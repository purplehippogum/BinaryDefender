#ifndef game_object_H
#define game_object_H

#include <QGraphicsRectItem>

class GameObject : public QGraphicsRectItem
{
	public:
		GameObject(double nx, double ny, double w, double h, int vx, int vy);
    void setX(int x);
    void setY(int y);
    void setVelX(int vx);
    void setVelY(int vy);
    void setRot(int r);
    int getX();
    int getY();
    int getWidth();
    int getHeight();
    int getVelX();
    int getVelY();
    int getRot();
    void move(int windowMaxX, int windowMaxY);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void draw();
	
	protected:
    int x;
    int y;
    int width;
    int height;
    int velX;
    int velY;
    /** Stores the rotation */
    int rot;
};

#endif
