#include "high_score_table.h"
#include "mainwindow.h"

#include <iostream>
#include <QDebug>

using namespace std;

HighScoreTable::HighScoreTable(MainWindow *window, int x, int y, std::vector<int> &s, std::vector<QString> &n)
{
	main = window;

  setFixedSize(200, 300);
  setWindowTitle("High Scores");
  scores = s;
  names = n;
	table = new QHBoxLayout;
	table->setAlignment(Qt::AlignTop);
  setLayout(table);
  
  nameColumn = new QVBoxLayout;
  scoreColumn = new QVBoxLayout;
  scoreColumn->setAlignment(Qt::AlignRight);
  
  for(unsigned int i = 0; i < names.size(); i++){
		name = new QLabel;//(nameColumn);
		nameRow = new QHBoxLayout;
		QString tmp;
		tmp.setNum(i+1);
		tmp.append(". ");
		tmp.append(names[i]);
		name->setText(tmp);
		nameRow->addWidget(name);
		nameColumn->addLayout(nameRow);
  }
  for(unsigned int i = 0; i < scores.size(); i++){
  	score = new QLabel;
  	scoreRow = new QHBoxLayout;
  	score->setNum(scores[i]);
  	scoreRow->addWidget(score);
  	scoreColumn->addLayout(scoreRow);
  }

	table->addLayout(nameColumn);
	table->addLayout(scoreColumn);
	move(x,y);
}
