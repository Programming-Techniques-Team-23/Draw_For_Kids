#pragma once
#include"Action.h"

class Paste :public Action {
private:
	Point P;
public:
	Paste(ApplicationManager* AM);
	virtual void ReadActionParameters();
		virtual void  Execute();
	~Paste();

};
