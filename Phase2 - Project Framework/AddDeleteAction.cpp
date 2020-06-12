#include "AddDeleteAction.h"
#include "Actions/Action.h"
#include "Figures/CFigure.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
#include"ApplicationManager.h"
AddDeleteAction::AddDeleteAction(ApplicationManager * pApp) :Action(pApp)
{}

void AddDeleteAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

}

//Execute the action
void AddDeleteAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();
	CFigure* Delete = pManager->getSelectedFig();
}