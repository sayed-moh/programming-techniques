#ifndef CRHOMB_H
#define CRHOMB_H

#include "Figures/CFigure.h"

class CRhombus : public CFigure
{
private:
	Point Center;
public:
	CRhombus(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool IsInFigure(int X, int Y);
};

#endif
