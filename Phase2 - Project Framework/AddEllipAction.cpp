#include "AddEllipAction.h"
#include "CEllipse.h"

#include "ApplicationManager.h"

#include "GUI/Input.h"
#include "GUI/Output.h"

AddEllipAction::AddEllipAction(ApplicationManager * pApp) :Action(pApp)
{}

void AddEllipAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Ellipse: Click at Ellipse Center");

	//Read Center and store it in point P
	pIn->GetPointClicked(P.x, P.y);

	EllipGfxInfo.isFilled = false;	//default is not filled
									//get drawing, filling colors and pen width from the interface
	EllipGfxInfo.DrawClr = pOut->getCrntDrawColor();
	EllipGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddEllipAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a rhombus with the parameters read from the user
	CEllipse *E = new CEllipse(P, EllipGfxInfo);

	//Add the ellipse to the list of figures
	pManager->AddFigure(E);
}