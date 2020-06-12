#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
    virtual void ChngDrawClr(color Dclr);
	Point getC1()const;
	Point getC2()const;
	virtual bool IsInFigure(int X, int Y);
};

#endif