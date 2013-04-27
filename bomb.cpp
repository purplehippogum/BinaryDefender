#include "bomb.h"

Bomb::Bomb(QPixmap *pm, double nx, double ny, double w, double h, int vx, int vy, int hp, int d) : BasicBullet(pm, nx, ny, w, h, vx,vy, hp, d)
{
	strikeCount = 0;
	bomb = true;
}
