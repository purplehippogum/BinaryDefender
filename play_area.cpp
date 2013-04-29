#include "play_area.h"
#include <iostream>

PlayArea::PlayArea(int nx, int ny, int w, int h, MainWindow *window, Player *p) : QGraphicsRectItem(nx, ny, w, h)
{
	player = p;
	main = window;
}

void PlayArea::mousePressEvent(QGraphicsSceneMouseEvent *clicked)
{
	if(clicked->button() == Qt::LeftButton){
		main->shoot();
	}
	else if(clicked->button() == Qt::RightButton){
		main->SMASHWalls();
	}
	else if(clicked->button() == Qt::MidButton){
		player->cycleAmmo();
	}
}
