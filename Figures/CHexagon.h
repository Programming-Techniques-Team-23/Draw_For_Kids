#ifndef CHEX_H
#define CHEX_H

#include "CFigure.h"
class CHexagon : public CFigure
{
private:
	Point Centre;
public:
	CHexagon(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	bool pointchecker(int x, int y);
	virtual void Save(ofstream& OutFile);
};

#endif