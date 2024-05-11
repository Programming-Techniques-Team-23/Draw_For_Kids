#ifndef CHEX_H
#define CHEX_H

#include "CFigure.h"
class CHexagon : public CFigure
{
private:
	Point Centre;
public:
	CHexagon(Point, GfxInfo FigureGfxInfo);
	CHexagon();
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