#ifndef ENEMY_H
#define ENEMY_H

#include "abstract_object.h"

class Enemy : public AbstractObject
{
	public:
		Enemy(QPixmap *pm, double nx, double ny, double w, double h, int hp);
		void move(int vx, int vy);
		void setDamage(int d);
		int getDamage();
	private:
		int damage;
		int dir;
};

#endif
