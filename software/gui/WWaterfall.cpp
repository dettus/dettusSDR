#include "WWaterfall.h"

WWaterfall::WWaterfall(QWidget* parent) : QWidget(parent)
{
	int i;

	mFftSize=1024;
	mMin=mMax=0;
	mUpper=5*65536;
	mLower=0;
	mLeft=0;
	mRight=mFftSize;
	if (mWaterfallImage!=nullptr) delete(mWaterfallImage);
	mWaterfallImage=nullptr;

}
void WWaterfall::resizeEvent(QResizeEvent *event)
{
//	if (mWaterfallImage!=nullptr) delete(mWaterfallImage);
//	mWaterfallImage=new QImage(mWidth,mHeight,QImage::Format_ARGB32);
//	painter.fillRect(0,0,mWidth,mHeight,QColor(32,32,32,255));
	if (mWidth!=this->width() || (mHeight!=this->height()))
	{
		mWidth=this->width();
		mHeight=this->height();
		if (mWaterfallImage!=nullptr) delete(mWaterfallImage);
		mWaterfallImage=new QImage(mWidth,mHeight,QImage::Format_ARGB32); 
	}
}
void WWaterfall::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	if (mWidth!=this->width() || (mHeight!=this->height()))
	{
		mWidth=this->width();
		mHeight=this->height();
		if (mWaterfallImage!=nullptr) delete(mWaterfallImage);
		mWaterfallImage=new QImage(mWidth,mHeight,QImage::Format_ARGB32); 
	}
	QRectF full(0,0, mWidth,mHeight);
	painter.drawImage(full,*mWaterfallImage,full);

}


void WWaterfall::mousePressEvent(QMouseEvent *event)
{
	if ((event->buttons() & Qt::RightButton)	)
	{
		zoomFit();
	}

}

void WWaterfall::setFFTsize(int size)
{
	mFftSize=size;
	mLeft=0;
	mRight=mFftSize;
	update();
}

void WWaterfall::plotWaterfall(double* spectrum, int n)
{
	int right,left;

	right=mRight;
	if (right>mFftSize) right=mFftSize;
	left=mLeft;
	if (left>(right-32)) left=right-32;
	if (left<0) left=0;

	if (mWaterfallImage!=nullptr)
	{
		QImage tmpImage(mWidth,mHeight,QImage::Format_ARGB32);
		QPainter tmpPainter(&tmpImage);
		QPainter waterfallPainter(mWaterfallImage);
		int i;
		int x;
		double dx;
		double dy;
		double maxy;


		mMin=mMax=sqrt(spectrum[0]);
		for (i=0;i<n;i++)
		{
			double s;
			s=sqrt(spectrum[i]);
			if (s<mMin) mMin=s;
			if (s>mMax) mMax=s;
		}
		// with each new spectrum, the waterfall moves UP. 
		QRectF target(0,0, mWidth,mHeight-1);
		QRectF source(0,0, mWidth,mHeight);
		tmpPainter.drawImage(target, *mWaterfallImage, source);	// move the image 1 pixel up
		waterfallPainter.drawImage(source, tmpImage, source);
		// the last line is now free to paint the new spectrum

		x=0;
		dx=(double)mWidth/(double)(mRight-mLeft);
		dy=(mMax-mMin);
		maxy=0;
		for (i=mLeft;i<mRight;i++)
		{
			double nx;
			double y;

			y=sqrt(spectrum[i])-mMin;

			nx=dx*i;
			if (y>maxy) maxy=y;
			if ((int)nx!=x)
			{
				double r,g,b;
				r=(maxy*255.0)/dy;
				g=64-(maxy*64.0)/dy;
				b=255-(maxy*255.0)/dy;
				waterfallPainter.setPen(QColor((int)r,(int)g,(int)b,255));
				waterfallPainter.drawLine(x,mHeight-1, (int)nx,mHeight-1);
				x=(int)nx;
				maxy=0;
			}

		}
		update();
	} else {
	}
}
void WWaterfall::setZoom(int left,int right,double upper,double lower)
{
	mUpper=upper;
	mLower=lower;
	mRight=right;
	mLeft=left;
	update();
}
void WWaterfall::zoomFit()
{
	setZoom(0,mFftSize,mMax,0);
}

void WWaterfall::wheelEvent(QWheelEvent *event)
{
}
