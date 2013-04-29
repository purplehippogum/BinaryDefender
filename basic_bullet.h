#ifndef BASIC_BULLET_H
#define BASIC_BULLET_H

#include "abstract_object.h"

/** 
* The player always may shoot this bullet. Only two may appear on the screen at a time.
*/

class BasicBullet : public AbstractObject
{
	public:
		BasicBullet(QPixmap *pm, double nx, double ny, double w, double h, int vx, int vy, int hp, int d);
		~BasicBullet();
		void move(double vx, double vy);// double vx, double vy
		int getDamage();
		void setInEnemy(bool b);
		bool getInEnemy();
		/** Subtracts 1 from strikeCount */
		void decStrike();
		int getStrike();
		void setBomb(bool b);
		bool getBomb();
		
	protected:
		/** How many enemies the bullet has gone through */
		int strikeCount;
		/** If true, bullet is intersecting with an enemy */
		bool inEnemy;
		double initX;
		double initY;
		int finX;
		int finY;
		int damage;
		bool bomb;
};

#endif
