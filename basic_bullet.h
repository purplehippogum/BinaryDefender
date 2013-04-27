#ifndef BASIC_BULLET_H
#define BASIC_BULLET_H

#include "abstract_object.h"

class BasicBullet : public AbstractObject
{
	public:
		BasicBullet(QPixmap *pm, double nx, double ny, double w, double h, int vx, int vy, int hp, int d);
		~BasicBullet();
		void move(double vx, double vy);// double vx, double vy
		int getDamage();
		/** Used to change the image to @param img */
		void setImage();
		/** @return the type of projectile */
		int getType();
		/** Set the type of projectile */
		void setType(int t);
		
	private:
		double initX;
		double initY;
		int finX;
		int finY;
		int damage;
		QPixmap *basic;
		QPixmap *bomb;
		QPixmap *arrow;
		int ammoType;
};

#endif
