#include "health_bar.h"

HealthBar::HealthBar(double nx, double ny, double w, double h, int vx, int vy, int v)
	: GameObject(nx, ny, w, h, vx, vy)
{
	val = v;
  txt = "Health";
  item = new QGraphicsSimpleTextItem(this);
  item->setText(txt);
  item->setPos(x, y - 15);
  item->show();
}

