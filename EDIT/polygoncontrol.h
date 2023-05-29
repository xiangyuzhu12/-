#ifndef POLYGONCONTROL_H
#define POLYGONCONTROL_H

#include <QMainWindow>
#include <QWidget>
#include "polygon.h"
#include "linecontrol.h"
#include "figurecontrol.h"
#include <vector>
using namespace std;

class PolygonControl:public FigureControl
{
public:
    PolygonControl();
    PolygonControl(std::vector<Figure*> *figures);
    PolygonControl(int width, int height);
    bool setFocus(Figure *fg);

    void onMousePressEvent(QMouseEvent *event);
    void onMouseMoveEvent(QMouseEvent *event);
    void onMousePassiveMoveEvent(QMouseEvent *event);
    void onKeyPressEvent(QKeyEvent *event);

    void onDraw();
    void onMarkDraw();
    void onFill();

    void onCut(const Point &leftDown, int width, int height); //对当前多边形进行裁剪
    void onScale(double s);
    void onDelete();
    void onClear();

private:
    int setPV; //当前正在更改的顶点索引，默认为-1表示正在绘制直线，-2表示正在选中中心点进行平移，-3表示正在拖动handle旋转
    int curIdx; //当前图形的索引
    vector<Line*> curLines; //当前聚焦的折线
    vector<MPolygon*> polygons;

    void deletePolygon(int idx); //删除特定索引的Polygon
};

#endif // POLYGONCONTROL_H
