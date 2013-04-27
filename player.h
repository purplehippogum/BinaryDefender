#ifndef player_H
#define player_H

#include "abstract_object.h"

class PlayArea;

class Player : public AbstractObject
{
	public:
		Player(QPixmap *pm, double nx, double ny, double w, double h, int hp);
		void setDir(int d);
		int getDir();
		/** increments pierce value */
		void incPierce();
		/** Increments bomb value */
		void incBombs();
		/** Decrements pierce count */
		void decPierce();
		/** Decrements bomb count */
		void decBomb();
		/** Sets the ammo type: 0 is basic, 1 is piercing, 2 is bomb */
		void cycleAmmo();
		/** Retrieves ammo type */
		int getAmmo();
		/** Retrieves amount of each ammo type */
		int getArrows();
		int getBombs();
		
	private:
		int dir;
		int ammoType;
		/** Keeps track of how many piercing bullets are left */
		int pierce;
		/** Remaining bombs */
		int bombs;
};

#endif
