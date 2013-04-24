#ifndef PLAY_AREA_H
#define PLAY_AREA_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

class MainWindow;

class PlayArea : public QGraphicsRectItem
{
	public:
		PlayArea(int nx, int ny, int w, int h, MainWindow *window);
		void mousePressEvent(QGraphicsSceneMouseEvent *clicked);
		/** Handles key presses */
	private:
		MainWindow *main;
};

#endif
