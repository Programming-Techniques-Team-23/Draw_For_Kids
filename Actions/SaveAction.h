#include "Action.h"
#include"../ApplicationManager.h"



class SaveAction : public Action
{
private:
	string name;
public:
	SaveAction(ApplicationManager* AM);
	virtual void ReadActionParameters();
	virtual void Execute();
};
