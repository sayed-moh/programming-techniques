#include "CRhombus.h"

CRhombus::CRhombus(Point P, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P;
}


void CRhombus::Draw(Output* pOut) const
{
	//Call Output::DrawRhomb to draw a rhombus on the screen	
	pOut->DrawRhomb(Center, FigGfxInfo, Selected);
}
double area1(int x1, int y1, int x2, int y2, int x3, int y3) {
	return abs((x1*(y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}
bool CRhombus::IsInFigure(int X, int Y) {  //I Divided Rhombus into two triangle to check if point is inside it or not.
	if (Y > Center.y)
	{
		double Area = area1((Center.x) + 60, Center.y, (Center.x) - 60, Center.y, Center.x, (Center.y) + 100);
		double A1 = area1(X, Y, (Center.x) - 60, Center.y, Center.x, (Center.y) + 100);
		double A2 = area1((Center.x) + 60, Center.y, X, Y, Center.x, (Center.y) + 100);
		double A3 = area1((Center.x) + 60, Center.y, (Center.x) - 60, Center.y, X, Y);
		return(Area == A1 + A2 + A3);
	}
	else if (Y < Center.y)
	{
		double Area = area1((Center.x) + 60, Center.y, (Center.x) - 60, Center.y, Center.x, (Center.y) - 100);
		double A1 = area1(X, Y, (Center.x) - 60, Center.y, Center.x, (Center.y) - 100);
		double A2 = area1((Center.x) + 60, Center.y, X, Y, Center.x, (Center.y) - 100);
		double A3 = area1((Center.x) + 60, Center.y, (Center.x) - 60, Center.y, X, Y);
		return(Area == A1 + A2 + A3);
	}
	return false;
}