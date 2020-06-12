#ifndef CELLIP_H
#define CELLIP_H

#include "Figures/CFigure.h"

class CEllipse : public CFigure
{
private:
	Point Center;
public:
	CEllipse(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool IsInFigure(int X, int Y);
};

#endif