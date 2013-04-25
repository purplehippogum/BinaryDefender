#include "mainwindow.h"
#include <cmath>
#include <ctime>
#include <iostream>

using namespace std;

void MainWindow::handleTimer()
{
	/** Keeps track of general timekeeping for round advancing purposes */
	++gameTimer;
	if(gameTimer == 200){
		++seconds;
	}
	/** SMASH the walls! */
// SMASH the top two walls	
	if(q1->getRight() && ( q1->getX() < (WINDOW_MAX_X/2 - q1->getWidth() - 10) ) ){
		q1->moveRight();
	}
	else q1->setRight(false);
	
	if(q3->getLeft() && q3->getX() > ( WINDOW_MAX_X/2 + 10 )){
		q3->moveLeft();
	}
	else q3->setLeft(false);
// SMASH the bottom two walls	
	if(q2->getRight() && ( q2->getX() < (WINDOW_MAX_X/2 - q2->getWidth() - 10) ) ){
		q2->moveRight();
	}
	else q2->setRight(false);
	
	if(q4->getLeft() && q4->getX() > ( WINDOW_MAX_X/2 + 10 )){
		q4->moveLeft();
	}
	else q4->setLeft(false);
// SMASH left two walls
	if(q1->getDown() && ( q1->getY() < (WINDOW_MAX_Y/2 - q1->getHeight() - 15) ) ){
		q1->moveDown();
	}
	else q1->setDown(false);
	
	if(q2->getUp() && q2->getY() > WINDOW_MAX_Y/2 + 15){
		q2->moveUp();
	}
	else q2->setUp(false);
// SMASH the right two walls
	if(q3->getDown() && ( q3->getY() < WINDOW_MAX_Y/2 - 241) ){
		q3->moveDown();
	}
	else q3->setDown(false);

	if(q4->getUp() && q4->getY() > ( WINDOW_MAX_Y/2 + 15 )){
		q4->moveUp();
	}
	else q4->setUp(false);
	/** Now bring em back after they collide */
// reset the top two walls
	if(!q1->getRight() && ( q1->getX() > -31 ) ){
			q1->moveLeft();
	}
	if(!q3->getLeft() && ( q3->getX() < 350 ) ){
			q3->moveRight();
	}
// reset the bottom 2 walls
	if(!q2->getRight() && ( q2->getX() > -31 ) ){
			q2->moveLeft();
	}
	if(!q4->getLeft() && ( q4->getX() < 350 ) ){
			q4->moveRight();
	}
// reset the left two walls
	if(!q1->getDown() && ( q1->getY() > -23 ) ){
			q1->moveUp();
	}
	if(!q2->getUp() && ( q2->getY() < 272 ) ){
			q2->moveDown();
	}
// reset the right two walls
// reset the left two walls
	if(!q3->getDown() && ( q3->getY() > -23 ) ){
			q3->moveUp();
	}
	if(!q4->getUp() && ( q4->getY() < 272 ) ){
			q4->moveDown();
	}
	/** Checks which bullets should be moving */
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
	/** Check for enemy collison with player */
	for(unsigned int i = 0; i < enemies.size(); i++){
		if(enemies[i]->collidesWithItem(q1, Qt::IntersectsItemShape) ||
		enemies[i]->collidesWithItem(q2, Qt::IntersectsItemShape) || 
		enemies[i]->collidesWithItem(q3, Qt::IntersectsItemShape) ||
		enemies[i]->collidesWithItem(q4, Qt::IntersectsItemShape) ){
			delete enemies[i];
			enemies.erase(std::find(enemies.begin(), enemies.end(), enemies[i]));
		}
		else if(enemies[i]->collidesWithItem(player, Qt::IntersectsItemShape) ){
			delete enemies[i];
			enemies.erase(std::find(enemies.begin(), enemies.end(), enemies[i]));
			player->setHealth(player->getHealth() - enemies[i]->getDamage());
			health->setWidth(player->getHealth()*1.2);
		}
	}
	/** Check for bullet exiting the scene and collision with an enemy */
	for(unsigned int i = 0; i < bullets.size(); i++){
		if(bullets[i] && (bullets[i]->getX() <= -25 || bullets[i]->getX() > WINDOW_MAX_X +10||
		bullets[i]->getY() > WINDOW_MAX_Y+10 || bullets[i]->getY() < -25) ){
//			delete bullets[i];
		bullets[i]->setPos(-200, -200);
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
					--enemyCounter;
				}
			}
		}
	}
// collidesWithItem ( const QGraphicsItem * other, Qt::ItemSelectionMode mode = Qt::IntersectsItemShape )
	if(gameTimer%400 == 0){
		srand(p.x());
		int dir = rand()%4;
		++enemyCounter;
		switch(dir){
			case 0: { enemy = new Enemy(enemyIMG, player->getX()+WINDOW_MAX_X/2, player->getY(), 32, 32, 0, 0, 32);
							enemy->setDamage(5);
							enemies.push_back(enemy);
							scene->addItem(enemy);
							break;
						}
			case 1: { enemy = new Enemy(enemyIMG, player->getX()-WINDOW_MAX_X/2, player->getY(), 32, 32, 0, 0, 32);
							enemy->setDamage(5);
							enemies.push_back(enemy);
							scene->addItem(enemy);
							break;
						}
			case 2: { enemy = new Enemy(enemyIMG, player->getX(), player->getY()+WINDOW_MAX_Y/2, 32, 32, 0, 0, 32);
							enemy->setDamage(5);
							enemies.push_back(enemy);
							scene->addItem(enemy);
							break;
						}
			case 3: { enemy = new Enemy(enemyIMG, player->getX(), player->getY()-WINDOW_MAX_Y/2, 32, 32, 0, 0, 32);
							enemy->setDamage(5);
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
		rounds++;
		rString.setNum(rounds);
		rNum->setText(rString);
	}
}

void MainWindow::shoot()
{
  valid = view->mapFromGlobal(valid);
	p = view->mapFromGlobal(QCursor::pos());
//	p = QCursor::pos();
// y offset: 90, x: 55
	double sx = abs(player->getX()+50 - p.x());
	double sy = abs(player->getY()+80 - p.y());
	if(bullets.size() < 2){
		if( sy > sx && ( p.y() < player->getY()+80)){// && (p.x() > (player->getX()-player->getWidth()/2) && p.x() < q3->getX()+q3->getWidth() ) ) ){// up alley
			valid = p;
			bullet = new BasicBullet(bbIMG, player->getX(), player->getY()-1, 16, 16, p.x(), p.y(), 1, 8);
			scene->addItem(bullet);
			bullets.push_back(bullet);
		}

		else if( sy > sx &&	( p.y() > player->getY()+80 ) ){//380 && (p.x() > 360 && p.x() < 480 ) ) ){// down alley
			valid = p;
			bullet = new BasicBullet(bbIMG, player->getX(), player->getY()+1, 16, 16, p.x(), p.y(), 1, 8);
			scene->addItem(bullet);
			bullets.push_back(bullet);
		}
		else if( sx > sy && (p.x() < player->getX()+55 ) ){//380 && ( p.y() < 450 && p.y() > 100 ) ) ){// left alley
			valid = p;
			bullet = new BasicBullet(bbIMG, player->getX()-1, player->getY(), 16, 16, p.x(), p.y(), 1, 8);
			scene->addItem(bullet);
			bullets.push_back(bullet);
		}
		else if( sx > sy && ( p.x() > player->getX()+55) ){//460 && ( p.y() < 450 && p.y() > 100 ) ) ){// right alley
			valid = p;
			bullet = new BasicBullet(bbIMG, player->getX()+1, player->getY(), 16, 16, p.x(), p.y(), 1, 8);
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

void MainWindow::SMASH()
{
//	cout << "\nq1 x " << q1->getX() << endl;
//	cout << "q1 y " << q1->getY() << endl;
	p = view->mapFromGlobal(QCursor::pos());
	cout << "\nmouse x " << p.x() << endl;
	cout << "mouse y " << p.y() << endl;
// test for top two SMASHing
	if( ( p.y() <=  273) && (p.x() > 320 && p.x() < 384 ) ){// up alley
		q1->setRight(true);
		q3->setLeft(true);
	}
	else if(	( p.y() > 338 && (p.x() > 320 && p.x() < 384 ) ) ){// down alley
		q2->setRight(true);
		q4->setLeft(true);
	}
	else if( (p.x() < 321 && ( p.y() < 340 && p.y() > 270 ) ) ){// left alley
		q1->setDown(true);
		q2->setUp(true);
	}
	else if( ( p.x() > 380 && ( p.y() < 340 && p.y() > 270 ) ) ){// right alley
		q3->setDown(true);
		q4->setUp(true);
	}
}

MainWindow::MainWindow()
{
	/** Define some colors */
	QBrush black(Qt::black);
	QBrush white(Qt::white);
	QBrush red(Qt::red);
	
	/** Initialize view and scene */
	scene = new QGraphicsScene(0, -40, WINDOW_MAX_X, WINDOW_MAX_Y, this);
	view = new QGraphicsView(scene);
	
	/** Configure view settings */
  view->setFixedSize(WINDOW_MAX_X*1.1, WINDOW_MAX_Y*1.1);
  view->setWindowTitle("Binary Defender");
  
  /** Configure Cursor */
  p = QWidget::mapFromGlobal(p);
  valid = QWidget::mapFromGlobal(valid);
  
	/** Initizlize and set up the play area dummy rectangle that registers clicks */
	area = new PlayArea(-0.05*WINDOW_MAX_X, -0.05*WINDOW_MAX_Y, WINDOW_MAX_X*1.1, WINDOW_MAX_Y*1.8, this);
	// -0.05, -0.08
//	area->setPen(Qt::NoPen);

	/** Sets up SMASH power */
	SMASHcount = 5;
	/** Set up rounds */
	rounds = 1;
	rString = "Round";
	ROUND = new QGraphicsSimpleTextItem;
	ROUND->setText(rString);
	ROUND->setPos(WINDOW_MAX_X/2-20, -62);
	rString.setNum(rounds);
	rNum = new QGraphicsSimpleTextItem;
	rNum->setText(rString);// add a string here
	rNum->setPos(WINDOW_MAX_X/2, -45);
	
	/** Set up score */
	score = 0;

	/** Set up the paths the enemies will traverse */
	// double nx, double ny, double w, double h, int vx, int vy
	q1 = new GameObject(-31, -23, 320, 230, 0, 0);
	q1->setBrush(black);
	q2 = new GameObject(-31, 272, 320, 230, 0, 0);
	q2->setBrush(black);
	q3 = new GameObject(350, -23, 320, 230, 0, 0);
	q3->setBrush(black);
	q4 = new GameObject(350, 272, 320, 230, 0, 0);
	q4->setBrush(black);
	
	/** Initialize timer that will keep the time of the scene */
	timer = new QTimer(this);
	timer->setInterval(5);
	seconds = 0;

	/** Initialize a pixmap for the player and a test AbstractObject */
	playerIMG = new QPixmap("player.png", "png", Qt::AutoColor);
	player = new Player(playerIMG, WINDOW_MAX_X/2-10, WINDOW_MAX_Y/2-10, 64, 64, 100);
	player->setTransformOriginPoint(player->getX()+40, player->getY() + 45);
	view->mapFromGlobal(player->pos().toPoint());
	
	/** Initialize the health bar */
	health = new HealthBar(-25, -42, 140, 16, 0, 0, player->getHealth());
	health->setBrush(red);
	health->setPen(Qt::NoPen);
	healthOutline = new GameObject(health->getX(), health->getY(), health->getWidth(), 16, 0, 0);
	healthOutline->setBrush(Qt::NoBrush);
	
	/** Initialize and set up the enemies */
	enemyIMG = new QPixmap("enemy_0.png", "png", Qt::AutoColor);
	enemy = NULL;
	enemyCounter = 5;
	
	/** Create an image for the BasicBullet */
	bbIMG = new QPixmap("basic_bullet.png", "png", Qt::AutoColor);
	bullet = NULL;
	
	/** Add items to the scene */
	scene->addItem(area);
	scene->addItem(player); objects.push_back(player);
	scene->addItem(q1);
	scene->addItem(q2);
	scene->addItem(q3);
	scene->addItem(q4);
	scene->addItem(health);
	scene->addItem(healthOutline);
	scene->addItem(ROUND);
	scene->addItem(rNum);
	
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

