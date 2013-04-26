#include "gameplay.h"
#include "mainwindow.h"
#include <iostream>

Gameplay::Gameplay(QGraphicsScene *scene, MainWindow *main) : QGraphicsView(scene)
{
	window = main;
}

void Gameplay::keyPressEvent(QKeyEvent *k)
{
	if(k->key() == Qt::Key_W){
		window->movePlayer("up");
  }
	if(k->key() == Qt::Key_S){
		window->movePlayer("down");
  }
	if(k->key() == Qt::Key_A){
		window->movePlayer("left");
  }
	if(k->key() == Qt::Key_D){
		window->movePlayer("right");
  }
}

void Gameplay::keyReleaseEvent(QKeyEvent * k)
{
	if(k->isAutoRepeat())
		k->ignore();
		
	if(k->key() == Qt::Key_W){
		window->movePlayer("stop");
  }
	if(k->key() == Qt::Key_S){
		window->movePlayer("stop");
  }
	if(k->key() == Qt::Key_A){
		window->movePlayer("stop");
  }
	if(k->key() == Qt::Key_D){
		window->movePlayer("stop");
  }
}
