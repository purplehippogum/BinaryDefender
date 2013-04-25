#include "game_object.h"
#include <cmath>

#define PI atan(1)*4

GameObject::GameObject(double nx, double ny, double w, double h, int vx, int vy) :
	QGraphicsRectItem(nx, ny, w, h)
{
	x = nx;
	y = ny;
	width = w;
	height = h;
	velX = vx;
	velY = vy;
	setTransformOriginPoint (x + width/2.0, y + height/2.0);
	transRight = false;
	transLeft = false;
	transUp = false;
	transDown = false;
}

int GameObject::getVelX()
{
	return velX;
}

int GameObject::getVelY()
{
	return velY;
}

void GameObject::setVelX(int vx)
{
	velX = vx;
}

void GameObject::setVelY(int vy)
{
	velY = vy;
}

void GameObject::setRot(int r)
{
	rot = r;
	setRotation(r);
	draw();
}

int GameObject::getRot()
{
	return rot;
}

void GameObject::setWidth(int w)
{
	width = w;
	setRect(x, y, w, height);
	draw();
}

void GameObject::setRight(bool b){
	transRight = b;
}

bool GameObject::getRight(){
	return transRight;
}

void GameObject::setLeft(bool b){
	transLeft = b;
}

bool GameObject::getLeft(){
	return transLeft;
}

void GameObject::setUp(bool b){
	transUp = b;
}

bool GameObject::getUp(){
	return transUp;
}

void GameObject::setDown(bool b){
	transDown = b;
}

bool GameObject::getDown(){
	return transDown;
}

void GameObject::face(int sx, int sy)
{
	double dx = abs(x+width/2 - sx);
	double dy = abs(y+height/2 - sy);
//	dy += PI;
	double num = atan2(dy, dx)*(180/PI);
	num *= -1;
//	double angle = atan2(sx, sy);
//	if(num < 0)
//		num += 2*PI;
//	angle *= 180/PI;
	setRotation(num);
	rot = num;
	draw();
}

void GameObject::move(int windowMaxX, int windowMaxY)
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

// Redraw rectangle to new position
	draw();
}

void GameObject::moveUp()
{
	this->moveBy(0, -1);
	--y;
	draw();
}

void GameObject::moveDown()
{
	this->moveBy(0, 1);
	++y;
	draw();
}

void GameObject::moveLeft()
{
	this->moveBy(-1, 0);
	--x;
	draw();
}

void GameObject::moveRight()
{
	this->moveBy(1, 0);
	++x;
	draw();
}

void GameObject::draw()
{
	QPointF p(x, y);
	QRectF r(rect());
	r.moveTo(p);
	setRect(r);
}

int GameObject::getX()
{
	return x;
}

int GameObject::getY()
{
	return y;
}

int GameObject::getWidth()
{
	return width;
}

int GameObject::getHeight()
{
	return height;
}

void GameObject::setX(int nx)
{
	x = nx;
}

void GameObject::setY(int ny)
{
	y = ny;
}
