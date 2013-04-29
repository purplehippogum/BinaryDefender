#ifndef ENEMY_H
#define ENEMY_H

#include "abstract_object.h"

/*
* Basic enemy that spawns randomly and seeks out the player
*/

class Enemy : public AbstractObject
{
	public:
		Enemy(QPixmap *pm, double nx, double ny, double w, double h, int hp, int p);
		void move(int vx, int vy);
		void setDamage(int d);
		int getDamage();
		bool getHunt();
		void setHunt(bool h);
		void setPoints(int p);
		int getPoints();
		
	private:
		int damage;
		/** If true, the enemy will go after the player */
		bool hunt;
		int points;
};

#endif
