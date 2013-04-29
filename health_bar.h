#ifndef HEALTH_BAR_H
#define HEALTH_BAR_H

#include <QString>
#include "game_object.h"

/**
* Simple colored rectangle that updates its width with the player's health.
*/

class HealthBar : public GameObject
{
	public:
		HealthBar(double nx, double ny, double w, double h, int vx, int vy, int v);
		GameObject *outline;
		void setVal(int v);
		int getVal();
		
	private:
		int val;
    /** Stores num in QString form */
    QString txt;
    /** Used to actually display text on tile */
    QGraphicsSimpleTextItem *item;
};

#endif
