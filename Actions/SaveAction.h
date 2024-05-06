#include "Action.h"
#include"../ApplicationManager.h"
#include "ApplicationManager.h"

#ifndef SAVE_ACTION_H
#endif SAVE_ACTION_H

class SaveAction : public Action
{
private :
	ofstream& OutFile;
public:

	void SAVE(ApplicationManager* AM);
	virtual void ReadActionParameters();
	virtual void Execute();

};