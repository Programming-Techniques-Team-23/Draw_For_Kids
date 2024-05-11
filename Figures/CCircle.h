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
	CCircle();
	virtual void Draw(Output* pOut) const;
	bool pointchecker(int x, int y);
	virtual void Save(ofstream& OutFile);
	string getType();
	string Details();
	virtual void Load(ifstream& Infile);
	void setcentre(Point f);
	void setradius(Point g);
	void setgfxinfo(GfxInfo gi);
	Point getcent();
	Point getradius();
	GfxInfo getgfxinfo();
};

#endif