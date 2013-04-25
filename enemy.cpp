#include "enemy.h"

Enemy::Enemy(QPixmap *pm, double nx, double ny, double w, double h, int vx, int vy, int hp) :
	AbstractObject(pm, nx, ny, w, h, vx, vy, hp)
{

}

void Enemy::move(int vx, int vy)// player's coordinates will be passed in
{
	if(x > vx)
		moveLeft(1);

	if(x < vx)
		moveRight(1);
/*
*/
	if(y > vy)
		moveUp(1);
		
	if(y < vy)
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
