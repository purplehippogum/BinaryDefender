#include "beginwindow.h"
#include "mainwindow.h"

BeginWindow::BeginWindow(MainWindow *window, int x, int y)
{
	main = window;

  setFixedSize(400, 80);
  setWindowTitle("Welcome to Binary Defender");

	move(x,y);
	vlayout = new QVBoxLayout;
	setLayout(vlayout);
  edit = new QLineEdit(this);
  entry = new QFormLayout;
  entry->addRow("Enter your name:", edit);
  vlayout->addLayout(entry);
  
  hlayout = new QHBoxLayout;
  start = new QPushButton("Start Game");
//  start->setEnabled(false);
  quit = new QPushButton("Quit Game");
  hlayout->addWidget(start);
  hlayout->addWidget(quit);
  
  vlayout->addLayout(hlayout);
  
  /**Connect signals to @param window */
	connect(start, SIGNAL(clicked()), main, SLOT(resumeGame()));
	connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
	
	/** Close the window */
	connect(start, SIGNAL(clicked()), this, SLOT(close()));
	connect(quit, SIGNAL(clicked()), this, SLOT(close()));	
}

QString BeginWindow::getString()
{
	string = edit->text();
	return string;
}
