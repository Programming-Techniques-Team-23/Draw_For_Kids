#include "Actions/Action.h"


class LoadAction : public Action

{
private:
	string name;
public:
	LoadAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	
};

