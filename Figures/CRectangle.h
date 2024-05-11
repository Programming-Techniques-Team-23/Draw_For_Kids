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
	string getType();
	string Details();
	virtual void Load(ifstream& Infile);
	void setcor1(Point f);
	void setcor2(Point g);
	void setgfxinfo(GfxInfo gi);
	Point getcor1();
	Point getcor2();
	GfxInfo getgfxinfo();
};

#endif