#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	CRectangle();
	virtual void Draw(Output* pOut) const;
	bool pointchecker(int x,int y);
	virtual void Save(ofstream& OutFile);
	Point PasteRect(Point P, Output* pOut);
	string getType();
	string Details();
	virtual void Load(ifstream& Infile);
};

#endif