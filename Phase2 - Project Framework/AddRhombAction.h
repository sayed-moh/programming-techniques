#ifndef ADD_RHOMB_ACTION_H
#define ADD_RHOMB_ACTION_H

#include "Actions/Action.h"

//Add Rhombus Action class
class AddRhombAction : public Action
{
private:
	Point P; //Rhombus Center
	GfxInfo RhombGfxInfo;
public:
	AddRhombAction(ApplicationManager *pApp);

	//Reads rhombus parameters
	virtual void ReadActionParameters();

	//Add rhombus to the ApplicationManager
	virtual void Execute();

};

#endif
