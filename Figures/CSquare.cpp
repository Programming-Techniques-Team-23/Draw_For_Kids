#include "CSquare.h"

CSquare::CSquare(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Centre = P1;
}


void CSquare::Draw(Output* pOut) const
{
	//Call Output::DrawSqaure to draw a square on the screen	
	pOut->DrawSquare(Centre, FigGfxInfo, Selected);
}
bool CSquare::pointchecker(int x, int y)
{
    int xmin = Centre.x - 100; 
    int xmax = Centre.x + 100; 
    int ymin = Centre.y - 100; 
    int ymax = Centre.y + 100; 

    if ((x >= xmin && x <= xmax) && (y >= ymin && y <= ymax))
        return true;
    else
        return false;
}
