#include "mainwindow.h"
#include <cmath>
#include <ctime>
#include <iostream>

using namespace std;

void MainWindow::handleTimer()
{
	++gameTimer;
	if(gameTimer == 200){
		++seconds;
	}
	for(unsigned int i = 0; i < bullets.size(); i++){
		if(bullets[i]->getX() < player->getX()){
			bullets[i]->move(-1.2, 0);
		}
		else if(bullets[i]->getX() > player->getX()){
			bullets[i]->move(1.2, 0);
		}
		else if(bullets[i]->getY() < player->getY()){
			bullets[i]->move(0, -1.2);
		}
		else if(bullets[i]->getY() > player->getY()){
			bullets[i]->move(0, 1.2);
		}
	}
	for(unsigned int i = 0; i < bullets.size(); i++){
		if(bullets[i] && (bullets[i]->getX() <= -40 || bullets[i]->getX() > WINDOW_MAX_X ||
		bullets[i]->getY() > 900 || bullets[i]->getY() < -40) ){
//			delete bullets[i];
			bullets.erase(std::find(bullets.begin(), bullets.end(), bullets[i]));
		}
		for(unsigned int j = 0; j < enemies.size(); j++){
			if(bullets[i]->collidesWithItem(enemies[j], Qt::IntersectsItemShape)){
				enemies[j]->setHealth(enemies[j]->getHealth() - bullets[i]->getDamage());
				bullets[i]->setPos(-200, -200);
//				delete bullets[i];
				bullets.erase(std::find(bullets.begin(), bullets.end(), bullets[i]));
				if(enemies[j]->getHealth() <= 0){
						delete enemies[j];
					enemies.erase(std::find(enemies.begin(), enemies.end(), enemies[j]));
				}
			}
		}
	}
// collidesWithItem ( const QGraphicsItem * other, Qt::ItemSelectionMode mode = Qt::IntersectsItemShape )
	if(gameTimer%400 == 0){
		srand(p.x());
		int dir = rand()%4;
		switch(dir){
			case 0: { enemy = new Enemy(enemyIMG, player->getX()+WINDOW_MAX_X/2, player->getY(), 32, 32, 0, 0, 32);
							enemies.push_back(enemy);
							scene->addItem(enemy);
							break;
						}
			case 1: { enemy = new Enemy(enemyIMG, player->getX()-WINDOW_MAX_X/2, player->getY(), 32, 32, 0, 0, 32);
							enemies.push_back(enemy);
							scene->addItem(enemy);
							break;
						}
			case 2: { enemy = new Enemy(enemyIMG, player->getX(), player->getY()+WINDOW_MAX_Y/2, 32, 32, 0, 0, 32);
							enemies.push_back(enemy);
							scene->addItem(enemy);
							break;
						}
			case 3: { enemy = new Enemy(enemyIMG, player->getX(), player->getY()-WINDOW_MAX_Y/2, 32, 32, 0, 0, 32);
							enemies.push_back(enemy);
							scene->addItem(enemy);
							break;
						}
		}
	}
	if(enemy && gameTimer%5 == 0){
//		std::cout << "Movee" << std::endl;
		for(unsigned int i = 0; i < enemies.size(); i++){
			enemies[i]->move(player->getX(), player->getY());
		}
	}
	if(enemyCounter == 0){// beginning of a new round
		enemyCounter = ( (rounds * 50)/seconds) - (30 * 100 - player->getHealth() );
		seconds = 0;
		++rounds;
	}
}

void MainWindow::shoot()
{
	p = QCursor::pos();
	if(bullets.size() < 2){
		if(	( p.y() > 380 && (p.x() > 418 && p.x() < 448 ) ) ){
			valid = p;
			bullet = new BasicBullet(bbIMG, player->getX(), player->getY()+1, 16, 16, p.x(), p.y(), 1, 8);
			scene->addItem(bullet);
			bullets.push_back(bullet);
		}
		else if( (p.x() < 418 && ( p.y() < 380 && p.y() > 305 ) ) ){
			valid = p;
			bullet = new BasicBullet(bbIMG, player->getX()-1, player->getY(), 16, 16, p.x(), p.y(), 1, 8);
			scene->addItem(bullet);
			bullets.push_back(bullet);
		}
		else if( ( p.x() > 448 && ( p.y() < 380 && p.y() > 305 ) ) ){
			valid = p;
			bullet = new BasicBullet(bbIMG, player->getX()+1, player->getY(), 16, 16, p.x(), p.y(), 1, 8);
			scene->addItem(bullet);
			bullets.push_back(bullet);
		}
		else if( ( p.y() < 305 && (p.x() > 418 && p.x() < 448 ) ) ){
			valid = p;
			bullet = new BasicBullet(bbIMG, player->getX(), player->getY()-1, 16, 16, p.x(), p.y(), 1, 8);
			scene->addItem(bullet);
			bullets.push_back(bullet);
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
	area = new PlayArea(-0.05*WINDOW_MAX_X, -0.05*WINDOW_MAX_Y, WINDOW_MAX_X*1.1, WINDOW_MAX_Y*1.1, this);
//	area->setPen(Qt::NoPen);

	/** Set up the paths the enemies will traverse */
	// double nx, double ny, double w, double h, int vx, int vy
	q1 = new GameObject(-31, -23, 320, 230, 0, 0);
	q2 = new GameObject(-31, 272, 320, 230, 0, 0);
	q3 = new GameObject(350, -23, 320, 230, 0, 0);
	q4 = new GameObject(350, 272, 320, 230, 0, 0);
	
	/** Initialize timer that will keep the time of the scene */
	timer = new QTimer(this);
	timer->setInterval(5);
	seconds = 0;

	/** Initialize a pixmap for the player and a test AbstractObject */
	playerIMG = new QPixmap("player.png", "png", Qt::AutoColor);
	player = new Player(playerIMG, WINDOW_MAX_X/2-10, WINDOW_MAX_Y/2-10, 64, 64, 0, 0, 100);
	
	/** Initialize and set up the enemies */
	enemyIMG = new QPixmap("enemy_0.png", "png", Qt::AutoColor);
	enemy = NULL;
	enemyCounter = 5;
	enemyDelay = 0;
	
	/** Create an image for the BasicBullet */
	bbIMG = new QPixmap("basic_bullet.png", "png", Qt::AutoColor);
	bullet = NULL;
	
	/** This text item is used for testing/debugging purposes */
  item = new QGraphicsSimpleTextItem;
  item->setPos(20, 20);

	/** Add items to the scene */
	scene->addItem(area);
	scene->addItem(item);
	scene->addItem(player); objects.push_back(player);
	scene->addItem(q1);
	scene->addItem(q2);
	scene->addItem(q3);
	scene->addItem(q4);
	
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

