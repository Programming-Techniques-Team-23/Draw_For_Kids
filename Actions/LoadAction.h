#include "Action.h"


class LoadAction : public Action

{
private:
	string name;
	Point p1;
	Point p2;
	Point p3;
	GfxInfo gi;
public:
	LoadAction(ApplicationManager* AM);
	virtual void ReadActionParameters();
	virtual void Execute();
	void setp1(Point r);
	void setp2(Point h);
	void setp3(Point k);
	void setgi(GfxInfo g);
};

