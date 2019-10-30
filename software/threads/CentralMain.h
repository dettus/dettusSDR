#ifndef	CENTRALMAIN_H
#define	CENTRALMAIN_H
#include <stdio.h>
#include <QThread>
#include <QMutex>
#include "TunerMain.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMutex>
#include "WSpectrum.h"
class CentralMain: public QThread
{
	Q_OBJECT

	public:
		CentralMain(TunerMain *tunerMain);
		void stop();
		
	protected:
		void run();
	
	private:
		bool mStopped=false;
		QMutex mMutex;

		TunerMain *mTunerMain;
		QHBoxLayout *mHLayout;
		QVBoxLayout *mVLayout;
		QWidget *mainWin=nullptr;
		QPushButton *mRecordButton=nullptr;
		QMutex	mLock;
		FILE *mFptr=nullptr;
		bool mRecord=false;

		WSpectrum *mWSpectrum;

	public slots:
		void handleRecord();

};
#endif
