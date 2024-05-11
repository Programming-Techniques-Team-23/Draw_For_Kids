#include "Actions/Action.h"
class ChngBorCol :public Action {
private:
	color CLR;
public:
	ChngBorCol(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};