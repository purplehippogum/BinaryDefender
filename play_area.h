#ifndef PLAY_AREA_H
#define PLAY_AREA_H

#include <QKeyEvent>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include "mainwindow.h"

class MainWindow;

class PlayArea : public QGraphicsRectItem
{
	public:
		PlayArea(int nx, int ny, int w, int h, MainWindow *window);
		/** Handles the left and right click events */
		void mousePressEvent(QGraphicsSceneMouseEvent *clicked);
	private:
		MainWindow *main;
};

#endif
