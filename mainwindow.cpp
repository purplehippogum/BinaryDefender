#include "mainwindow.h"
#include <cmath>
#include <ctime>
#include <iostream>

#include <QDebug>
using namespace std;

bool MainWindow::checkCollision(AbstractObject *obj)
{
	if(obj->collidesWithItem(q1, Qt::IntersectsItemShape))
		return true;
	else if(obj->collidesWithItem(q2, Qt::IntersectsItemShape))
		return true;
	else if(obj->collidesWithItem(q3, Qt::IntersectsItemShape))
		return true;
	else if(obj->collidesWithItem(q4, Qt::IntersectsItemShape))
		return true;
	if(t1){
		if(obj->collidesWithItem(t1, Qt::IntersectsItemShape))
		return true;
	else if(obj->collidesWithItem(b1, Qt::IntersectsItemShape))
		return true;
	else if(obj->collidesWithItem(c1, Qt::IntersectsItemShape))
		return true;
	}
	else if(obj->getY() < -20)
		return true;
	else if(obj->getY() > WINDOW_MAX_Y-52)
		return true;
	else if(obj->getX() < -20)
		return true;
	else if(obj->getX() > WINDOW_MAX_X+3)
		return true;
	return false;
}

bool MainWindow::checkPlace(QPointF p)
{
	if(p.x() > 450 && (p.y() < 200 || p.y() > 250) )// right two blocks
		return true;
	if(p.x() < 180 && (p.y() < 200 || p.y() > 250) )// left two blocks
		return true;
		
	if( (p.x() > 230 && p.x() < 380) && (p.y() > 340 || p.y() < 90) )// top/bottom middle block
		return true;
	if( (p.x() > 230 && p.x() < 380) && (p.y() > 140 && p.y() < 310) )// central block
		return true;

	return false;
}

void MainWindow::pushOut(AbstractObject *obj, int dir)
{
	if(checkCollision(player) && dir == 0){
		obj->moveBy(-5,0);
	}
	if(checkCollision(player) && dir == 1){
		obj->moveBy(-5,0);
	}
}

void MainWindow::handleTimer()
{
	/** Display the arrow icon */
	arrowStr.setNum(player->getArrows());
	arrowText->setText(arrowStr);
	if(player->getAmmo() == 1)
		arrowCount->setSelected();
	else
		arrowCount->deSelect();
	
	if(rounds % 2 == 0 && !heartCreated){
		heart = new Heart(heartIMG, 300, 320, 16, 16, 5);
		scene->addItem(heart);
		heartCreated = true;
	}
	if(heart && player->collidesWithItem(heart, Qt::IntersectsItemShape)){
		if(player->getHealth() < 100){
			player->setHealth(player->getHealth()+5);
			health->setWidth(player->getHealth()*1.2);
		}
		scene->removeItem(heart);
		heart = NULL;
	}
	if(heart && !checkCollision(heart) &&(
	 ( abs(heart->getX() - player->getX()) ) <= 80 || ( abs(heart->getY() - player->getY()) ) <= 60) ){
		if(heart->getX() >= player->getX())
			heart->moveRight(1);
		else
			heart->moveLeft(1);
			
		if(heart->getY() >= player->getY())
			heart->moveDown(1);
		else
			heart->moveUp(1);
	}
	
	/** Ends game if player's health falls below zero */
	if(player->getHealth() <= 0){
		emit death();
	}

	/** Keeps track of general timekeeping for round advancing purposes */
	gameTimer += 0.5;
	if(fmod(gameTimer, 20.0) == 0.0){
		++seconds;
	}
	if(killCount >= enemyLimit){// beginning of a new round
//			cout << "Seconds for round " << seconds << endl;
			enemyLimit += rounds*1.2;
			if(enemySpeed < 2.5)
				enemySpeed += 0.5;
			if(enemySpawnRate < 200)
				enemySpawnRate += 50;
			killCount = 0;
			seconds = 1;
			SMASHcount++;
			SMASH->setPixmap(*SMASHIMG);
			rounds++;
			rString.setNum(rounds);
			rNum->setText(rString);
			heartCreated = false;
//			cout << "Enemy limit " << enemyLimit << endl;
	}
	/** Set up level 2 */
	if(rounds == 5 && level == 1){
		buildLevelTwo();
		level++;
	}
/** Handle player movement */
// up
	if(player->getDir() == 0 && !checkCollision(player) ){
		nameDisp->setPos(player->getX(), player->getY()+25);
		player->setTransformOriginPoint(0, 23);// 23
		nameDisp->setRotation(0);
		player->setRotation(0);
		player->moveUp(1);
	}
	else if(player->rotation() == 0 && checkCollision(player)){
		player->moveDown(1);
		pushOut(player, 0);
		nameDisp->setPos(player->getX(), player->getY()-20);
	}
// down
	if(player->getDir() == 1 && !checkCollision(player) ){
		nameDisp->setPos(player->getX(), player->getY()-9);
		nameDisp->setRotation(0);
		player->setTransformOriginPoint(14, 18);
		player->setRotation(180);
		player->moveDown(1);
	}
	else if(player->rotation() == 180 && checkCollision(player)){
		player->moveUp(1);
		pushOut(player, 1);
	}
// left
	if(player->getDir() == 2 && !checkCollision(player) ){
		player->setTransformOriginPoint(10, 20);
		player->setRotation(-90);
		player->moveLeft(1);
		nameDisp->setPos(player->getX()+20, player->getY()+35);
		nameDisp->setRotation(-90);
	}
	else if(player->rotation() == -90 && checkCollision(player)){
		player->moveRight(1);
	}
//  right
	if(player->getDir() == 3 && !checkCollision(player)){
		player->setTransformOriginPoint(10, 15);
		player->setRotation(90);
		nameDisp->setPos(player->getX(), player->getY());
		nameDisp->setRotation(90);
		player->moveRight(1);
	}
	else if(player->rotation() == 90 && checkCollision(player) ){
		player->moveLeft(1);
	}
	
	else if(player->getDir() == 3 && player->rotation() == 90 && checkCollision(player) ){
		player->moveUp(1);
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
	
// SMASH the central and top walls
	if(t1->getDown() && ( t1->getY() < 0) ){
		t1->moveDown();
	}
	else t1->setDown(false);

	if(c1->getUp() && c1->getY() > ( 130 )){
		c1->moveUp();
	}
	else c1->setUp(false);
	
// SMASH the central and bottom walls
	if(c1->getDown() && ( c1->getY() < 170) ){
		c1->moveDown();
	}
	else c1->setDown(false);

	if(b1->getUp() && b1->getY() > ( 330 )){
		b1->moveUp();
	}
	else b1->setUp(false);
	
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
	if(!q3->getDown() && ( q3->getY() > -23 ) ){
			q3->moveUp();
	}
	if(!q4->getUp() && ( q4->getY() < 272 ) ){
			q4->moveDown();
	}
	
// reset the central and top walls
	if(!t1->getDown() && ( t1->getY() > -23 ) ){
			t1->moveUp();
	}
	if(!c1->getUp() && ( c1->getY() < WINDOW_MAX_Y/2-85 ) ){
			c1->moveDown();
	}
	
// reset the central and bottom walls
	if(!c1->getDown() && ( c1->getY() > WINDOW_MAX_Y/2-85 ) ){
			c1->moveUp();
	}
	if(!b1->getUp() && ( b1->getY() < WINDOW_MAX_Y-120 ) ){
			b1->moveDown();
	}
	
/** Checks which bullets should be moving */
	for(unsigned int i = 0; i < bullets.size(); i++){
		if(bullets[i]->getDir() == 2){// move left
			bullets[i]->setRotation(-90);
			bullets[i]->move(-1.2, 0);
		}
		else if(bullets[i]->getDir() == 3){// move right
			bullets[i]->setRotation(90);
			bullets[i]->move(1.2, 0);
		}
		else if(bullets[i]->getDir() == 0){// move up
//			bullets[i]->setRotation(0);
			bullets[i]->move(0, -1.2);
		}
		else if(bullets[i]->getDir() == 1){// move down
			bullets[i]->setRotation(180);
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
			killCount++;
			score->addPoints(enemies[i]->getPoints());
			score->updateScore();
		}
		else if(enemies[i]->collidesWithItem(player, Qt::IntersectsItemShape) ){
			delete enemies[i];
			enemies.erase(std::find(enemies.begin(), enemies.end(), enemies[i]));
			killCount++;
			player->setHealth(player->getHealth() - enemies[i]->getDamage());
			health->setWidth(player->getHealth()*1.2);
		}
	}
/** Check for bullet exiting the scene and collision with an enemy */
	for(unsigned int i = 0; i < bullets.size(); i++){
		if(bullets[i] && (bullets[i]->getX() <= -25 || bullets[i]->getX() > WINDOW_MAX_X +10||
		bullets[i]->getY() > WINDOW_MAX_Y+10 || bullets[i]->getY() < -25) ){
		bullets[i]->setPos(-200, -200);
			bullets.erase(std::find(bullets.begin(), bullets.end(), bullets[i]));
		}
/*		if( bullets[i]->collidesWithItem(q1, Qt::IntersectsItemShape) ||
		bullets[i]->collidesWithItem(q2, Qt::IntersectsItemShape) || 
		bullets[i]->collidesWithItem(q3, Qt::IntersectsItemShape) ||
		bullets[i]->collidesWithItem(q4, Qt::IntersectsItemShape) ){*/
		if(checkCollision(bullets[i])){
			bullets[i]->setPos(-200, -200);
			bullets.erase(std::find(bullets.begin(), bullets.end(), bullets[i]));
		}
/** Check for bullet collision with enemy */
		for(unsigned int j = 0; j < enemies.size(); j++){
			if(bullets[i]->collidesWithItem(enemies[j], Qt::IntersectsItemShape)){
				bullets[i]->setInEnemy(true);
				enemies[j]->setHealth(enemies[j]->getHealth() - bullets[i]->getDamage());
				if(bullets[i]->getStrike() <= 0){
					bullets[i]->setPos(-200, -200);
					bullets.erase(std::find(bullets.begin(), bullets.end(), bullets[i]));
				}
				if(enemies[j]->getHealth() <= 0){
					delete enemies[j];
					enemies.erase(std::find(enemies.begin(), enemies.end(), enemies[j]));
					killCount++;
					score->addPoints(enemies[i]->getPoints());
					score->updateScore();
				}
				bullets[i]->decStrike();
			}
			else{
				bullets[i]->setInEnemy(false);
			}
		}
	}
/** This if statement handles enemy spawning */
	if(fmod( gameTimer, (200.0- enemySpawnRate) ) == 0){
		int dir = rand()%6;
//		dir = 0;
		if(level == 1){
			switch(dir){
			// right side
				case 0: { enemy = new Enemy(enemyIMG, WINDOW_MAX_X, WINDOW_MAX_Y/2-15, 32, 32, 32, 48);
								enemy->setDamage(5);
								enemies.push_back(enemy);
								scene->addItem(enemy);
								break;
							}
			// left side
				case 1: { enemy = new Enemy(enemyIMG, 0, WINDOW_MAX_Y/2-20, 32, 32, 32, 48);
								enemy->setDamage(5);
								enemies.push_back(enemy);
								scene->addItem(enemy);
								break;
							}
			// bottom
				case 2: { enemy = new Enemy(enemyIMG, WINDOW_MAX_X/2, WINDOW_MAX_Y+40, 32, 32, 32, 48);
								enemy->setDamage(5);
								enemies.push_back(enemy);
								scene->addItem(enemy);
								break;
							}
			// top
				case 3: { enemy = new Enemy(enemyIMG, WINDOW_MAX_X/2, -25, 32, 32, 32, 48);
								enemy->setDamage(5);
								enemies.push_back(enemy);
								scene->addItem(enemy);
								break;
							}
			}
		}
		else if(level == 2){
			switch(dir){
			// right side
				case 0: { enemy = new Enemy(enemyIMG, WINDOW_MAX_X, WINDOW_MAX_Y/2-15, 32, 32, 32, 48);
								enemy->setDamage(5);
								enemies.push_back(enemy);
								scene->addItem(enemy);
								enemy->setPath(0);
								break;
							}
			// left side
				case 1: { enemy = new Enemy(enemyIMG, 0, WINDOW_MAX_Y/2-20, 32, 32, 32, 48);
								enemy->setDamage(5);
								enemies.push_back(enemy);
								scene->addItem(enemy);
								enemy->setPath(2);
								break;
							}
			// upper right top
				case 2: { enemy = new Enemy(enemyIMG, WINDOW_MAX_X/2+100, -25, 32, 32, 32, 48);
								enemy->setDamage(5);
								enemies.push_back(enemy);
								scene->addItem(enemy);
								enemy->setPath(5);
								break;
							}
			//upper left top
				case 3: { enemy = new Enemy(enemyIMG, WINDOW_MAX_X/2-120, -25, 32, 32, 32, 48);
								enemy->setDamage(5);
								enemies.push_back(enemy);
								scene->addItem(enemy);
								enemy->setPath(2);
								break;
							}
			//lower right bottom
				case 4: { enemy = new Enemy(enemyIMG, WINDOW_MAX_X/2+100, WINDOW_MAX_Y-50, 32, 32, 32, 48);
								enemy->setDamage(5);
								enemies.push_back(enemy);
								scene->addItem(enemy);
								enemy->setPath(5);
								break;
							}
			//lower left bottom
				case 5: { enemy = new Enemy(enemyIMG, WINDOW_MAX_X/2-120, WINDOW_MAX_Y-50, 32, 32, 32, 48);
								enemy->setDamage(5);
								enemies.push_back(enemy);
								scene->addItem(enemy);
								enemy->setPath(2);
								break;
							}
			}
		}
	}

/** Handles enemy movement. Speed, etc */
	if(enemy && fmod( gameTimer,(1.0 - enemySpeed) ) == 0){
		if(level == 1){
			for(unsigned int i = 0; i < enemies.size(); i++){
				if(!enemies[i]->getHunt())
					enemies[i]->move(WINDOW_MAX_X/2-15, WINDOW_MAX_Y/2-15);
				if(enemies[i]->getX() == WINDOW_MAX_X/2-15 && enemies[i]->getY() == WINDOW_MAX_Y/2-15){
					enemies[i]->setHunt(true);
				}
				if(enemies[i]->getHunt()){
					enemies[i]->move(player->getX(), player->getY());
				}
			}
		}
		else if(level == 2){
			for(unsigned int i = 0; i < enemies.size(); i++){
			int dy = abs(enemies[i]->getY() - player->getY());
			int dx = abs(enemies[i]->getX() - player->getX());

			/** Move to a node */
//				if(dx >= 8 && dy >= 8){
					if(enemies[i]->getPath() == 0){
						enemies[i]->move(420, WINDOW_MAX_Y/2-15);
					}
					if(enemies[i]->getPath() == 1){
						enemies[i]->move(420, 110);
					}
					if(enemies[i]->getPath() == 2){
						enemies[i]->move(200, 110);
					}
					if(enemies[i]->getPath() == 4){
						enemies[i]->move(200, 315);
					}
					if(enemies[i]->getPath() == 5){
						enemies[i]->move(420, 315);
					}
				/** Stop at a node and choose a direction */
					if(enemies[i]->getX() == 420 && enemies[i]->getY() == WINDOW_MAX_Y/2-15){//reaches node 0
						int randDir = rand()%2;
							if(randDir == 0){
								enemies[i]->setPath(1);
							}
							else{
								enemies[i]->setPath(5);
							}
					}
					if(enemies[i]->getX() == 420 && enemies[i]->getY() == 110){//reaches node 1
						int randDir = rand()%2;
							if(randDir == 0){
								enemies[i]->setPath(2);
							}
							else{
								enemies[i]->setPath(5);
							}
					}
					if(enemies[i]->getX() == 200 && enemies[i]->getY() == 110){// reaches node 2
						int randDir = rand()%2;
							if(randDir == 0){
								enemies[i]->setPath(1);
							}
							else{
								enemies[i]->setPath(4);
							}
					}
					if(enemies[i]->getX() == 200 && enemies[i]->getY() == 315){// reaches node 4
						int randDir = rand()%2;
							if(randDir == 0){
								enemies[i]->setPath(2);
							}
							else{
								enemies[i]->setPath(5);
							}
					}
					if(enemies[i]->getX() == 420 && enemies[i]->getY() == 315){// reaches node 5
						int randDir = rand()%2;
							if(randDir == 0){
								enemies[i]->setPath(4);
							}
							else{
								enemies[i]->setPath(1);
							}
					}
//				}
				else{
//					enemies[i]->move(player->getX(), player->getY());
				}
			}
		}
	}
}

void MainWindow::buildLevelTwo()
{
	/** Move and scale down the existing walls to the corners */
	q1->setSize(200, 230);
	q2->setSize(200, 230);
	q3->setSize(200, 230);
	q3->moveBy(120, 0);
	q4->setSize(200, 230);
	q4->moveBy(120, 0);
	
	/** Create the new walls that will create the new maze */
	QBrush black(Qt::black);
	//top middle wall
	t1 = new GameObject(WINDOW_MAX_X/2-75, -23, 150, 120, 0, 0);
	t1->setBrush(black);
	scene->addItem(t1);
	//bottom middle wall
	b1 = new GameObject(WINDOW_MAX_X/2-75, WINDOW_MAX_Y-120, 150, 120, 0, 0);
	b1->setBrush(black);
	scene->addItem(b1);
	
	c1 = new GameObject(WINDOW_MAX_X/2-75, WINDOW_MAX_Y/2-85, 150, 150, 0, 0);
	c1->setBrush(black);
	scene->addItem(c1);
	
//	player->setPos(300, 320);
//	player->setRotation(0);
//	player->update(300, 320, 72, 72);
	nameDisp->setPos(player->getX(), player->getY()+100);
}

void MainWindow::shoot()
{
  valid = gameplay->mapFromGlobal(valid);
//	p = gameplay->mapFromGlobal(QCursor::pos());
//	p = gameplay->mapFromScene(QCursor::pos());
	
	if(bullets.size() < 2 && timer->isActive() ){
		if( player->rotation() == 0){// shoot up
			if(player->getAmmo() == 0){
				valid = p;
				bullet = new BasicBullet(bbIMG, player->getX()+5, player->getY()-3, 16, 16, p.x(), p.y(), 1, 8);
				player->getAmmo();
				bullet->setDir(0);
				scene->addItem(bullet);
				bullets.push_back(bullet);
			}
			else if(player->getAmmo() == 1 && player->getArrows() > 0){
				valid = p;
				arrow = new ArrowBullet(arrowIMG, player->getX()+8, player->getY()-19, 16, 16, p.x(), p.y(), 1, 5);
				arrow->setTransformOriginPoint(16, -50);
				player->getAmmo();
				arrow->setDir(0);
				scene->addItem(arrow);
				bullets.push_back(arrow);
				player->decPierce();
			}
		}

		else if( player->rotation() == 180){// shoot down
			if(player->getAmmo() == 0){
				valid = p;
				bullet = new BasicBullet(bbIMG, player->getX()+4, player->getY()+1, 16, 16, p.x(), p.y(), 1, 8);
				bullet->setTransformOriginPoint(9, 21);
				bullet->setDir(1);
				scene->addItem(bullet);
				bullets.push_back(bullet);
			}
			else if(player->getAmmo() == 1 && player->getArrows() > 0){
				valid = p;
				arrow = new ArrowBullet(arrowIMG, player->getX()+14, player->getY()+47, 16, 16, p.x(), p.y(), 1, 5);
				arrow->setTransformOriginPoint(0, 0);
				arrow->setDir(1);
				scene->addItem(arrow);
				bullets.push_back(arrow);
				player->decPierce();
			}
		}
		else if( player->rotation() == -90 ){// shoot left
			if(player->getAmmo() == 0){
				valid = p;
				bullet = new BasicBullet(bbIMG, player->getX()-1, player->getY()-4, 16, 16, p.x(), p.y(), 1, 8);
				bullet->setTransformOriginPoint(6, 23);
				bullet->setDir(2);
				scene->addItem(bullet);
				bullets.push_back(bullet);
			}
			else if(player->getAmmo() == 1 && player->getArrows() > 0){
				valid = p;
				arrow = new ArrowBullet(arrowIMG, player->getX()-1, player->getY(), 16, 16, p.x(), p.y(), 1, 5);
				arrow->setTransformOriginPoint(-5, 27);
				arrow->setRotation(180);
				arrow->setDir(2);
				scene->addItem(arrow);
				bullets.push_back(arrow);
				player->decPierce();
			}
		}
		else if( player->rotation() == 90 ){// shoot right
			valid = p;
			if(player->getAmmo() == 0){
				bullet = new BasicBullet(bbIMG, player->getX()+1, player->getY()-3, 16, 16, p.x(), p.y(), 1, 8);
				bullet->setTransformOriginPoint(10, 23);
				bullet->setDir(3);
				scene->addItem(bullet);
				bullets.push_back(bullet);
			}
			else if(player->getAmmo() == 1 && player->getArrows() > 0){
				arrow = new ArrowBullet(arrowIMG, player->getX()+1, player->getY(), 16, 16, p.x(), p.y(), 1, 5);
				arrow->setDir(3);
				arrow->setTransformOriginPoint(16, 31);
				scene->addItem(arrow);
				bullets.push_back(arrow);
				player->decPierce();
			}
		}
	}
}

void MainWindow::restartGame()
{
	qApp->exit(EXIT_CODE_REBOOT);
}

void MainWindow::pauseGame(){
	if(timer->isActive()){
		QMessageBox *msgBox = new QMessageBox;
		msgBox->move(WINDOW_MAX_X/2-50, WINDOW_MAX_Y/2+50);
		msgBox->setText("Game Paused");
		msgBox->addButton(quit, QMessageBox::DestructiveRole);
		msgBox->addButton(resume, QMessageBox::YesRole);
		msgBox->addButton(restart, QMessageBox::NoRole);
		msgBox->show();
		timer->stop();
	}
}

void MainWindow::handleDeath()
{
		player->setPos(-200, -200);
		QMessageBox *msgBox = new QMessageBox;
		msgBox->move(WINDOW_MAX_X/2-50, WINDOW_MAX_Y/2+50);
		msgBox->setText("Game Over");
		msgBox->addButton(quit, QMessageBox::DestructiveRole);
		msgBox->addButton(restart, QMessageBox::NoRole);
		msgBox->show();
		timer->stop();
		score->decimal();
//		score->setPos(WINDOW_MAX_X/2-280, WINDOW_MAX_Y/2+40);
		
		/** Insert the player's score in its proper place */
		vector<QString>::iterator sit = highScoreNames.begin();
		vector<int>::iterator it;
		int index = 0;
		for(it = highScores.begin(); it != highScores.end(); ++it){
			if(score->getPoints() >= *it){
				cout << "points " <<  *it << endl;
				it = highScores.insert(it, score->getPoints());
				sit = highScoreNames.insert(sit, name);
				break;
			}
			++index;
			++sit;
		}
		
		if(highScores.size() == 0){
			cout << "Empty" << endl;
			highScores.push_back(score->getPoints());
			highScoreNames.push_back(name);
		}
		
		/** Write the scores to the file */
		fstream writeScores("high_scores.txt", ofstream::in | ofstream::out);
		if(writeScores.fail())
			cerr << "FAILURE" << endl;
		else{
			for(unsigned int i = 0; i < highScores.size(); i++){
				string tmp = highScoreNames[i].toStdString();
				
				writeScores << tmp << " " << highScores[i] << endl;
			}
		}
		highScoreTable = new HighScoreTable(this, 0, 0, highScores, highScoreNames);
		highScoreTable->show();
}

void MainWindow::resumeGame()
{
	/** Set up and display the player's name */
	name = begin->getString();
	nameDisp = new QGraphicsSimpleTextItem;
	nameDisp->setText(name);
	nameDisp->setPos(player->getX(), player->getY()+25);
	scene->addItem(nameDisp);
	
	if(!timer->isActive()){
		timer->start();
	}
}

/** This power may be activated about once a round to effectively clear a lane of enemies */
void MainWindow::SMASHWalls()
{
	p = gameplay->mapFromGlobal(QCursor::pos());
//	cout << "c pos " << p.x() << ", " << p.y() << endl;
		if(level == 1){
			if( ( p.y() <=  273) && (p.x() > 320 && p.x() < 384 ) ){// up alley
				SMASHcount--;
				q1->setRight(true);
				q3->setLeft(true);
			}
			else if(	( p.y() > 338 && (p.x() > 320 && p.x() < 384 ) ) ){// down alley
				SMASHcount--;
				q2->setRight(true);
				q4->setLeft(true);
			}
			if( (p.x() < 321 && ( p.y() < 340 && p.y() > 270 ) ) ){// left alley
				q1->setDown(true);
				q2->setUp(true);
				SMASHcount--;
			}
			else if( ( p.x() > 380 && ( p.y() < 340 && p.y() > 270 ) ) ){// right alley
				q3->setDown(true);
				q4->setUp(true);
				SMASHcount--;
			}
		}
		else{
			if( (p.y() <= 425 && p.y() >= 370) && (p.x() >= 280 && p.x() <= 430 ) ){
				b1->setUp(true);
				c1->setDown(true);
				SMASHcount--;
			}
			if( (p.y() >= 160 && p.y() <= 220) && (p.x() >= 280 && p.x() <= 430 ) ){
				t1->setDown(true);
				c1->setUp(true);
				SMASHcount--;
			}
			if( (p.x() < 210 && ( p.y() < 340 && p.y() > 270 ) ) ){// left alley
				q1->setDown(true);
				q2->setUp(true);
				SMASHcount--;
			}
			if( p.x() > 500 && ( p.y() < 340 && p.y() > 270 ) ){// right alley
				q3->setDown(true);
				q4->setUp(true);
				SMASHcount--;
			}
/*			if( (p.x() >= 210 && p.x() <= 280) && ( p.y() <= 160 && p.y() > 0 ) ){
				q1->setRight(true);
				t1->setLeft(true);
			}*/
		}

	if(SMASHcount == 0)
		SMASH->setPixmap(*blank);
}

MainWindow::MainWindow()
{
	/** Define some colors */
	QBrush black(Qt::black);
	QBrush white(Qt::white);
	QBrush red(Qt::red);
	QBrush green(Qt::green);
	
	/** Set a new default font */
	QFont newFont("Courier", 12, QFont::Bold, true);
	QApplication::setFont(newFont);
	
	/** Set up the welcome beginning window */
	begin = new BeginWindow(this, WINDOW_MAX_X/2-100, WINDOW_MAX_Y/2+100);
	
	/** Set up the reboot QAction */
	actionReboot = new QAction(this);
	actionReboot->setText(tr("Restart"));

	/** Used to read in high scores */
	fstream scoreFile("high_scores.txt", fstream::in | fstream::out);
	/** Check for score failure */
	if(scoreFile.fail()){
		QErrorMessage *noScores = new QErrorMessage(this);
		noScores->setMinimumSize(200, 200);
		noScores->showMessage("Unable to read high scores file! No high scores will be recorded this time.");
	}
	
	if(scoreFile){
	/** Stores the high scores */
		while(!scoreFile.eof()){
			int s;
			string n;
			QString qn;
			
			scoreFile >> n;
			scoreFile >> s;
			highScores.push_back(s);
			qn = qn.fromStdString(n);
			highScoreNames.push_back(qn);
		}
		highScores.pop_back();
		highScoreNames.pop_back();
		
		scoreFile.close();
	}
	else{
		cout << "create" << endl;
		scoreFile.open("high_scores.txt", fstream::out);
//		scoreFile << "asdsadasd";
		scoreFile.close();
	}

	/** Initialize level count */
	level = 1;

	/** Initialize a pixmap for the player */
	playerIMG = new QPixmap("player.png", "png", Qt::AutoColor);
	player = new Player(playerIMG, WINDOW_MAX_X/2-10, WINDOW_MAX_Y/2-10, 72, 72, 100);
	player->setTransformOriginPoint(10, 17);// 10, 17

	/** Initialize heart */
	heartIMG = new QPixmap("heart.png", "png", Qt::AutoColor);
	heart = NULL;
	heartCreated = false;
	
	/** Initialize gameplay and scene */
	scene = new QGraphicsScene(0, -40, WINDOW_MAX_X, WINDOW_MAX_Y, this);//
	gameplay = new Gameplay(scene, this, player);
	
	/** Configure gameplay settings */
  gameplay->setFixedSize(WINDOW_MAX_X*1.1, WINDOW_MAX_Y*1.1);
  gameplay->setWindowTitle("Binary Defender");
  
  /** Set up SMASH Display */
  SMASHIMG = new QPixmap("SMASH.png", "png", Qt::AutoColor);
  blank = new QPixmap("blank.PNG", "png", Qt::AutoColor);
  SMASH = new QGraphicsPixmapItem();
  SMASH->setPos(WINDOW_MAX_X/2+30, -55);
  SMASH->setPixmap(*SMASHIMG);
  
  
	/** Seeds random to x coordinate of mouse */
	p = gameplay->mapFromGlobal(QCursor::pos());
	srand(p.x());
  
  /** Configure Cursor */
  p = QWidget::mapFromGlobal(p);
  valid = QWidget::mapFromGlobal(valid);
  
  /** Set up pause button */
  pause = new QPushButton("Pause Game");
  pause->move(WINDOW_MAX_X/2-150, -55);
  /** Set up quit pause menu button */
  quit = new QPushButton("Quit Game");
  /** Set up resume pause menu button */
  resume = new QPushButton("Resume Game");
  /** Set up restart button */
  restart = new QPushButton("Restart Game");

	/** Initizlize and set up the play area dummy rectangle that registers clicks */
	area = new PlayArea(-0.05*WINDOW_MAX_X, -0.05*WINDOW_MAX_Y, WINDOW_MAX_X*1.1, WINDOW_MAX_Y*1.8, this, player);
	// -0.05, -0.08
//	area->setPen(Qt::NoPen);

	/** Sets up SMASH power */
	SMASHcount = 1;
	/** Set up rounds */
	rounds = 5;
	rString = "Round";
	ROUND = new QGraphicsSimpleTextItem;
	ROUND->setText(rString);
	ROUND->setPos(WINDOW_MAX_X/2-20, -62);
	rString.setNum(rounds);
	rNum = new QGraphicsSimpleTextItem;
	rNum->setText(rString);// add a string here
	rNum->setPos(WINDOW_MAX_X/2, -45);
	
	/** Set up score */
	// WINDOW_MAX_X/2-200, WINDOW_MAX_Y/3-20, this, scene
	score = new Score(WINDOW_MAX_X/2 - 70, -30, this, scene, player);
	score->updateScore();
	score->setBrush(Qt::NoBrush);
	score->setPen(Qt::NoPen);
	
	/** Set up the arrow count display */
	arrowStr.setNum(player->getArrows());
	arrowText = new QGraphicsSimpleTextItem;
	arrowText->setText(arrowStr);
	arrowText->setPos(125, -43);
	
	
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
	seconds = 1;

	/** Initialize the health bar */
	health = new HealthBar(-25, -42, 140, 16, 0, 0, player->getHealth());
	health->setBrush(red);
	health->setPen(Qt::NoPen);
	healthOutline = new GameObject(health->getX(), health->getY(), health->getWidth(), 16, 0, 0);
	healthOutline->setBrush(Qt::NoBrush);
	
	/** Initialize and set up the enemies */
	enemyIMG = new QPixmap("enemy_0.png", "png", Qt::AutoColor);
	enemy = NULL;
	killCount = 0;
	enemyLimit = 5;
	enemySpawnRate = 0.0;
	enemySpeed = 0.0;
	gameTimer = 0;
	
	/** Create an image for the BasicBullet */
	bbIMG = new QPixmap("basic_bullet.png", "png", Qt::AutoColor);
	bullet = NULL;
	/** Set up arrow object */
	arrowIMG = new QPixmap("arrow.png", "png", Qt::AutoColor);
	arrow = NULL;
	
	arrowCount = new ArrowCount(arrowIMG, 140, -56, scene);
	
	/** Add items to the scene */
	scene->addItem(area);
	scene->addItem(player); objects.push_back(player);
	scene->addItem(q1);
	scene->addItem(q2);
	scene->addItem(q3);
	scene->addItem(q4);
	scene->addItem(health);
	scene->addItem(arrowText);
	scene->addItem(healthOutline);
	scene->addItem(ROUND);
	scene->addItem(rNum);
	scene->addItem(score);
	scene->addItem(SMASH);
	scene->addWidget(pause);
	
	c1 = NULL;
	t1 = NULL;
	
	/** Game Events, or connections */
	connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));
	connect(pause, SIGNAL(clicked()), this, SLOT(pauseGame()));
	connect(resume, SIGNAL(clicked()), this, SLOT(resumeGame()));
	/** For restarting the game */
	connect(restart, SIGNAL(clicked()), this, SLOT(restartGame()));
	/** Quits the application */
	connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
	/** Connection to restart the application */
	connect( actionReboot, SIGNAL( triggered() ),this, SLOT( restartGame() ) );
	/** Connects death signal and slot */
	connect(this, SIGNAL(death()), this, SLOT(handleDeath()));
}

void MainWindow::movePlayer(std::string dir)
{
//	cout << "player pos " << player->getX() << ", " << player->getY() << endl;
	if(dir == "up")
		player->setDir(0);
	else if(dir == "down")
		player->setDir(1);
	else if(dir == "left")
		player->setDir(2);
	else if(dir == "right")
		player->setDir(3);
	else
		player->setDir(-1);
}

void MainWindow::show() {
//	timer->start();
//	view->show();
	gameplay->show();
	begin->show();
}

MainWindow::~MainWindow()
{
	timer->stop();
}
