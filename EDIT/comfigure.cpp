#include "comfigure.h"

ComFigure::ComFigure()
{

}

ComFigure::ComFigure(const std::vector<Figure*>& initFigures):figures(initFigures)
{
}

ComFigure::~ComFigure()
{
    clear();
}

void ComFigure::draw()
{
    for (auto it : figures)
        it->draw();
}

void ComFigure::clear()
{
    for (auto it : figures)
        it->clear();
}
