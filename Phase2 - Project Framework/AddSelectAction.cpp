#include "AddSelectAction.h"
#include "Actions/Action.h"
#include "Figures/CFigure.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
#include"ApplicationManager.h"
AddSelectAction::AddSelectAction(ApplicationManager * pApp) :Action(pApp)
{}

void AddSelectAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Select a Figure");
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->ClearStatusBar();

}
//Execute the action
void AddSelectAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();
    CFigure* SelectedFigure = pManager->GetFigure(P1.x, P1.y);
	CFigure* check = pManager->getSelectedFig();
	if (SelectedFigure != NULL)
	{
		if(check==NULL)
		{
			SelectedFigure->SetSelected(true);
			pManager->setSelectedFig(SelectedFigure);
		}
		else if(check!=NULL)
		{
			if (!SelectedFigure->IsSelected())
			{
				check->SetSelected(false);
				SelectedFigure->SetSelected(true);
				pManager->setSelectedFig(SelectedFigure);
			}
			else
			{
				SelectedFigure->SetSelected(false);
			}
		}
	}
	else
	{
		if (check != NULL)
			check->SetSelected(false);
	}
	
	/*if (SelectedFigure == NULL)
		SelectedFigure->SetSelected(false);*/
}
