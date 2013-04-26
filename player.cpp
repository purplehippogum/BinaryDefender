#include "player.h"

Player::Player(QPixmap *pm, double nx, double ny, double w, double h, int hp)
	: AbstractObject(pm, nx, ny, w, h, hp)
{
}
void Player::setDir(int d)
{
	dir = d;
}

int Player::getDir()
{
	return dir;
}
