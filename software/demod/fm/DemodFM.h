#ifndef	DEMODFM_H
#define	DEMODFM_H
#include <QtWidgets>
#include <QHBoxLayout>
#include "Demod.h"

class DemodFM: public Demod
{
	Q_OBJECT
	public:
		DemodFM(QWidget* parent=nullptr);
		void onNewSamples(tIQSamplesBlock *pSamples);
		int getBandwidth() {return 192000/4;};
		int getSampleRate() {return 192000;};
		int getFreqOffset() {return 0;};

	private:
		double mAngle=0;
		
		QHBoxLayout *mHLayout=nullptr;
		QLabel *mLabel=nullptr;
		
};

#endif