#include "basic_bullet.h"
#include <iostream>
#include <cmath>

BasicBullet::BasicBullet(QPixmap *pm, double nx, double ny, double w, double h, int vx, int vy, int hp, int d)
	: AbstractObject(pm, nx, ny, w, h, hp)
{
	initX = nx;
	initY = ny;
	finX = vx;
	finY = vy;
	damage = d;
	basic = new QPixmap("basic_bullet.png", "png", Qt::AutoColor); 
	bomb = new QPixmap("bomb.png", "png", Qt::AutoColor);// ("player.png", "png", Qt::AutoColor)
	arrow = new QPixmap("arrow.png", "png", Qt::AutoColor);
}

BasicBullet::~BasicBullet()
{

}

int BasicBullet::getDamage()
{
	return damage;
}

void BasicBullet::move(double vx, double vy)// double vx, double vy
{
//	std::cout << "\nbullet x " << x << std::endl;
//	std::cout << "fin x " << finX << std::endl;

	if(vx > 0)
		moveRight(1);

	else if(vx < 0)
		moveLeft(1);
/*
*/
	if(vy < 0)
		moveUp(1);

	else if(vy > 0)
		moveDown(1);
}

void BasicBullet::setImage()
{
	if(ammoType == 0)
		setPixmap(*basic);
	if(ammoType == 1)
		setPixmap(*arrow);
	else if(ammoType == 2)
		setPixmap(*bomb);
}

int BasicBullet::getType()
{
	return ammoType;
}

void BasicBullet::setType(int t)
{
	ammoType = t;
}
