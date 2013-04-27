#ifndef BOMB_H
#define BOMB_H

#include "basic_bullet.h"

class Bomb : public BasicBullet
{
	public:
		Bomb(QPixmap *pm, double nx, double ny, double w, double h, int vx, int vy, int hp, int d);
	private:
	
};

#endif
