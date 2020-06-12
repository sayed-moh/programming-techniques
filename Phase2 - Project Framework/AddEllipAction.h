#ifndef ADD_ELLIP_ACTION_H
#define ADD_ELLIP_ACTION_H

#include "Actions/Action.h"

//Add Ellipse Action class
class AddEllipAction : public Action
{
private:
	Point P; //Ellipse Center
	GfxInfo EllipGfxInfo;
public:
	AddEllipAction(ApplicationManager *pApp);

	//Reads ellipse parameters
	virtual void ReadActionParameters();

	//Add ellipse to the ApplicationManager
	virtual void Execute();

};

#endif
