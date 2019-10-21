#include "WWaterfall.h"

#define	WATERFALLWIDTH	32768
#define	WATERFALLHEIGHT	256
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
	mWaterfallImage=new QImage(WATERFALLWIDTH,WATERFALLHEIGHT,QImage::Format_ARGB32); 
	QPainter waterfallPainter(mWaterfallImage);
	waterfallPainter.fillRect(0,0,WATERFALLWIDTH,WATERFALLHEIGHT,QColor(0,0,255,255));

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
	}

}
void WWaterfall::paintEvent(QPaintEvent *event)
{
	double delta;
	QPainter painter(this);
	if (mWidth!=this->width() || (mHeight!=this->height()))
	{
		mWidth=this->width();
		mHeight=this->height();
	}
	QSize	size(mWidth,mHeight);
	QRectF full(0,0, mWidth,mHeight);
	delta=((double)(mRight-mLeft)*(double)WATERFALLWIDTH)/(double)mFftSize;
	QImage tmpImage(delta,WATERFALLHEIGHT,QImage::Format_ARGB32);
	QPainter tmpPainter(&tmpImage);
	QRectF source(mLeft,0,delta,WATERFALLHEIGHT);
	QRectF target(0,0,delta,WATERFALLHEIGHT);

	tmpPainter.drawImage(target,*mWaterfallImage,source);
	

	
	

		
//	painter.drawImage(full,mWaterfallImage->scaled(size),full);
	painter.drawImage(full,tmpImage.scaled(size),full);

}


void WWaterfall::mousePressEvent(QMouseEvent *event)
{
	if ((event->buttons() & Qt::LeftButton)	)
	{
		mLastMoveEventX=event->pos().x();
	}
	if ((event->buttons() & Qt::RightButton)	)
	{
		zoomFit();
		mZoomback->setZoom(mLeft,mRight);
	}
}

void WWaterfall::mouseMoveEvent(QMouseEvent *event)
{
	int x,y;
	double dx;
	int left,right;

	dx=(((double)mRight-(double)mLeft)*(double)WATERFALLWIDTH)/(double)(mWidth*mFftSize);
	left=mLeft;
	right=mRight;
	if ((event->buttons() & Qt::LeftButton)	)
	{
		x=event->pos().x();
		if (mLastMoveEventX!=-1)
		{
			left+=(mLastMoveEventX-x)*dx;
			right+=(mLastMoveEventX-x)*dx;
		}
		if (left>0&&left<mFftSize && right>0&&right<mFftSize)
		{
			if (mZoomback!=nullptr)
			{
				mZoomback->setZoom(left,right);
			} else {
				mLeft=left;
				mRight=right;	
			}
		}
		mLastMoveEventX=x;	
		update();
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
	if (mWaterfallImage!=nullptr)
	{
		QImage tmpImage(WATERFALLWIDTH,WATERFALLHEIGHT,QImage::Format_ARGB32);
		QPainter tmpPainter(&tmpImage);
		QPainter waterfallPainter(mWaterfallImage);
		int i;
		int x;
		double dx;
		double dy;
		double maxy;


		mMin=mMax=log((spectrum[0]));
		for (i=0;i<n;i++)
		{
			double s;
			s=log((spectrum[i]));
			if (s<mMin) mMin=s;
			if (s>mMax) mMax=s;
		}
		// with each new spectrum, the waterfall moves DOWN
		QRectF target(0,1, WATERFALLWIDTH,WATERFALLHEIGHT-1);
		QRectF source(0,0, WATERFALLWIDTH,WATERFALLHEIGHT-1);
		tmpPainter.drawImage(target, *mWaterfallImage, source);	// move the image 1 pixel up
		waterfallPainter.drawImage(source, tmpImage, source);
		// the upper line is now free to paint the new spectrum

		x=0;
		dx=(double)WATERFALLWIDTH/(double)(mFftSize);
		dy=(mMax-mMin);
		maxy=0;
		for (i=0;i<mFftSize;i++)
		{
			double nx;
			double y;

			y=log((spectrum[i]))-mMin;


			nx=dx*(i-0);
			if (y>maxy) maxy=y;
			if ((int)nx!=x)
			{
				double r,g,b;
				r=(maxy*255.0)/dy;
				g=64-(maxy*64.0)/dy;
				b=255-(maxy*255.0)/dy;

				r=(maxy* 32.0)/dy;
				g=(maxy*255.0)/dy;
				b=(maxy*192.0)/dy;

				r=(maxy*255.0)/dy;
				g=(maxy*255.0)/dy;
				b=63+(maxy*192.0)/dy;
				waterfallPainter.setPen(QColor((int)r,(int)g,(int)b,255));
				waterfallPainter.drawLine(x,0, (int)nx,0);
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
void WWaterfall::setZoom(int left,int right)
{
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
	QPoint curPoint = event->pos();
	double x;
	double d;
	double fact;
	int right=mRight;
	int left=mLeft;

	
	x=(double)(curPoint.x()*WATERFALLWIDTH)/(double)(mFftSize*mWidth);
	d=right-left;

	fact=(right-left)/10;
	if (event->delta()>0) // mousewheel up
	{

		fact=(right-left)/10;
		left+=(int)(fact*x);
		right-=(int)(fact*(1.0-x));
	}
	else if (event->delta()<0) // mousewheel down
	{
		fact=(right-left)/10;
		left-=(int)fact;
		right+=(int)fact;
	}
	if (left<0) left=0;
	if (left>mFftSize-32) left=mFftSize-32;

	if (right>mFftSize || right<=left) right=mFftSize;
	if (mZoomback!=nullptr)
	{
		mZoomback->setZoom(left,right);
	} else {
		mLeft=left;
		mRight=right;	
	}
	update();
}
void WWaterfall::setZoomback(Zoomback* zoomback)
{
	mZoomback=zoomback;
}

