#include "play_area.h"
#include "player.h"
#include "gameplay.h"

Player::Player(QPixmap *pm, double nx, double ny, double w, double h, int hp)
	: AbstractObject(pm, nx, ny, w, h, hp)
{
	ammoType = 0;
	dir = -1;
}
void Player::setDir(int d)
{
	dir = d;
}

int Player::getDir()
{
	return dir;
}

void Player::incPierce()
{
	pierce++;
}
void Player::incBombs(){
	bombs++;
}
void Player::decPierce(){
	pierce--;
}
void Player::decBomb(){
	bombs--;
}
void Player::cycleAmmo(){
	ammoType++;
	if(ammoType == 2){
		ammoType = 0;
	}
}

int Player::getAmmo(){
	return ammoType;
}

int Player::getArrows(){
	return pierce;
}

int Player::getBombs(){
	return bombs;
}
