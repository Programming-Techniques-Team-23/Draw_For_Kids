#ifndef CHEX_H
#define CHEX_H

#include "CFigure.h"

class CHexagon : public CFigure
{
private:
	Point Centre1;
public:
	CHexagon(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
};

#endif