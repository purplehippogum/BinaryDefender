#ifndef HIGH_SCORE_TABLE_H
#define HIGH_SCORE_TABLE_H

#include <QWidget>
#include <QString>
#include <QLabel>
#include <QBoxLayout>
#include <string>

class MainWindow;

class HighScoreTable : public QWidget
{
	public:
		HighScoreTable(MainWindow *window, int x, int y, std::vector<int> &s, std::vector<QString> &n);
		MainWindow *main;
	
	private:
		std::vector<int> scores;
		std::vector<QString> names;
		QHBoxLayout *table;
		QVBoxLayout *nameColumn;
		QHBoxLayout *nameRow;
		QLabel *name;
		QVBoxLayout *scoreColumn;
		QHBoxLayout *scoreRow;
		QLabel *score;
};

#endif
