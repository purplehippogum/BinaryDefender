#ifndef PLAY_AREA_H
#define PLAY_AREA_H

#include <QKeyEvent>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include "mainwindow.h"
#include "player.h"

class MainWindow;
class Player;

class PlayArea : public QGraphicsRectItem
{
	public:
		PlayArea(int nx, int ny, int w, int h, MainWindow *window, Player *p);
		/** Handles the left and right click events */
		void mousePressEvent(QGraphicsSceneMouseEvent *clicked);
		
	private:
		MainWindow *main;
		Player *player;
};

#endif
