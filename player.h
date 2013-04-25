#ifndef player_H
#define player_H

#include "abstract_object.h"

class Player : public AbstractObject
{
	public:
	Player(QPixmap *pm, double nx, double ny, double w, double h, int hp);
};

#endif
