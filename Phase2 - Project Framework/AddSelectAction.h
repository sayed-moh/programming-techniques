#ifndef ADD_SELECT_ACTION_H
#define ADD_SELECT_ACTION_H
#include"ApplicationManager.h"
#include"Actions/Action.h"
//Add Rectangle Action class
class AddSelectAction : public Action
{
private:
	Point P1;
public:
	AddSelectAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

#endif