#ifndef ADD_Copy_ACTION_H
#define ADD_Copy_ACTION_H
#include "ApplicationManager.h"
#include "Actions/Action.h"

class AddCopyAction :public Action
{
private:
	
	 CFigure*cpy;
public:

	AddCopyAction(ApplicationManager * pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	


};


#endif