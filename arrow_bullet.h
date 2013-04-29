#ifndef ARROW_BULLET_H
#define ARROW_BULLET_H

#include "basic_bullet.h"

/** 
* This bullet pierces multiple enemies and is destroyed upon hitting the third enemy.
* It takes the form of an arrow.
*/

class ArrowBullet : public BasicBullet
{
	public:
		ArrowBullet(QPixmap *pm, double nx, double ny, double w, double h, int vx, int vy, int hp, int d);
	
	private:
};

#endif
