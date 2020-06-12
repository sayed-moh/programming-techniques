#pragma once
#ifndef ADD_Paste_ACTION_H
#define ADD_Paste_ACTION_H
#include "ApplicationManager.h"
#include "Actions/Action.h"

class AddPasteAction:public Action

{
private:
	Point position;
	CFigure *paste;
	CFigure *nPaste;

public:
	AddPasteAction(ApplicationManager*pAppManager);
	void ReadActionParameters();
	void Execute();

};
#endif
