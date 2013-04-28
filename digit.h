#ifndef DIGIT_H
#define DIGIT_H

#include <QGraphicsSceneMouseEvent>

#include "game_object.h"

class Score;
class Player;

class Digit : public GameObject
{
	public:
		Digit(double nx, double ny, double w, double h, int vx, int vy, Player *p, Score *s);
		void mousePressEvent(QGraphicsSceneMouseEvent *clicked);
		void setIndex(int i);
		int getIndex();
    void setBin(bool b);
    bool getBin();
	
	private:
		Player *player;
		Score *score;
		/** The position of the digit */
		int index;
		bool bin;
};

#endif
