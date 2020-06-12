#include "GUI/Input.h"
#include "GUI/Output.h"
#include "ApplicationManager.h"
#include "AddCutAction.h"
#include "Figures/CRectangle.h"
#include "CRhombus.h"
#include "CTriangle.h"
#include "CLine.h"
#include "CEllipse.h"

AddCutAction::AddCutAction(ApplicationManager*pApp) :Action(pApp)
{

}
void AddCutAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	pManager->getSelectedFig();
	Cut = pManager->getClipboard();
}
void AddCutAction::Execute()
{
	Output *pOut = pManager->GetOutput();
	ReadActionParameters();
	if (Cut != NULL)
	{
		pManager->getSelectedFig();
		pOut->PrintMessage("Cut operation succeded ");
	}
	else
	{
		pOut->PrintMessage("no Figure is selected ");
	}
}