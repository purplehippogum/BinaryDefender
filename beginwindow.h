#ifndef BEGINWINDOW_H
#define BEGINWINDOW_H

#include <QApplication>
#include <QWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QString>

/**
* This class represents a welcome window that displays when the game first starts up.
*/

class MainWindow;

class BeginWindow : public QWidget
{
	public:
		BeginWindow(MainWindow *window, int x, int y);
		QString getString();
		
	private:
		MainWindow *main;
		QVBoxLayout *vlayout;
		QHBoxLayout *hlayout;
		QFormLayout *entry;
		QLineEdit *edit;
		QString string;
		QPushButton *start;
		QPushButton *quit;
};

#endif
