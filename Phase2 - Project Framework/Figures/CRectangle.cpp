#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
Point CRectangle::getC1()const { return Corner1; }
Point CRectangle::getC2()const { return Corner2; }
void CRectangle:: ChngDrawClr(color Dclr)
{
	FigGfxInfo.DrawClr = BLACK;
}

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}
bool CRectangle::IsInFigure(int X, int Y) {
	int maxx;
	int maxy;
	int minx;
	int miny;
	if (Corner1.x > Corner2.x)
	{
		maxx = Corner1.x;
		minx = Corner2.x;
	}
	else
	{
		maxx = Corner2.x;
		minx = Corner1.x;
	}
	if (Corner1.y > Corner2.y) {
		maxy = Corner1.y;
		miny = Corner2.y;
	}
	else
	{
		maxy = Corner2.y;
		miny = Corner1.y;
	}
	if (X > minx && X<maxx && Y>miny && Y < maxy)
		return true;
	/*if (Corner1.x > Corner2.x && Corner1.y > Corner2.y)
	{
		if (X > Corner2.x && X < Corner1.x && Y > Corner2.y && Y < Corner1.y)
			return true;
	}
	else if (Corner1.x > Corner2.x && Corner1.y < Corner2.y) {
		if (Corner1.x > Corner2.x && Corner1.y > Corner2.y)
		{
			if (X > Corner2.x && X < Corner1.x && Y < Corner2.y && Y > Corner1.y)
				return true;
		}
	}
	else if (Corner1.x < Corner2.x && Corner1.y > Corner2.y) {
		if (Corner1.x > Corner2.x && Corner1.y > Corner2.y)
		{
			if (X < Corner2.x && X > Corner1.x && Y > Corner2.y && Y < Corner1.y)
				return true;
		}
	}
	else if (Corner1.x < Corner2.x && Corner1.y < Corner2.y) {
		if (Corner1.x > Corner2.x && Corner1.y > Corner2.y)
		{
			if (X < Corner2.x && X > Corner1.x && Y < Corner2.y && Y > Corner1.y)
				return true;
		}
		else if (Corner1.x < Corner2.x && Corner1.y < Corner2.y) {
			if (Corner1.x > Corner2.x && Corner1.y > Corner2.y)
			{
				if (X < Corner2.x && X > Corner1.x && Y < Corner2.y && Y > Corner1.y)
					return true;
			}
		}
	}*/
	return false;
}