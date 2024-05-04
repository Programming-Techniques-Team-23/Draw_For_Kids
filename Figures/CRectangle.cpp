#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}
bool CRectangle::pointchecker(int x, int y)
{
    int Pxmin, Pxmax, Pymin, Pymax;

    if (Corner1.x >= Corner2.x)
    {
        Pxmax = Corner1.x;
        Pxmin = Corner2.x;
    }
    else
    {
        Pxmax = Corner2.x;
        Pxmin = Corner1.x;
    }

    if (Corner1.y >= Corner2.y)
    {
        Pymax = Corner1.y;
        Pymin = Corner2.y;
    }
    else
    {
        Pymax = Corner2.y;
        Pymin = Corner1.y;
    }
    if ((x >= Pxmin && x <= Pxmax) && (y >= Pymin && y <= Pymax))
        return true;
    else
        return false;
}

