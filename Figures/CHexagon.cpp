#include "CHexagon.h"

CHexagon::CHexagon(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Centre = P1;
}


void CHexagon::Draw(Output* pOut) const
{
	//Call Output::DrawHex to draw a hexagon on the screen	
	pOut->DrawHex(Centre, FigGfxInfo, Selected);
}