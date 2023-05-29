#ifndef CIRCLECONTROL_H
#define CIRCLECONTROL_H

#include <QMainWindow>
#include <QWidget>
#include "circle.h"
#include "figurecontrol.h"
#include <vector>
using namespace std;

class CircleControl:public FigureControl
{
public:
    CircleControl();
    CircleControl(std::vector<Figure*> *figures);
    CircleControl(int width, int height);
    bool setFocus(Figure *fg);

    void onMousePressEvent(QMouseEvent *event);
    void onMouseMoveEvent(QMouseEvent *event);
    void onKeyPressEvent(QKeyEvent *event);

    void onDraw();
    void onMarkDraw();
    void onFill();

    void onScale(double s);
    void onDelete();
    void onClear();

private:
    enum SetCP{CIRCLEPOINT, MARKPOINT, CENTERPOINT, HANDLEPOINT}setCP; //当前点击的点为圆上的点/标记点/圆心
    Circle *curCircle; //当前聚焦的圆
    vector<Circle*> circles;
};

#endif // CIRCLECONTROL_H
