#include "GUI/Input.h"
#include "GUI/Output.h"
#include "ApplicationManager.h"
#include "AddCopyAction.h"
#include "Figures/CRectangle.h"

#include "CRhombus.h"
#include "CTriangle.h"
#include "CLine.h"
#include "CEllipse.h"

AddCopyAction::AddCopyAction(ApplicationManager * pApp):Action(pApp)
{

}
void AddCopyAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	pManager->getSelectedFig();
	cpy = pManager->getClipboard();

	

}
void AddCopyAction::Execute()
{
	Output *pOut = pManager->GetOutput();
	ReadActionParameters();
	if (cpy != NULL)
	{
		pManager->getSelectedFig();
		pOut->PrintMessage("copied");
		
	}
	else
	{
		pOut->PrintMessage("no Figure is selected ");
	}

}
//notes if the program does not work
//{	CFigure* clipboard = pManager->getClipboard();
//if (clipboard == NULL)
//{
//	delete clipboard;
//}
//
////This action needs to read some parameters first
//ReadActionParameters();
//CFigure* SelectedFigure = pManager->getSelectedFig();
//
//if (SelectedFigure)
//{
//	CRectangle* r = dynamic_cast<CRectangle*>(SelectedFigure);
//	CLine* l = dynamic_cast<CLine*>(SelectedFigure);
//	CRhombus* rh = dynamic_cast<CRhombus*>(SelectedFigure);
//	CTriangle* tr = dynamic_cast<CTriangle*>(SelectedFigure);
//	CEllipse* e = dynamic_cast<CEllipse*>(SelectedFigure);
//	if (r)
//	{
//		clipboard = new CRectangle(*r);
//	}
//	else if (l)
//	{
//		clipboard = new CLine(*l);
//
//	}
//	else if (rh)
//	{
//		clipboard = new CRhombus(*rh);
//
//	}
//	else if (tr)
//	{
//		clipboard = new CTriangle(*tr);
//	}
//	else if (e)
//	{
//		clipboard = new CEllipse(*e);
//	}
//
//	else
//
//	{
//		clipboard = NULL;
//
//
//	}
//}
//else
//
//{
//	clipboard = NULL;
//
//
//}
//
//pManager->setClipboard(clipboard);
///*if (SelectedFigure == NULL)
//	SelectedFigure->SetSelected(false);*/}
//
//
//
//






