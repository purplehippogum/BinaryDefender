#ifndef PLAY_AREA_H
#define PLAY_AREA_H

#include <QKeyEvent>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

class MainWindow;

class PlayArea : public QGraphicsRectItem
{
	public:
		PlayArea(int nx, int ny, int w, int h, MainWindow *window);
		/** Handles the left and right click events */
		void mousePressEvent(QGraphicsSceneMouseEvent *clicked);
		void keyPressEvent(QKeyEvent *k);
	private:
		MainWindow *main;
};

#endif
