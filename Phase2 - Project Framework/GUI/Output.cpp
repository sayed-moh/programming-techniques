#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;

	UI.width = 1250;
	UI.height = 650;
	UI.wx = 5;
	UI.wy = 5;


	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 69;

	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames


						//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");

	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	pWind->SetPen(WHITE, 3); //clearing toolbar
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_LINE] = "images\\MenuItems\\Menu_Line.jpg";
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rect.jpg";
	MenuItemImages[ITM_TRI] = "images\\MenuItems\\Menu_Tri.jpg";
	MenuItemImages[ITM_RHOMBUS] = "images\\MenuItems\\Menu_Rhombus.jpg";
	MenuItemImages[ITM_ELLIPSE] = "images\\MenuItems\\Menu_Ellipse.jpg";
	MenuItemImages[ITM_PALLET] = "images\\MenuItems\\Menu_Colors.jpg";
	MenuItemImages[ITM_CHNGDRWCLR] = "images\\MenuItems\\Menu_DrawColor.jpg";
	MenuItemImages[ITM_CHNGFILLCLR] = "images\\MenuItems\\Menu_FillColor.jpg";
	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\Menu_Select.jpg";
	MenuItemImages[ITM_COPY] = "images\\MenuItems\\Menu_Copy.jpg";
	MenuItemImages[ITM_CUT] = "images\\MenuItems\\Menu_Cut.jpg";
	MenuItemImages[ITM_DEL] = "images\\MenuItems\\Menu_Delete.jpg";
	MenuItemImages[ITM_PASTE] = "images\\MenuItems\\Menu_Paste.jpg";
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\Menu_Save.jpg";
	MenuItemImages[ITM_SAVEBYTYPE] = "images\\MenuItems\\Menu_Savebytype.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\Menu_Load.jpg";
	MenuItemImages[ITM_PM] = "images\\MenuItems\\Menu_PM.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i<DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	pWind->SetPen(WHITE, 3);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
	UI.InterfaceMode = MODE_PLAY;
	string MenuItemImages[PLAY_ITM_COUNT];

	MenuItemImages[ITM_DM] = "images\\MenuItems\\Menu_DM.jpg";
	MenuItemImages[ITM_BYTYPE] = "images\\MenuItems\\Menu_Bytype.jpg";
	MenuItemImages[ITM_BYCLR] = "images\\MenuItems\\Menu_Bycolor.jpg";
	MenuItemImages[ITM_EXIT2] = "images\\MenuItems\\Menu_Exit.jpg";

	for (int i = 0; i<PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);


	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
	///TODO: write code to create Play mode menu
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{
	return UI.DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{
	return UI.FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

int Output::getCrntPenWidth() const		//get current pen width
{
	return UI.PenWidth;
}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	if (P1.y > UI.height - UI.StatusBarHeight)
		P1.y = UI.height - UI.StatusBarHeight;
	if (P2.y > UI.height - UI.StatusBarHeight)
		P2.y = UI.height - UI.StatusBarHeight;
	if (P1.y < UI.ToolBarHeight)
		P1.y = UI.ToolBarHeight;
	if (P2.y < UI.ToolBarHeight)
		P2.y = UI.ToolBarHeight;

	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}

void Output::DrawTri(Point P1, Point P2, Point P3, GfxInfo TriGfxInfo, bool selected) const
{
	if (P1.y > UI.height - UI.StatusBarHeight)
		P1.y = UI.height - UI.StatusBarHeight;
	if (P2.y > UI.height - UI.StatusBarHeight)
		P2.y = UI.height - UI.StatusBarHeight;
	if (P3.y > UI.height - UI.StatusBarHeight)
		P3.y = UI.height - UI.StatusBarHeight;
	if (P1.y < UI.ToolBarHeight)
		P1.y = UI.ToolBarHeight;
	if (P2.y < UI.ToolBarHeight)
		P2.y = UI.ToolBarHeight;
	if (P3.y < UI.ToolBarHeight)
		P3.y = UI.ToolBarHeight;

	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = TriGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (TriGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TriGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);

}

void Output::DrawLine(Point P1, Point P2, GfxInfo LineGfxInfo, bool selected) const
{
	if (P1.y> UI.height - UI.StatusBarHeight)
		P1.y = UI.height - UI.StatusBarHeight;
	if (P1.y < UI.ToolBarHeight)
		P1.y = UI.ToolBarHeight;
	if (P2.y < UI.ToolBarHeight)
		P2.y = UI.ToolBarHeight;

	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor;
	else
		DrawingClr = LineGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;

	style = FRAME;

	pWind->DrawLine(P1.x, P1.y, P2.x, P2.y, style);

}

void Output::DrawRhomb(Point P1, GfxInfo RhombGfxInfo, bool selected) const
{
	int y = 60;
	int z = 100;
	if (P1.y + z > UI.height - UI.StatusBarHeight)
		P1.y = UI.height - (z + UI.StatusBarHeight);
	if (P1.y < UI.ToolBarHeight + z)
		P1.y = UI.ToolBarHeight + z;
	if (UI.width - P1.x < y)
		P1.x = UI.width - (y + 15);
	if (P1.x < y)
		P1.x = y;
	int *X = new int[4];
	int *Y = new int[4];
	X[0] = P1.x + y;
	Y[0] = P1.y;
	X[1] = P1.x;
	Y[1] = P1.y + z;
	X[2] = P1.x - y;
	Y[2] = P1.y;
	X[3] = P1.x;
	Y[3] = P1.y - z;

	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor;
	else
		DrawingClr = RhombGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RhombGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RhombGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawPolygon(X, Y, 4, style);

	delete[]X;
	delete[]Y;
}

void Output::DrawEllip(Point P1, GfxInfo EllipGfxInfo, bool selected) const
{
	int y = 60;
	int z = 100;
	if (P1.y + y > UI.height - UI.StatusBarHeight)
		P1.y = UI.height - (y + UI.StatusBarHeight);
	if (P1.y < UI.ToolBarHeight + y)
		P1.y = UI.ToolBarHeight + y;
	if (UI.width - P1.x < y)
		P1.x = UI.width - (z + 15);
	if (P1.x<z)
		P1.x = z;

	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor;
	else
		DrawingClr = EllipGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (EllipGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(EllipGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawEllipse(P1.x - z, P1.y + y, P1.x + z, P1.y - y, style);

}

//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

