#include "digit.h"
#include "score.h"
#include "player.h"

Digit::Digit(double nx, double ny, double w, double h, int vx, int vy, Player *p, Score *s) :
	GameObject(nx, ny, w, h, vx, vy)
{
	player = p;
	score = s;
}

void Digit::mousePressEvent(QGraphicsSceneMouseEvent *clicked)
{
	if(clicked->button() == Qt::LeftButton && bin == true){
		player->incPierce();
		score->removeDigit(index);
	}
}

void Digit::setIndex(int i)
{
	index = i;
}

int Digit::getIndex()
{
	return index;
}

void Digit::setBin(bool b)
{
	bin = b;
}

