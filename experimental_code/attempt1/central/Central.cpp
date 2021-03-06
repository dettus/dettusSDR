#include "Central.h"
#include "TDummy.h"
#include "TRtlTcp.h"
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
	mWaterfall->setFFTsize(mFftSize);
	mTuner=tuner;
	mTuner->setSink(this);

	mWSpectrum->setZoomback(this);
	mWaterfall->setZoomback(this);


	if (mainwin!=nullptr)
	{
		mainwin->setWSpectrum(mWSpectrum);
		mainwin->setWWaterfall(mWaterfall);
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
#if 0
	eTunerId tunerId=TUNER_UNDEF;
	TunerDialog *tunerDialog=mTunerDialog;
	//TunerDialog *tunerDialog=new TunerDialog();

	// INITIALIZE
	mMainwin->hide();
	while (!mStopped && mTuner==nullptr && tunerId==TUNER_UNDEF)
	{
		QThread::msleep(1000);
		tunerId=tunerDialog->getTunerValue();
		printf("hello. tunerid:%d\n",(int)tunerId);
		switch (tunerId)
		{
			case TUNER_QUIT:
				mStopped=true;
				break;
			case TUNER_DUMMY:
				mTuner=(Tuners*)new TDummy();
				mTuner->setSink(this);
				//((TDummy*)mTuner)->start();
				((TDummy*)mTuner)->moveToThread(mTunerThread);
				break;
			case TUNER_RTLTCP:
				mTuner=(Tuners*)new TRtlTcp();
				mTuner->setSink(this);
				//((TRtlTcp*)mTuner)->start();
				((TRtlTcp*)mTuner)->moveToThread(mTunerThread);
//https://mayaposch.wordpress.com/2011/11/01/how-to-really-truly-use-qthreads-the-full-explanation/
				break;
			default:
				break;
		}
	}
//	tunerDialog->hide();
#endif	
	mMainwin->setWTuner(mTuner->getWidget());	
	mMainwin->showMaximized();	

	// main window is shown. run the main loop
	while (!mStopped)
	{
		double spectrum[mFftSize];
		int left,right;
		QThread::msleep(1);
		// lock
		mMutex.lock();
		if (iqBuf.fillnext!=iqBuf.fillcur)
		{
			printf(">>> new samples:%d\n",iqBuf.fillnext-iqBuf.fillcur);
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
		while ((iqBuf.fillcur-iqBuf.used)>=mFftSize)
		{
			
			for (i=0;i<mFftSize;i++) spectrum[i]=0.0f;
			for (i=0;i<16;i++)
			{
				if ((iqBuf.fillcur-iqBuf.used)>=mFftSize)
				{
					mFft->process(&iqBuf.samples[iqBuf.used&(iqBuf.size-1)]);
					mFft->addSpectrum(spectrum);
					iqBuf.used+=mFftSize;
				}
			}
			mWSpectrum->plotSpectrum(spectrum,mFftSize);
			mWaterfall->plotWaterfall(spectrum,mFftSize);
			
//			QThread::usleep(1);
		}
//		mWSpectrum->getZoom(&left,&right);
//		mWaterfall->setZoom(left,right);
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
void Central::setZoom(int left,int right)
{
	mWSpectrum->setZoom(left,right);
	mWaterfall->setZoom(left,right);
}
