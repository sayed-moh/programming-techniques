#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "AddLineAction.h"
#include "AddTriAction.h"
#include "AddRhombAction.h"
#include "AddEllipAction.h"
#include "AddSelectAction.h"
#include "AddDeleteAction.h"
#include "Figures/CRectangle.h"
#include "AddCopyAction.h"


//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	SelectedFig=NULL;
	Clipboard=NULL;
	FigCount = 0;

	//Create an array of figure pointers and set them to NULL		
	for (int i = 0; i < MaxFigCount; i++)
		FigList[i] = NULL;
}
CFigure* ApplicationManager::getSelectedFig()const { return SelectedFig; }
CFigure* ApplicationManager::getClipboard()const { return Clipboard; }

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;

		case DRAW_LINE:
			pAct = new AddLineAction(this);
			break;

		case DRAW_TRI:
			pAct = new AddTriAction(this);
			break;

		case DRAW_RHOMBUS:
			pAct = new AddRhombAction(this);
			break;

		case DRAW_ELLIPSE:
			pAct = new AddEllipAction(this);
			break;

		case SELECT:
			pAct = new AddSelectAction(this);
			break;

		case COPY:
			pAct = new AddCopyAction(this);
			break;
		

		case DEL:
			pAct = new AddDeleteAction(this);
			break;
		case TO_PLAY:
			pOut->PrintMessage("Action: Switch to play Mode, creating play tool bar");
			pOut->CreatePlayToolBar(); // THIS TESTS Output::CreateSimulationToolBar() function //////
			break;
		case TO_DRAW:
			pOut->PrintMessage("Action: Switch to draw Mode, creating draw tool bar");
			pOut->CreateDrawToolBar(); // THIS TESTS Output::CreateSimulationToolBar() function //////
			break;

		case EXIT:
			///create ExitAction here
			
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
		for (int i = FigCount-1; i >=0; i--)
		{
			bool k=FigList[i]->IsInFigure(x, y);
			if (k)
			{
				return FigList[i];
			}
		}

	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

	return NULL;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	for(int i=0; i<FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}
