#ifndef	CENTRALMAIN_H
#define	CENTRALMAIN_H
#include <stdio.h>
#include <QThread>
#include <QMutex>
#include "TunerMain.h"
#include "DemodMain.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMutex>
#include "WVolume.h"
#include "WSpectrum2.h"
#include "Downsampler.h"
#include "SimpleShifter.h"
class CentralMain: public QThread
{
	Q_OBJECT

	public:
		CentralMain(TunerMain *tunerMain,DemodMain *demodMain,AudioMain *audioMain);
		void stop();
		
	protected:
		void run();
	
	private:
		bool mStopped=false;
		QMutex mMutex;

		TunerMain *mTunerMain;
		DemodMain *mDemodMain;
		AudioMain *mAudioMain;
		QVBoxLayout *mV1Layout;
		QHBoxLayout *mH1Layout;
		QHBoxLayout *mH2Layout;
		QHBoxLayout *mH3Layout;
		QVBoxLayout *mV2Layout;
		QVBoxLayout *mV3Layout;
		QWidget *mainWin=nullptr;
		QPushButton *mRecordButton=nullptr;
		QWidget *mDemodWidget=nullptr;
		QMutex	mLock;
		FILE *mFptr=nullptr;
		bool mRecord=false;

		QPushButton *bFFT[8]; // 8 buttons for 256, 512... 32768

		WSpectrum *mWSpectrum;
		WVolume *mWVolume;


// testing

	public slots:
		void handleRecord();
		void handleFFTclicked();

};
#endif
