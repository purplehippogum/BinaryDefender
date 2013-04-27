#ifndef SCORE_H
#define SCORE_H

#include <QString>
#include <QGraphicsSimpleTextItem>
#include <vector>
#include <QGraphicsRectItem>
#include "abstract_object.h"

class MainWindow;

class Score : public QGraphicsRectItem
{
	public:
		Score(int nx, int ny, MainWindow *main, QGraphicsScene *sc);
		int getX();
		int getY();
		void setPoints(int p);
		void addPoints(int p);
		int getPoints();
		void updateScore();
		void binary();
		void draw();
		
		
	private:
		MainWindow *window;
		QGraphicsScene *scene;
		/** Shows the word score */
		QGraphicsSimpleTextItem *scoreDisplay;
		/** Stores the value of score */
		int points;
		QString s;
		/** Displays the actual point value */
		QGraphicsSimpleTextItem *pointDisplay;
		/**Converts score to binary **/
		QString toBinary(int num, bool rev);
		/** Abstractly stores position for later reference */
		int x;
		int y;
		int width;
		int height;
		QPixmap *oneIMG;
		QPixmap *zeroIMG;
		QGraphicsPixmapItem *zero;
		QGraphicsPixmapItem *one;
		AbstractObject *digit;
		std::vector<AbstractObject*> digits;
};

#endif
