#ifndef ADD_SEL_ACTION_H
#define ADD_SEL_ACTION_H

#include "Action.h"

//Select Action Class
class SelectAction : public Action
{
private:
	Point P1;
public:
	SelectAction(ApplicationManager* pApp);

	//Reads Point
	virtual void ReadActionParameters();

	//Add Selection to the ApplicationManager
	virtual void Execute();

};

#endif