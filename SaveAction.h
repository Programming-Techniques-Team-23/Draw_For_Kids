#ifndef SAVEACTION_H
#define SAVEACTION_H
#include "Actions/Action.h"
#include "ApplicationManager.h"



class SaveAction : public Action
{
private:
	string name;
	ofstream fout;
public:
	SaveAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};
#endif
