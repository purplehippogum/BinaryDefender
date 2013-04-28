#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <QKeyEvent>
#include <QGraphicsView>
#include <QGraphicsScene>

class MainWindow;
class Player;

class Gameplay : public QGraphicsView
{
	public:
		Gameplay(QGraphicsScene *scene, MainWindow *main, Player *p);
		void keyPressEvent(QKeyEvent *k);
		void keyReleaseEvent(QKeyEvent *k);
	private:
		MainWindow *window;
		Player *player;
};

#endif
