#ifndef ADD_Delete_ACTION_H
#define ADD_Delete_ACTION_H
#include"Actions/Action.h"

//Add Rectangle Action class
class AddDeleteAction : public Action
{
private:
	Point P1, P2; //Rectangle Corners
	GfxInfo RectGfxInfo;
public:
	AddDeleteAction(ApplicationManager *pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

};

#endif