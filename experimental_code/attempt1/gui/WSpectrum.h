#ifndef	WSPECTRUM_H
#define	WSPECTRUM_H

#include <QtWidgets>
#include "Zoomback.h"

class WSpectrum : public QWidget,public Zoomback
{
	Q_OBJECT

public:
	WSpectrum(QWidget *parent = nullptr);
	void setFFTsize(int size);
	void plotSpectrum(double* spectrum,int n);
	void setZoom(int left,int right,double upper,double lower);
	void setZoom(int left,int right);
	void zoomFit();
	void getZoom(int *left,int *right);
	void setZoomback(Zoomback* zoomback);

	
protected:
	void paintEvent(QPaintEvent *event) override;
	void resizeEvent(QResizeEvent *event) override;
	void mousePressEvent(QMouseEvent *event) override;
	void mouseReleaseEvent(QMouseEvent *event) override;
	void mouseMoveEvent(QMouseEvent *event) override;
	void wheelEvent(QWheelEvent *event) override;

private:
	int mWidth;
	int mHeight;
	int mFftSize;
	double mSpectrum[65536];
	double mMin,mMax;

	double mUpper,mLower;
	int mLeft,mRight;
	int mLastMoveEventX=-1;
	int mLastMoveEventY=-1;
	Zoomback* mZoomback=nullptr;
};

#endif
