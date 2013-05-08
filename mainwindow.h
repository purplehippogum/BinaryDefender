#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QFont>
#include <QAction>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPushButton>
#include <QMessageBox>
#include <QTimer>
#include <QString>
#include <QGraphicsSimpleTextItem>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <QBoxLayout>
#include <QErrorMessage>

#include "beginwindow.h"
#include "player.h"
#include "basic_bullet.h"
#include "arrow_bullet.h"
#include "enemy.h"
#include "play_area.h"
#include "score.h"
#include "gameplay.h"
#include "game_object.h"
#include "health_bar.h"
#include "arrowcount.h"
#include "high_score_table.h"
#include "heart.h"

#define WINDOW_MAX_X 640
#define WINDOW_MAX_Y 480
#define EXIT_CODE_REBOOT -123456789

/** 
* Houses all main gameplay and events.
*/

class PlayArea;
class Gameplay;
class Score;
class BeginWindow;
class HighScoreTable;

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
	void SMASHWalls();
	/** Moves the player */
	void movePlayer(std::string dir);
	void setName(QString n);
    
private:
	/** Checks for @param obj collision with walls */
	bool checkCollision(AbstractObject *obj);
	/** @return true if @param p is in a wall */
	bool checkPlace(QPointF p);
	/** Pushes @param obj out of object */
	void pushOut(AbstractObject *obj, int dir);
	/** Sets up the geometry for level 2 */
	void buildLevelTwo();
	
	QVBoxLayout *layout;

	/** Stores the high scores from the text file */
	std::vector<int> highScores;
	std::vector<QString> highScoreNames;
	HighScoreTable *highScoreTable;

	/** Declare a begin window */
	BeginWindow *begin;
	/** Action to handle restartGame() slot */
	QAction *actionReboot;
	/** Stores the scene */
	QGraphicsScene *scene;
	/** Displays all of the game objects */
	QGraphicsView *_view;
	/** Handles key presses */
	Gameplay *gameplay;
	/** Pauses the game */
	QPushButton *pause;
	QPushButton *resume;
	QPushButton *restart;
	QPushButton *quit;
	/** Designates a play area to detect mouse presses */
	PlayArea *area;
	/** Button that pauses the game and brings up the menu */
	
	/** Keeps track of game time */
	double gameTimer;
	int seconds;
	/** Keeps track of level count */
	int level;
	/** Keeps track of how many SMASH powers the player has */
	int SMASHcount;
	/** Displays the SMASH image */
	QGraphicsPixmapItem *SMASH;
	QPixmap *SMASHIMG;
	QPixmap *blank;
	/** Score object */
	Score *score;
	
	/** Basic level walls */
	GameObject *q1;
	GameObject *q2;
	GameObject *q3;
	GameObject *q4;
	/** Level 2 walls */
	GameObject *t1;
	GameObject *b1;
	GameObject *c1;
	/** Stores the objects in the scene */
	std::vector<AbstractObject*> objects;
	/** is essentially the 'framerate' for the level */
	QTimer *timer;
	/** Main Player object */
	Player *player;
	/** Stores player name */
	QString name;
	/** Displays the player name */
	QGraphicsSimpleTextItem *nameDisp;
	/** Player health */
	HealthBar *health;
	GameObject *healthOutline;
	/** Heart object */
	Heart *heart;
	bool heartCreated;
	
	/** Numerical Arrow count display */
	QString arrowStr;
	QGraphicsSimpleTextItem *arrowText;
	/** Gaphical Arrow count display */
	ArrowCount *arrowCount;
	
	/** Enemy letter objects */
	Enemy *enemy;
	QPixmap *enemyIMG;
	std::vector<Enemy*> enemies;
	/** This is how many enemies have been killed */
	int killCount;
	/** This is how many enemies must be killed to advance the round */
	int enemyLimit;
	/** Controls the speed at which the enemies move */
	double enemySpeed;
	double enemySpawnRate;
	/** Keeps track of rounds */
	int rounds;
	/** Displays round count */
	QString rString;
	QGraphicsSimpleTextItem *ROUND;
	QGraphicsSimpleTextItem *rNum;
	
	/** The three different bullet objects */
	BasicBullet *bullet;
	ArrowBullet *arrow;
//	Bomb *bomb;
	std::vector<BasicBullet*>	bullets;
	
	/** Stores the mouse position */
	QPoint p;
	QPoint valid;
	
	/** Store game object images */
	QPixmap *playerIMG;
	QPixmap *bbIMG;
	QPixmap *arrowIMG;
	QPixmap *heartIMG;
	
public slots:
	/** Handles object movement when timer gets set off */
	void handleTimer();
	/** Used to pause the game */
	void pauseGame();
	/** Resumes the game */
	void resumeGame();
	/** Restarts the game */
	void restartGame();
	/** Triggered on player death */
	void handleDeath();
	
signals:
	void death();
};

#endif // MAINWINDOW_H
