#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QtOpenGL/QtOpenGL>
#include <GL/glu.h>
#include <QMouseEvent>
#include <vector>
#include <QGLWidget>
#include "linecontrol.h"
#include "circlecontrol.h"
#include "ellipsecontrol.h"
#include "polygoncontrol.h"
#include "curvecontrol.h"
#include "cutwindow.h"
#include "linecontrol.h"

enum Mode{LINE=0, CIRCLE, ELLIPSE, POLYGON, CURVE};
enum Edit{DRAW=0, FILL, CUT};

class GLWIDGET:public QGLWidget
{
    Q_OBJECT
public:
    explicit GLWIDGET(QWidget *parent, Mode m);
    ~GLWIDGET();

    virtual void setMode(Mode m);
    virtual void setEditMode(Edit e);

    virtual void onScalePlusFigures(); //放大所有图形
    virtual void onScaleMinusFigures(); //缩小所有图形
    virtual void onCutFigures(); //裁剪cw可以裁剪的所有图形
    virtual void onFillFigures(); //填充当前图形
    virtual void onSave(string fileName); //保存到文件
    virtual void onDelete(); //删除当前被选中的图形
    virtual void onClear(); //清空图层

signals:
    void changeMode(Mode m); //更新绘图状态

protected:
    virtual void initializeGL();
    virtual void resizeGL(int w, int h);
    virtual void paintGL();
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void keyPressEvent(QKeyEvent *event);

private:
    int curCtrl; //当前FigureControl的索引
    int curEdit; //当前编辑状态
    CutWindow *cw; //裁剪窗口
    vector<FigureControl*> figureControls;
    vector<Figure*> allFigures; //本画布中的所有图形

    Figure *setFocusByPoint(const Point &p); //根据点击的点来设置curCtrl和对应FigureControl的curFigure
};

#endif // GLWIDGET_H
