#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QString>
#include <QGraphicsSimpleTextItem>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <vector>

#include "player.h"
#include "basic_bullet.h"
#include "enemy.h"
#include "play_area.h"
#include "game_object.h"
#include "health_bar.h"

#define WINDOW_MAX_X 640
#define WINDOW_MAX_Y 480

class PlayArea;

class MainWindow : public QWidget {
    Q_OBJECT
    
public:
	explicit MainWindow();
	~MainWindow();
	/** Displays the window with all of the objects within */
	void show();
	/** Handles shooting after the player clicks */
	void shoot();
	/** Smashes two walls together, destroying all of the enemies in the way */
	void SMASH();
    
private:
	/** Stores the view */
	QGraphicsScene *scene;
	/** Displays all of the game object */
	QGraphicsView *view;
	/** Designates a play area to detect mouse presses */
	PlayArea *area;
	/** Keepts track of game time */
	int gameTimer;
	int seconds;
	/** Keeps track of how many SMASH powers the player has */
	int SMASHcount;
	/** Score */
	int score;
	/** Rectangle that the enemies will travel on */
	GameObject *q1;
	GameObject *q2;
	GameObject *q3;
	GameObject *q4;
	/** Stores the objects in the scene */
	std::vector<AbstractObject*> objects;
	/** is essentially the 'framerate' for the level */
	QTimer *timer;
	/** Main Player object */
	Player *player;
	/** Player health */
	HealthBar *health;
	GameObject *healthOutline;
	
	/** Enemy letter objects */
	Enemy *enemy;
	QPixmap *enemyIMG;
	std::vector<Enemy*> enemies;
	/** This is how many enemies have been killed */
	int killCount;
	/** This is how many enemies must be killed to advance the round */
	int enemyLimit;
	/** Keeps track of rounds */
	int rounds;
	/** Displays round count */
	QString rString;
	QGraphicsSimpleTextItem *ROUND;
	QGraphicsSimpleTextItem *rNum;
	
	/** A simple bullet object */
	BasicBullet *bullet;
	std::vector<BasicBullet*>	bullets;
	
	/** Stores the mouse position */
	QPoint p;
	QPoint valid;
	
	/** Store game object images */
	QPixmap *playerIMG;
	QPixmap *bbIMG;
	
public slots:
	/** Handles object movement when timer gets set off */
	void handleTimer();
	/** Used to pause the game */
	void toggleTimer();
};

#endif // MAINWINDOW_H
