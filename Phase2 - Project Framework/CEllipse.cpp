#include "CEllipse.h"

CEllipse::CEllipse(Point P, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P;
}


void CEllipse::Draw(Output* pOut) const
{
	//Call Output::DrawEllip to draw a ellipse on the screen	
	pOut->DrawEllip(Center, FigGfxInfo, Selected);
}
bool CEllipse::IsInFigure(int X, int Y)
{
	int x1 = Center.x;
	int y1 = Center.y;
	if ((x1 - X)*(x1 - X) * 3600 + (y1 - Y)*(y1 - Y) * 10000 <= 10000 * 3600)
	{
		return true;
	}
	return false;
}