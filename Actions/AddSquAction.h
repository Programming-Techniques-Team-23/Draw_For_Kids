#ifndef ADD_SQU_ACTION_H
#define ADD_SQU_ACTION_H

#include "Action.h"

//Add Square Action class
class AddSquAction : public Action
{
private:
	Point P1; //Square centre
	GfxInfo SquGfxInfo;
public:
	AddSquAction(ApplicationManager* pApp);

	//Reads square parameters
	virtual void ReadActionParameters();

	//Add square to the ApplicationManager
	virtual void Execute();

};

#endif