#include "Action.h"
#include"../ApplicationManager.h"



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
