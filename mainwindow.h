#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>

#include "game_object.h"

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
	GameObject *test;	

public slots:
	void handleTimer();
	void toggleTimer();
};

#endif // MAINWINDOW_H
