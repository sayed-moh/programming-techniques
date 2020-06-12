#include "AddRhombAction.h"
#include "CRhombus.h"

#include "ApplicationManager.h"

#include "GUI/Input.h"
#include "GUI/Output.h"

AddRhombAction::AddRhombAction(ApplicationManager * pApp) :Action(pApp)
{}

void AddRhombAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Rhombus: Click at Rhombus Center");

	//Read Center and store it in point P
	pIn->GetPointClicked(P.x, P.y);

	RhombGfxInfo.isFilled = false;	//default is not filled
									//get drawing, filling colors and pen width from the interface
	RhombGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RhombGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddRhombAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a rhombus with the parameters read from the user
	CRhombus *RH = new CRhombus(P, RhombGfxInfo);

	//Add the rhombus to the list of figures
	pManager->AddFigure(RH);
}