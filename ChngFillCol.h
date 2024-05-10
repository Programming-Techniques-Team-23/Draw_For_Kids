#include "Actions/Action.h"
class ChngFillCol :public Action{
private:
	bool clicked;
	bool Fill;
	color CLR;
public:
	ChngFillCol(ApplicationManager* pApp, bool n = false, color C=PURPLE);
	virtual void ReadActionParameters();
	virtual void Execute();
};