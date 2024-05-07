#include "Action.h"
#include"../ApplicationManager.h"


#ifndef SAVE_ACTION_H
#endif SAVE_ACTION_H

class SaveAction : public Action
{
private :
	string name;
public:
	SaveAction(ApplicationManager* AM);
	virtual void ReadActionParameters();
	virtual void Execute();
};