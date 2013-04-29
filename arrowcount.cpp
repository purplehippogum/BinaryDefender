#include "arrowcount.h"

ArrowCount::ArrowCount(QPixmap *pix, int nx, int ny, QGraphicsScene *s)
{
	scene = s;
	pixMap = new QPixmap;
	pixMap = pix;
	blank = new QPixmap("arrow_select.png", "png", Qt::AutoColor);
	x = nx;
	y = ny;
	count = 1;
	pic = new QGraphicsPixmapItem;
	pic->setPixmap(*pixMap);
	pic->setPos(x, y);
	scene->addItem(pic);
}

void ArrowCount::setSelected()
{
	pic->setPixmap(*blank);
}

void ArrowCount::deSelect()
{
	pic->setPixmap(*pixMap);
}

void ArrowCount::inc()
{
	count++;
	update();
}

void ArrowCount::dec()
{
	if(count > 0){
		count--;
		update();
	}
}

void ArrowCount::setCount(int c)
{
	count = c;
	update();
}

void ArrowCount::update()
{
/*	for(int i = pics.size() - 1; i > 0; i--){
		pics[i]->setPixmap(*blank);
		scene->removeItem(pics[i]);
		delete pics[i];
		pics.pop_back();
	}
	
	for(int i = 0; i < 1; i++){
		pic = new QGraphicsPixmapItem;
		pic->setPixmap(*pixMap);
		pic->setPos(x, y);
		scene->addItem(pic);
		pics.push_back(pic);
	}*/
}
