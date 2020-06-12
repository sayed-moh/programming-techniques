#pragma once
#ifndef ADD_Cut_ACTION_H
#define ADD_Cut_ACTION_H
#include "ApplicationManager.h"
#include "Actions/Action.h"

class AddCutAction:public Action
{
private:
	CFigure*Cut;
public:
	AddCutAction(ApplicationManager*pAppManager);
	void ReadActionParameters();
	virtual void Execute();


};

#endif