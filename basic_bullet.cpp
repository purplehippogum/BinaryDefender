#include "basic_bullet.h"
#include <iostream>
#include <cmath>

BasicBullet::BasicBullet(QPixmap *pm, double nx, double ny, double w, double h, int vx, int vy, int hp)
	: AbstractObject(pm, nx, ny, w, h, vx, vy, hp)
{
	initX = nx;
	initY = ny;
	finX = vx;
	finY = vy;
}

void BasicBullet::move(double vx, double vy)// double vx, double vy
{
//	std::cout << "\nbullet x " << x << std::endl;
//	std::cout << "fin x " << finX << std::endl;

	if(vx < 0)
		moveLeft(abs(vx));

	else if(vx > 0)
		moveRight(vx);
/*
*/
	if(vy < 0)
		moveUp(abs(vy));

	else if(vy > 0)
		moveDown(vy);
}
