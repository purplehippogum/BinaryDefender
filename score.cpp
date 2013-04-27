#include "score.h"
#include "mainwindow.h"

Score::Score(int nx, int ny, MainWindow *main, QGraphicsScene *sc) : QGraphicsRectItem(nx, ny, 150, 30)
{
	window = main;
	scene = sc;
//	digits[0] = NULL;
//	digit = NULL;
	this->setBrush(Qt::NoBrush);
	width = 150;
	height = 30;
	x = nx;
	y = ny;
	this->setTransformOriginPoint (x + width/2.0, y + height/2.0);
	zeroIMG = new QPixmap("zero.png", "png", Qt::AutoColor);
//	zero->setPixmap(*zeroIMG);
	oneIMG = new QPixmap("one.png", "png", Qt::AutoColor);
//	one->setPixmap(*oneIMG);
	this->setPos(nx, ny);
	points = 0;
	s = "Score";
	scoreDisplay = new QGraphicsSimpleTextItem(this);
	scoreDisplay->setText(s);
	scoreDisplay->setPos(x-50, y+5);
	scoreDisplay->show();
	/** Use the string to store the actual score value */
	s.setNum(points);
	pointDisplay = new QGraphicsSimpleTextItem(this);
	pointDisplay->setText(s);
	pointDisplay->setPos(x, y-15);
	pointDisplay->show();
}

void Score::updateScore()
{
	s.setNum(points);
	binary();
	pointDisplay->setText(s);

	for(unsigned int i = 0; i < digits.size(); i++){
		if(digits[i] != NULL){
			delete digits[i];
			digits.erase(std::find(digits.begin(), digits.end(), digits[i]));
		}
	}
	
	for(int i = 0; i < s.length(); i++){
		if(s[i] == '1'){
			digit = new AbstractObject(oneIMG, i*12 + x+116, y+145, 16, 16, -1);
			digit->show();
			scene->addItem(digit);
			digit->setBin(true);
			digits.push_back(digit);
		}
		else{
			digit = new AbstractObject(zeroIMG, i*12 + x+116, y+145, 16, 16, -1);
			digit->setBin(false);
			digit->show();
			scene->addItem(digit);
			digits.push_back(digit);
		}
	}
	for(unsigned int i = 0; i < digits.size(); i++){
		if(digits[i] != NULL){
			delete digits[i];
			digits.erase(std::find(digits.begin(), digits.end(), digits[i]));
		}
	}
}

QString Score::toBinary(int num, bool rev)
{
    QString s;  
    while(num != 0)
    {
       s += (num & 1) ? '1' : '0';
       num >>= 1;
    }

    if(!rev)        
        std::reverse(s.begin(),s.end());

    return s;
}

void Score::binary()
{
	bool b = false;
	s = toBinary(points, b);
}

void Score::setPoints(int p)
{
	points = p;
}

void Score::addPoints(int p)
{
 points += p;
}

int Score::getPoints()
{
	return points;
}
