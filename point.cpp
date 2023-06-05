#include "point.h"
#include <cmath>
#include <GL/glu.h>
#include <iostream>
using namespace std;

Point::Point()
{

}

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}

Point::~Point()
{
}

int Point::getX() const
{
    return x;
}

int Point::getY() const
{
    return y;
}

double Point::distanceTo(const Point &p) const
{
    //return abs(this->x - p.x) + abs(this->y - p.y);
    return sqrt((this->x - p.x)*(this->x - p.x) + (this->y - p.y)*(this->y - p.y));
}

void Point::draw()
{
    glVertex2i(x, y);
}

void Point::markDraw()
{
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0);
    int n = 100; //绘制100个点
    GLfloat R = 5.0f; //圆的半径
    GLfloat pi = 3.1415926536f;
    for(int i=0;i<n;i++)
        glVertex2f(x+R*cos(2*pi/n*i), y+R*sin(2*pi/n*i));
    glEnd();
    glFlush();
}

void Point::centerMarkDraw()
{
    glColor3f(0.0, 0.0, 1.0);
    //绘制十字
    glBegin(GL_LINES);
    glVertex2i(x-10, y);
    glVertex2i(x+10, y);
    glVertex2i(x, y-10);
    glVertex2i(x, y+10);
    glEnd();
    //绘制圆点
    glBegin(GL_POLYGON);
    int n = 100; //绘制100个点
    GLfloat R = 5.0f; //圆的半径
    GLfloat pi = 3.1415926536f;
    for(int i=0;i<n;i++)
        glVertex2f(x+R*cos(2*pi/n*i), y+R*sin(2*pi/n*i));
    glEnd();
    glFlush();
}

void Point::handleDraw(const Point &p)
{
    glColor3f(0.0, 0.0, 1.0); //蓝色
    //绘制连线
    glBegin(GL_LINES);
    glVertex2i(x, y);
    glVertex2i(p.x, p.y);
    glEnd();
    //绘制圆点
    glBegin(GL_POLYGON);
    int n = 100; //绘制100个点
    GLfloat R = 5.0f; //圆的半径
    GLfloat pi = 3.1415926536f;
    for(int i=0;i<n;i++)
        glVertex2f(x+R*cos(2*pi/n*i), y+R*sin(2*pi/n*i));
    glEnd();
    glFlush();
}

//void Point::clear()
//{
//}

void Point::setPoint(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Point::setHandlePoint(const Point &begin, const Point &end, int h)
{
    Point center((begin.getX()+end.getX())/2, (begin.getY()+end.getY())/2);
    if(begin.getX()==end.getX())
        setPoint(center.getX(), center.getY()+h);
    else
    {
        double k = (double)(end.getY()-begin.getY())/(double)(end.getX()-begin.getX());
        setPoint(int(center.getX()-h*k/sqrt(k*k+1)+0.5), int(center.getY()+h/sqrt(k*k+1)+0.5));
    }
}

void Point::translate(const Point &offset)
{
    this->x += offset.x;
    this->y += offset.y;
}

void Point::rotate(const Point &ctr, double angle)
{
    angle = angle * 3.14159265 / 180;
    int nx = int(ctr.x + (x-ctr.x)*cos(angle) - (y-ctr.y)*sin(angle) + 0.5);
    int ny = int(ctr.y + (x-ctr.x)*sin(angle) + (y-ctr.y)*cos(angle) + 0.5);
    x = nx, y = ny;
}

void Point::scale(const Point &base, double sx, double sy)
{
    x = x*sx + base.x*(1-sx);
    y = y*sy + base.y*(1-sy);
}

void Point::rotateToParallel(const Point &base, const Point &ref, double dist)
{
    if(base==ref)
        return;
    double c = ref.getX() - base.getX(), d = ref.getY() - base.getY(); //现向量base->ref
    double rRef = base.distanceTo(ref); //center->ref向量的长度
    x = int(base.x+dist*c/rRef+0.5);
    y = int(base.y+dist*d/rRef+0.5);
}

void Point::rotateToPerpendicularUp(const Point &base, const Point &ref, double dist)
{
    if(base==ref) //base=ref则不变
        return;
    if(ref.getY()==base.getY())
        this->setPoint(base.getX(), base.getY()+dist);
    else
    {
        double c = ref.getX() - base.getX(), d = ref.getY() - base.getY(); //现向量center->ref
        double rRef = base.distanceTo(ref);//center->ref向量的长度
        double tmp = -abs(dist*d/rRef); //此处rRef!=0
        x = base.x + int(tmp+0.5);
        y = base.y + int(-c/d*tmp+0.5); //此处d!=0
    }
}

void Point::rotateToPerpendicularDown(const Point &base, const Point &ref, double dist)
{
    if(base==ref)
        return;
    if(ref.getY()==base.getY())
        this->setPoint(base.getX(), base.getY()-dist);
    else
    {
        double c = ref.getX() - base.getX(), d = ref.getY() - base.getY(); //现向量center->ref
        double rRef = base.distanceTo(ref);//center->ref向量的长度
        double tmp = abs(dist*d/rRef); //此处rRef!=0
        x = base.x + int(tmp+0.5);
        y = base.y + int(-c/d*tmp+0.5); //此处d!=0
    }
}

// 从上到下，从左到右增大
bool Point::operator<(const Point & p) const
{
    return this->y>p.y || (this->y==p.y && this->x<p.x);
}

bool Point::operator==(const Point & p) const
{
    return this->x==p.x && this->y==p.y;
}

Point Point::operator-(const Point &p) const
{
    return Point(x-p.x, y-p.y);
}

Point Point::operator+(const Point &p) const
{
    return Point(x+p.x, y+p.y);
}

ostream & operator<<(ostream & out, const Point & p)
{
    out << '(' << p.getX() << ',' << p.getY() << ')';
    return out;
}
