#ifndef COMFIGURE_H
#define COMFIGURE_H

#include <QMainWindow>
#include <QWidget>
#include "figure.h"
#include <vector>

class ComFigure
{
public:
    ComFigure();
    ComFigure(const std::vector<Figure*> &initFigures);
    ~ComFigure();
    virtual void draw();
    virtual void clear();

protected:
    std::vector<Figure*> figures;
};

#endif // COMFIGURE_H
