#ifndef CCIRC_H
#define CCIRC_H
#include<string>
#include "CFigure.h"

class CCircle : public CFigure
{
private:
	Point Centre;
	Point Radius;
public:
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	bool pointchecker(int x, int y);
	virtual void Save(ofstream& OutFile);
	string getType();
	string Details();
};

#endif