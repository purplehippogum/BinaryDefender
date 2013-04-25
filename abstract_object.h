#ifndef ABSTRACT_OBJECT_H
#define ABSTRACT_OBJECT_H

#include <QGraphicsPixmapItem>
#include <QTransform>
#include <QPixmap>

class AbstractObject : public QGraphicsPixmapItem
{
	public:
		AbstractObject(QPixmap *pm, double nx, double ny, double w, double h, int hp);
    virtual void setX(int x);
    virtual void setY(int y);
    virtual void setVelX(int vx);
    virtual void setVelY(int vy);
    virtual void setHealth(int h);
    virtual void setRot(int r);
    int getX();
    int getY();
    int getWidth();
    int getHeight();
    int getVelX();
    int getVelY();
    int getHealth();
    int getRot();
    /** Object will rotate towards @param x, @param y */
    virtual void face(int sx, int sy);
    virtual void move(int windowMaxX, int windowMaxY);
    virtual void moveUp(double s);
    virtual void moveDown(double s);
    virtual void moveLeft(double s);
    virtual void moveRight(double s);
	
	protected:
    int x;
    int y;
    int width;
    int height;
    int velX;
    int velY;
    int health;
    /** Stores the rotation */
    int rot;
    QPixmap *pixMap;
    QTransform rotate;
};

#endif
