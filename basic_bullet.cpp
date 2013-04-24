#include "basic_bullet.h"

BasicBullet::BasicBullet(QPixmap *pm, double nx, double ny, double w, double h, int vx, int vy)
	: AbstractObject(pm, nx, ny, w, h, vx, vy)
{
	initX = nx;
	initY = ny;
	finX = vx;
	finY = vy;
}

void BasicBullet::move(double vx, double vy)// double vx, double vy
{
	
	if(x > finX)
		moveLeft(1.2);
	else if(x < finX)
		moveRight(1.2);
		
	if(y > finY)
		moveUp(1.2);
	else if(y < finY)
		moveDown(1.2);
}
