#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <QKeyEvent>
#include <QGraphicsView>
#include <QGraphicsScene>

class Gameplay : public QGraphicsView
{
	public:
		Gameplay(QGraphicsScene *scene);
		void keyPressEvent(QKeyEvent *k);
	private:
		
};

#endif
