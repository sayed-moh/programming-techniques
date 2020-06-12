#include "AddLineAction.h"
#include "CLine.h"

#include "ApplicationManager.h"

#include "GUI/Input.h"
#include "GUI/Output.h"

AddLineAction::AddLineAction(ApplicationManager * pApp) :Action(pApp)
{}

void AddLineAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Line: Click at initial point");

	//Read initial point and store it in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Line: Click at final point");

	//Read final point and store it in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	//get drawing, filling colors and pen width from the interface
	LineGfxInfo.DrawClr = pOut->getCrntDrawColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddLineAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a line with the parameters read from the user
	CLine *L = new CLine(P1, P2, LineGfxInfo);

	//Add the line to the list of figures
	pManager->AddFigure(L);
}