#include "Central.h"
#define	BUFSIZE	(1<<23)

Central::Central(MainWindow* mainwin,Tuners* tuner)
{
	iqBuf.samples=new tSComplex[BUFSIZE];
	iqBuf.size=BUFSIZE;
	iqBuf.fillcur=0;
	iqBuf.fillnext=0;
	iqBuf.used=0;
	
	mStopped=false;
	
	
	mWSpectrum=new WSpectrum(mainwin);
	mWaterfall=new WWaterfall(mainwin);
	mFft=new SimpleFft(mFftSize);
	mWSpectrum->setFFTsize(mFftSize);
	mTuner=tuner;

	if (mainwin!=nullptr)
	{
		mainwin->setWSpectrum(mWSpectrum);
		mainwin->setWWaterfall(mWaterfall);
		mainwin->setWTuner(mTuner->getWidget());	
	}
	mMainwin=mainwin;
	mMutex.unlock();
	mMutex2.unlock();
}
void Central::onNewSamples(tSComplex* iqSamples,int n)
{
	int i;
	int j;
	int mask;
	// lock here
	mMutex.lock();
	
	j=iqBuf.fillnext;
	mask=iqBuf.size-1;
	for (i=0;i<n;i++)
	{
		iqBuf.samples[j&mask]=iqSamples[i];
		j++;
	}
	iqBuf.fillnext=j;
	mMutex.unlock();

	// unlock here
}

void Central::run()
{
	int i;
	while (!mStopped)
	{
		double spectrum[mFftSize];
		QThread::msleep(1);
		// lock
		mMutex.lock();
		if (iqBuf.fillnext!=iqBuf.fillcur)
		{
			iqBuf.fillcur=iqBuf.fillnext;
		}
		if (iqBuf.fillcur>=iqBuf.size && iqBuf.fillnext>=iqBuf.size && iqBuf.used>=iqBuf.size)
		{
			iqBuf.fillcur-=iqBuf.size;
			iqBuf.fillnext-=iqBuf.size;
			iqBuf.used-=iqBuf.size;
		}
		mMutex.unlock();

		mMutex2.lock();
		for (i=0;i<mFftSize;i++) spectrum[i]=0.0f;
		if (iqBuf.fillcur-iqBuf.used>=mFftSize)
		{
			for (i=0;i<10;i++)
			{
				if (iqBuf.fillcur-iqBuf.used>=mFftSize)
				{
					mFft->process(&iqBuf.samples[iqBuf.used&(iqBuf.size-1)]);
					mFft->addSpectrum(spectrum);
					iqBuf.used+=mFftSize;
				}
				mWSpectrum->plotSpectrum(spectrum,mFftSize);
				mWaterfall->plotWaterfall(spectrum,mFftSize);
				QThread::msleep(1);
			}
		}
		iqBuf.used=iqBuf.fillcur;
		mMutex2.unlock();
	}
}
void Central::stop()
{
	mStopped=true;
}

void Central::setFftSize(int fftsize)
{
	mMutex2.lock();	
	if (mFftSize!=fftsize && mFft!=nullptr)
	{
		delete(mFft);
	}
	if (mFft==nullptr)
	{
		mFft=new SimpleFft(fftsize);
	}
	mFftSize=fftsize;
	if (mWSpectrum!=nullptr) mWSpectrum->setFFTsize(fftsize);
	if (mWaterfall!=nullptr) mWaterfall->setFFTsize(fftsize);	
	mMutex2.unlock();	
}
void Central::setTuner(Tuners* tuner)
{
	mTuner=tuner;
	mMainwin->setWTuner(mTuner->getWidget());	
}
