#include "gameplay.h"
#include <iostream>

Gameplay::Gameplay(QGraphicsScene *scene) : QGraphicsView(scene)
{

}

void Gameplay::keyPressEvent(QKeyEvent *k)
{
	if(k->key() == Qt::Key_W){
		std::cout <<  "hey girl" << std::endl;
  }
}
