#ifndef CLINE_H
#define CLINE_H

#include "Figures/CFigure.h" 

class CLine : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
public:
	CLine(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool IsInFigure(int X, int Y);
};

#endif