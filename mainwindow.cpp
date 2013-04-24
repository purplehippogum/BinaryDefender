#include "mainwindow.h"
#include <cmath>
#include <ctime>
#include <iostream>

void MainWindow::handleTimer()
{
	if(bullet){
		if( valid.x() < 408 && ( valid.y() < 380 && valid.y() > 345 ) ){
			bullet->move(-1.2, 0);
		}
		else if(valid.x() > 456 && ( valid.y() < 380 && valid.y() > 345 ) ){
			bullet->move(1.2, 0);
		}
		else if(valid.y() < 345 && (valid.x() > 408 && valid.x() < 456 ) ){
			bullet->move(0, -1.2);
		}
		else if(valid.y() > 380 && (valid.x() > 408 && valid.x() < 456 ) ){
			bullet->move(0, 1.2);
		}
		if(bullet->getX() <= -50 || bullet->getX() > WINDOW_MAX_X){
			inScene = false;
		}
		if(bullet->getY() <= -50 || bullet->getY() > WINDOW_MAX_Y){
			inScene = false;
		}
	}
}

void MainWindow::shoot()
{
	p = QCursor::pos();
	if(!inScene){
		if( (p.x() < 418 && ( p.y() < 380 && p.y() > 345 ) ) || ( p.x() > 448 && ( p.y() < 380 && p.y() > 345 ) ) ||
		( p.y() < 345 && (p.x() > 418 && p.x() < 448 ) ) || ( p.y() > 380 && (p.x() > 418 && p.x() < 448 ) ) ){
			valid = p;
			inScene = true;
			bullet = new BasicBullet(bbIMG, player->getX()+6, player->getY(), 16, 16, p.x(), p.y());
			scene->addItem(bullet); objects.push_back(bullet);
		}
	}
//	std:: cout << "p.x " << p.x() << std::endl;
//	std:: cout << "p.y " << p.y() << std::endl;
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
  
  /** Configure Cursor */
  p = QWidget::mapFromGlobal(p);
  valid = QWidget::mapFromGlobal(valid);
  
	/** Initizlize and set up the play area dummy rectangle that registers clicks */
	area = new PlayArea(-0.03*WINDOW_MAX_X, -0.03*WINDOW_MAX_Y, WINDOW_MAX_X*1.05, WINDOW_MAX_Y*1.05, this);
//	area->setPen(Qt::NoPen);

	/** Set up the paths the enemies will traverse */
	// double nx, double ny, double w, double h, int vx, int vy
	
	/** Initialize timer that will keep the time of the scene */
	timer = new QTimer(this);
	timer->setInterval(5);

	/** Initialize a pixmap for the player and a test AbstractObject */
	playerIMG = new QPixmap("player.png", "png", Qt::AutoColor);
	player = new Player(playerIMG, WINDOW_MAX_X/2, WINDOW_MAX_Y/2, 64, 64, 0, 0);
	
	/** Create an image for the BasicBullet */
	bbIMG = new QPixmap("basic_bullet.png", "png", Qt::AutoColor);
	bullet = NULL;
	inScene = false;
	
	/** This text item is used for testing/debugging purposes */
  item = new QGraphicsSimpleTextItem;
  item->setPos(20, 20);

	/** Add items to the scene */
	scene->addItem(area);
	scene->addItem(item);
	scene->addItem(player); objects.push_back(player);
	
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

