#include "play_area.h"
#include "mainwindow.h"
#include <iostream>

PlayArea::PlayArea(int nx, int ny, int w, int h, MainWindow *window) : QGraphicsRectItem(nx, ny, w, h)
{ 
	main = window;
}

void PlayArea::mousePressEvent(QGraphicsSceneMouseEvent *clicked)
{
	if(clicked->button() == Qt::LeftButton){
		main->shoot();
	}
	else if(clicked->button() == Qt::RightButton){
		main->SMASH();
	}
}

void PlayArea::keyPressEvent(QKeyEvent *k)
{
	if(k->key() == Qt::Key_W){
		std::cout <<  "hey girl" << std::endl;
  }
}
