#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
	int currentExitCode = 0;
	
	do{
		QApplication game(argc, argv);
		MainWindow w;
		w.show();
		currentExitCode = game.exec();
		
	}while(currentExitCode == EXIT_CODE_REBOOT);

	return currentExitCode;
}
