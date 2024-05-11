#ifndef CSQUARE_H
#define CSQUARE_H

#include "CFigure.h"

class CSquare : public CFigure
{
private:
	Point Centre;
public:
	CSquare(Point, GfxInfo FigureGfxInfo);
	CSquare();
	virtual void Draw(Output* pOut) const;
	bool pointchecker(int x, int y);
	virtual void Save(ofstream& OutFile);
	string getType();
	string Details();
	virtual void Load(ifstream& Infile);
	
	void setcentre(Point f);
	void setgfxinfo(GfxInfo gi);
	Point getcent();
	GfxInfo getgfxinfo();

};

#endif