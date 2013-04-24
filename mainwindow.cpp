#include "mainwindow.h"
#include <cmath>
#include <ctime>

void MainWindow::handleTimer()
{

}
void MainWindow::shoot()
{
	
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
//	view->setBackgroundBrush(black);
	
	/** Initialize timer that will keep the time of the scene */
	timer = new QTimer(this);
	timer->setInterval(10);

	/** Initialize a pixmap for the player and a test AbstractObject */
	player = new QPixmap("player.png", "png", Qt::AutoColor);
	test = new AbstractObject(player, WINDOW_MAX_X/2, WINDOW_MAX_Y/2, 50, 50, 0, 0);
	
	// ( const QString & fileName, const char * format = 0, Qt::ImageConversionFlags flags = Qt::AutoColor )

  item = new QGraphicsSimpleTextItem;
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

