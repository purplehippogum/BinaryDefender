#include "abstract_object.h"
#include <cmath>

#define PI atan(1)*4

AbstractObject::AbstractObject(QPixmap *pm, double nx, double ny, double w, double h, int hp)
{
	x = nx;
	y = ny;
	width = w;
	height = h;
//	velX = vx;
//	velY = vy;
	health = hp;
	setPos(x, y);
	pixMap = new QPixmap;//(pm);// QPixmap
	pixMap = pm;
	setPixmap(*pm);
	this->setTransformOriginPoint(x + width/2.0, y + height/2.0);
	this->update(x, y, width, height);
}

int AbstractObject::getVelX()
{
	return velX;
}

int AbstractObject::getVelY()
{
	return velY;
}

void AbstractObject::setVelX(int vx)
{
	velX = vx;
}

void AbstractObject::setVelY(int vy)
{
	velY = vy;
}

void AbstractObject::setRot(int r)
{
	rot = r;
	setRotation(r);
}

int AbstractObject::getRot()
{
	return rot;
}

void AbstractObject::setHealth(int h)
{
	health = h;
}

int AbstractObject::getHealth()
{
	return health;
}

void AbstractObject::setDir(int d)
{
	dir = d;
}

int AbstractObject::getDir()
{
	return dir;
}

void AbstractObject::face(int sx, int sy)
{
	double dx = abs(x+width/2 - sx);
	double dy = abs(y+height/2 - sy);
//	dy += PI;
	double num = atan2(dy, dx);//*(180/PI);
//	num *= -1;
	rotate.rotate(num, Qt::ZAxis);
	pixMap->transformed(rotate, Qt::SmoothTransformation);
//	setRotation(num);
	rot = num;
}

void AbstractObject::move(int windowMaxX, int windowMaxY)
{
	x += velX;
	y += velY;

	if(x < 0){
		velX = 0;
		x = 0;
	}
	if (y < 0){
		velY = 0;
		y  = 0;
	}
	if(x+width > windowMaxX){
		velX = 0;
		x = windowMaxX;
	}
	if(y+height > windowMaxY){
		velY = 0;
		y = windowMaxY;
	}
}

void AbstractObject::moveUp(double s)
{
	this->moveBy(0, -1*s);
	--y;
}

void AbstractObject::moveDown(double s)
{
	this->moveBy(0, 1*s);
	++y;
}

void AbstractObject::moveLeft(double s)
{
	this->moveBy(-1*s, 0);
	--x;
}

void AbstractObject::moveRight(double s)
{
	this->moveBy(1*s, 0);
	++x;
}

int AbstractObject::getX()
{
	return x;
}

int AbstractObject::getY()
{
	return y;
}

int AbstractObject::getWidth()
{
	return width;
}

int AbstractObject::getHeight()
{
	return height;
}

void AbstractObject::setX(int nx)
{
	x = nx;
}

void AbstractObject::setY(int ny)
{
	y = ny;
}
