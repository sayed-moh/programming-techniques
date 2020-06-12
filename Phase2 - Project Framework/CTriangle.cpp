#include "CTriangle.h"

CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
}


void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawTri to draw a triangle on the screen	
	pOut->DrawTri(Corner1, Corner2, Corner3, FigGfxInfo, Selected);
}
float area(int x1, int y1, int x2, int y2, int x3, int y3) {
	return abs((x1*(y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}
bool CTriangle::IsInFigure(int X, int Y)
{
	float Area = area(Corner1.x, Corner1.y, Corner2.x, Corner2.y, Corner3.x, Corner3.y);
	float A1= area(X, Y, Corner2.x, Corner2.y, Corner3.x, Corner3.y);
	float A2= area(Corner1.x, Corner1.y, X, Y, Corner3.x, Corner3.y);
	float A3= area(Corner1.x, Corner1.y, Corner2.x, Corner2.y, X, Y);
	return(Area == A1 + A2 + A3);
}
