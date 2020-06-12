#include "CLine.h"

CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}


void CLine::Draw(Output* pOut) const
{
	//Call Output::DrawLine to draw a line on the screen	
	pOut->DrawLine(Corner1, Corner2, FigGfxInfo, Selected);
}
/*double dist(int x1,int y1,int x2,int y2)
{
	return sqrt((x1 - x2)*(x1-x2) + (y2 - y1)*(y2-y1));
}*/
bool CLine::IsInFigure(int X, int Y)
{
	double Dist = sqrt((Corner1.x - Corner2.x)*(Corner1.x - Corner2.x) + (Corner1.y - Corner2.y)*(Corner1.y - Corner2.y));
	double D1= sqrt((Corner1.x - X)*(Corner1.x - X) + (Corner1.y - Y)*(Corner1.y - Y));
	double D2= sqrt((X - Corner2.x)*(X - Corner2.x) + (Y - Corner2.y)*(Y - Corner2.y));
	return(abs(Dist - (D1 + D2)) <= 0.01);
   /*int slope = (Corner1.y - Corner2.y) / (Corner1.x - Corner2.x);
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
	if (X >= minx && X <= maxx && Y<=maxy && Y>=miny && (Corner1.y - Y) / (Corner1.x - X) == slope)
		return true;
	else*/
}