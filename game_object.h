#ifndef game_object_H
#define game_object_H

#include <QGraphicsRectItem>

/**
* Unlike AbstractObject, this class inherits a QGraphicsRectItem and 
* is used for click detection since it is more reliable.
*/

class GameObject : public QGraphicsRectItem
{
	public:
		GameObject(double nx, double ny, double w, double h, int vx, int vy);
    void setX(int x);
    void setY(int y);
    void setVelX(int vx);
    void setVelY(int vy);
    void setRot(int r);
    void setWidth(int w);
    void setHeight(int h);
    void setSize(int w, int h);
    void setRight(bool b);
    void setLeft(bool b);
    void setUp(bool b);
    void setDown(bool b);
    int getX();
    int getY();
    int getWidth();
    int getHeight();
    int getVelX();
    int getVelY();
    bool getRight();
    bool getLeft();
    bool getUp();
    bool getDown();
    int getRot();
    /** Object will rotate towards @param x, @param y */
    void face(int sx, int sy);
    void move(int windowMaxX, int windowMaxY);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void draw();
//    bool contains(const QPointF &point) const;
	
	protected:
    int x;
    int y;
    int width;
    int height;
    int velX;
    int velY;
    /** These 4 boolean variables tell if the object is in motion or not */
    bool transRight;
    bool transLeft;
    bool transUp;
    bool transDown;
    /** Stores the rotation */
    int rot;
};

#endif
