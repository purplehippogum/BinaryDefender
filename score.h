#ifndef SCORE_H
#define SCORE_H

#include <QString>
#include <QGraphicsSimpleTextItem>
#include <vector>
#include <QGraphicsRectItem>

class MainWindow;
class Digit;
class Player;

class Score : public QGraphicsRectItem
{
	public:
		Score(int nx, int ny, MainWindow *main, QGraphicsScene *sc, Player *p);
		int getX();
		int getY();
		void setPoints(int p);
		void addPoints(int p);
		int getPoints();
		void updateScore();
		void removeDigit(int d);
		
	private:
		void binary();
		void draw();
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
		/** Convert back to decimal */
		int toDecimal(int num);
		/** Abstractly stores position for later reference */
		int x;
		int y;
		int width;
		int height;
		QPixmap *oneIMG;
		QPixmap *zeroIMG;
		QGraphicsPixmapItem *zero;
		QGraphicsPixmapItem *one;
		Digit *digit;
		std::vector<Digit*> digits;
		Player *player;
};

#endif
