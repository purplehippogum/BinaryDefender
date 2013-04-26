#include "enemy.h"

Enemy::Enemy(QPixmap *pm, double nx, double ny, double w, double h, int hp, int p) :
	AbstractObject(pm, nx, ny, w, h, hp)
{
	hunt = false;
	points = p;
}

void Enemy::move(int vx, int vy)// player's coordinates will be passed in
{
	if(x > vx)// && abs(vy - y) < 5)
		moveLeft(1);

	else if(x < vx)// && abs(vy - y) < 5)
		moveRight(1);
/*
*/
	else if(y > vy)// && abs(vx - x) < 5 )
		moveUp(1);
		
	else if(y < vy)// && abs(vx - x) < 5)
		moveDown(1);
}

void Enemy::setDamage(int d)
{
	damage = d;
}

int Enemy::getDamage()
{
	return damage;
} 

bool Enemy::getHunt()
{
	return hunt;
}

void Enemy::setHunt(bool h)
{
	hunt = h;
}

int Enemy::getPoints()
{
	return points;
}

void Enemy::setPoints(int p)
{
	points = p;
}

