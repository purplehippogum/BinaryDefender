#include "game_object.h"

GameObject::GameObject(double nx, double ny, double w, double h, int vx, int vy) :
	QGraphicsRectItem(nx, ny, w, h)
{
	x = nx;
	y = ny;
	width = w;
	height = h;
	velX = vx;
	velY = vy;
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
}

int GameObject::getRot()
{
	return rot;
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
