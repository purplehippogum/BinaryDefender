#ifndef ARROWCOUNT_H
#define ARROWCOUNT_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <vector>

/** 
* This class displays the arrow icon and counter in the MainWindow HUD
*/

class ArrowCount
{
	public:
		ArrowCount(QPixmap *pix, int nx, int ny, QGraphicsScene *s);
		/** Increases the arrow count */
		void inc();
		/** Decreases the arrow count */
		void dec();
		/** Sets the count */
		void setCount(int c);
		/** Set the pixmap so it looks selected */
		void setSelected();
		/** Revert the image to its normal state */
		void deSelect();
		
	private:
		/** Updates the arrow display */
		void update();
		QGraphicsScene *scene;
		/** Keeps track of how many arrows to display */
		int count;
		QPixmap *blank;
		QPixmap *pixMap;
		QGraphicsPixmapItem *pic;
		std::vector<QGraphicsPixmapItem*> pics;
		int x;
		int y;
};

#endif
