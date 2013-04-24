#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QString>
#include <QGraphicsSimpleTextItem>
#include <QGraphicsPixmapItem>

#include "game_object.h"
#include "abstract_object.h"

#define WINDOW_MAX_X 640
#define WINDOW_MAX_Y 480

class MainWindow : public QWidget {
    Q_OBJECT
    
public:
    explicit MainWindow();
    ~MainWindow();
    /** Displays the window with all of the objects within */
    void show();
    
private:
	/** Stores the view */
	QGraphicsScene *scene;
	/** Displays all of the game object */
	QGraphicsView *view;
	/** is essentially the 'framerate' for the level */
	QTimer *timer;
//	GameObject *test;
	AbstractObject * test;
	QPoint p;
	QPixmap *player;
  QString txt;
  QGraphicsSimpleTextItem *item;

public slots:
	/** Handles object movement when timer gets set off */
	void handleTimer();
	/** Used to pause the game */
	void toggleTimer();
	/** Handles shooting after the player clicks */
	void shoot();
};

#endif // MAINWINDOW_H
