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
		bool getHunt();
		void setHunt(bool h);
	private:
		int damage;
		/** If true, the enemy will go after the player */
		bool hunt;
};

#endif
