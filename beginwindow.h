#ifndef BEGINWINDOW_H
#define BEGINWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QLayout>

class BeginWindow : public QWidget
{
	public:
		BeginWindow(int x, int y);
		
	private:
		QLayout *layout;
		QLineEdit *edit;
};

#endif
