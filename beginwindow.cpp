#include "beginwindow.h"

BeginWindow::BeginWindow(int x, int y)
{
	move(x,y);
	setLayout(layout);
  edit = new QLineEdit(this);
}
