#ifndef ELLIPSECONTROL_H
#define ELLIPSECONTROL_H

#include <QMainWindow>
#include <QWidget>
#include "ellipse.h"
#include "figurecontrol.h"
#include <vector>
using namespace std;

class EllipseControl:public FigureControl

{
public:
    EllipseControl();
    EllipseControl(std::vector<Figure*> *figures);
    EllipseControl(int width, int height);
    bool setFocus(Figure *fg);

    void onMousePressEvent(QMouseEvent *event);
    void onMouseMoveEvent(QMouseEvent *event);
    void onKeyPressEvent(QKeyEvent *event);

    void onDraw();
    void onMarkDraw();

    void onScale(double s);
    void onDelete();
    void onClear();

private:
    enum SetEP{ENDPOINT, MARKPOINT, CENTERPOINT, HANDLEPOINT}setEP; //当前点击的点为终点/标记点
    MEllipse *curEllipse; //当前正在绘制的椭圆
    vector<MEllipse*> ellipses; //绘制好的椭圆
};

#endif // ELLIPSECONTROL_H
