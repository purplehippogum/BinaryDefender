#include "mainwindow.h"
#include <cmath>
#include <ctime>

void MainWindow::handleTimer()
{
	p = QCursor::pos();
	test->face(p.x(), p.y());
  txt.setNum(test->getRot());
  item->setText(txt);
}

void MainWindow::toggleTimer(){
	if(timer->isActive()) timer->stop();

	else timer->start();
}

MainWindow::MainWindow()  {
	/** Define some colors */
	QBrush black(Qt::black);
	QBrush white(Qt::white);
	
	/** Initialize view and scene */
	scene = new QGraphicsScene(0, 0, WINDOW_MAX_X, WINDOW_MAX_Y, this);
	view = new QGraphicsView(scene);
	
	/** Configure view settings */
  view->setFixedSize(WINDOW_MAX_X*1.1, WINDOW_MAX_Y*1.1);
  view->setWindowTitle("Binary Defender");
	view->setBackgroundBrush(black);
	
	/** Initialize timer that will keep the time of the scene */
	timer = new QTimer(this);
	timer->setInterval(10);

	/** Initialize a test GameObject */
	test = new GameObject(WINDOW_MAX_X/2, WINDOW_MAX_Y/2, 50, 50, 0, 0);
	test->setBrush(white);

  item = new QGraphicsSimpleTextItem;
  item->setBrush(white);
  item->setPos(20, 20);

	scene->addItem(item);	
	scene->addItem(test);
	
	/** Game Events, or connections */
	connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));
}

void MainWindow::show() {
	timer->start();
	view->show();
}

MainWindow::~MainWindow()
{
	timer->stop();
}

