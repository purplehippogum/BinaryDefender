#ifndef BASIC_BULLET_H
#define BASIC_BULLET_H

#include "abstract_object.h"

class BasicBullet : public AbstractObject
{
	public:
		BasicBullet(QPixmap *pm, double nx, double ny, double w, double h, int vx, int vy, int hp);
		void move(double vx, double vy);// double vx, double vy
	private:
		double initX;
		double initY;
		int finX;
		int finY;
};

#endif
