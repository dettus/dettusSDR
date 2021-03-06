#include "WSpectrum.h"

WSpectrum::WSpectrum(QWidget* parent) : QWidget(parent)
{
	int i;

	mFftSize=1024;
	mMin=mMax=0;
	for (i=0;i<mFftSize;i++)
	{
		mSpectrum[i]=0;	
	}
	mUpper=65536*5;
	mLower=0;
	mLeft=0;
	mRight=mFftSize;
}
void WSpectrum::resizeEvent(QResizeEvent *event)
{
	mWidth=this->width();
	mHeight=this->height();
	repaint();
}
void WSpectrum::paintEvent(QPaintEvent *event)
{
	QPainter painter1(this);
	int i;
	int x;
	int y;
	double dx;
	double dy;
	int upper,lower,right,left;

	right=mRight;
	if (right>mFftSize) right=mFftSize;
	left=mLeft;
	if (left>(right-32)) left=right-32;
	if (left<0) left=0;
	if (lower<0) lower=0;
	
	

	x=0;
	y=mHeight;
	dx=(double)mWidth/(double)(right-left);
//	dy=(mMax-mMin)/(double)mHeight;
	dy=(double)(mUpper-mLower)/(double)mHeight;

	painter1.fillRect(0,0,mWidth,mHeight,QColor(32,32,32,255));
	painter1.setPen(QColor(255,255,255,255));

	for (i=left;i<right;i++)
	{
		int nx;
		int ny;

		nx=(int)((double)(i-left)*dx);
		ny=mHeight-(int)((mSpectrum[i]-(double)mLower)/dy);
		painter1.drawLine(x,y,nx,ny);
		x=nx;
		y=ny;
	}
}


void WSpectrum::mousePressEvent(QMouseEvent *event)
{
	if ((event->buttons() & Qt::LeftButton)	)
	{
		mLastMoveEvent=event->pos().x();
	}
}
void WSpectrum::mouseReleaseEvent(QMouseEvent *event)
{
	mLastMoveEvent=-1;
}

void WSpectrum::mouseMoveEvent(QMouseEvent *event)
{
	int x;
	double dx;
	int left,right;

	dx=((double)mRight-(double)mLeft)/(double)mWidth;
	left=mLeft;
	right=mRight;
	if ((event->buttons() & Qt::LeftButton)	)
	{
		x=event->pos().x();
		if (mLastMoveEvent!=-1)
		{
			left+=(mLastMoveEvent-x)*dx;
			right+=(mLastMoveEvent-x)*dx;
			repaint();
		}
		if (left>0&&left<mFftSize && right>0&&right<mFftSize)
		{
			mLeft=left;
			mRight=right;
		}
		mLastMoveEvent=x;	
	}
}

void WSpectrum::setFFTsize(int size)
{
	mFftSize=size;
	repaint();
}

void WSpectrum::plotSpectrum(double* spectrum, int n)
{
	int i;
	
	mMin=mMax=spectrum[0];
	for (i=0;i<n;i++)
	{
		mSpectrum[i]=spectrum[i];
		if (mSpectrum[i]<mMin) mMin=mSpectrum[i];
		if (mSpectrum[i]>mMax) mMax=mSpectrum[i];
	}
	repaint();
}
void WSpectrum::setZoom(int left,int right,double upper,double lower)
{
	mUpper=upper;
	mLower=lower;
	mRight=right;
	mLeft=left;
	repaint();
}
void WSpectrum::zoomFit()
{
	setZoom(0,mFftSize,mMax,0);
}

void WSpectrum::wheelEvent(QWheelEvent *event)
{
	QPoint curPoint = event->pos();
	double x;
	double d;
	double fact;

	
	x=(double)curPoint.x()/(double)mWidth;
	d=mRight-mLeft;

	fact=(mRight-mLeft)/10;
	if (event->delta()>0) // mousewheel up
	{
		mLeft+=(int)(fact*x);
		mRight-=(int)(fact*(1.0-x));
	}
	else if (event->delta()<0) // mousewheel down
	{
		mLeft-=(int)fact;
		mRight+=(int)fact;
	}
	if (mLeft<0) mLeft=0;
	if (mRight>mFftSize || mRight<=mLeft) mRight=mFftSize;
	repaint();
}
