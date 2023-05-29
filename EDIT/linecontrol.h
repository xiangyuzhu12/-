#ifndef LINECONTROL_H
#define LINECONTROL_H

#include <QMainWindow>
#include <QWidget>
#include "line.h"
#include "point.h"
#include "figurecontrol.h"
#include <vector>
using namespace std;

class LineControl:public FigureControl
{
public:
    LineControl();
    LineControl(std::vector<Figure*> *figures);
    LineControl(int width, int height);
    LineControl(std::vector<Figure*> *figures, int width, int height);
    bool setFocus(Figure *fg);

    void onMousePressEvent(QMouseEvent *event);
    void onMouseMoveEvent(QMouseEvent *event);
    void onKeyPressEvent(QKeyEvent *event);

    void onDraw();
    void onMarkDraw(); //绘制当前聚焦的直线的额外标记
    void onCut(const Point &leftDown, int width, int height); //只对当前直线进行裁剪
    void onScale(double s);
    void onDelete();
    void onClear();

    const vector<Line*> &getLines();

private:
    enum SetLP{SETBEGIN, SETEND, SETCENTER, SETHANDLE} setLP; //目前更改的是起点/终点
    Line *curLine; //当前聚焦的直线
    vector<Line*> lines; //注意：删除直线时需要同时删除lines和allFigures中的直线
};

#endif // LINECONTROL_H
