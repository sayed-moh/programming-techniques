
#include "GUI/Input.h"
#include "GUI/Output.h"
#include "ApplicationManager.h"
#include "AddCopyAction.h"
#include "Figures/CRectangle.h"
#include "CRhombus.h"
#include "CTriangle.h"
#include "CLine.h"
#include "CEllipse.h"
#include "AddPasteAction.h"


AddPasteAction::AddPasteAction(ApplicationManager*pAppManager)
	:Action(pAppManager)
{
}
void AddPasteAction::ReadActionParameters()
{
	paste = pManager->getClipboard();
}
void AddPasteAction::Execute()
{
	Input *pIn = pManager->GetInput();
	Output *pOut = pManager->GetOutput();
	ReadActionParameters();
	if (paste == NULL)
	{
		pOut->PrintMessage("you must copy or cut first ");
	}
	else
	{
		pIn->GetPointClicked(position.x,position.y);
		
		pManager->AddFigure(nPaste);
	}

}