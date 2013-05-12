#include <QtGui/QApplication>
#include "mainwindow.h"

/** @mainpage
* Copyright 2013 Zach Vega-Perkins
* This program is distributed under the terms of the GNU General Public License

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

/**
* Main simply creates a new Qt application and runs it until
* the player manually quits. Otherwise, the program will
* restart
*/

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
