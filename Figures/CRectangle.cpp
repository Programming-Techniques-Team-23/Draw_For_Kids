#include "CRectangle.h"
#include <fstream>


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

void CRectangle::Save(ofstream& OutFile)
{
    
    string s = "   ";
	string dc;
	string fc;
	if (FigGfxInfo.DrawClr == BLACK)
	{
		fc = "Black";
	}
	else if (FigGfxInfo.DrawClr == BLUE)
	{
		dc = "Blue";
	}
	else if (FigGfxInfo.DrawClr == GREEN)
	{
		dc = "GREEN";
	}
	else if (FigGfxInfo.DrawClr == YELLOW)
	{
		dc = "Yellow";
	}
	else if (FigGfxInfo.DrawClr == RED)
	{
		dc = "RED";
	}
	else if (FigGfxInfo.DrawClr == ORANGE)
	{
		dc = "ORANGE";
	}
	else if (FigGfxInfo.DrawClr == NULL)
	{
		dc = "NOT FILLED";
	}

	if (FigGfxInfo.FillClr == BLACK)
	{
		fc = "Black";
	}
	else if (FigGfxInfo.DrawClr == BLUE)
	{
		fc = "Blue";
	}
	else if (FigGfxInfo.DrawClr == GREEN)
	{
		fc = "GREEN";
	}
	else if (FigGfxInfo.DrawClr == YELLOW)
	{
		fc = "Yellow";
	}
	else if (FigGfxInfo.DrawClr == RED)
	{
		fc = "RED";
	}
	else if (FigGfxInfo.DrawClr == ORANGE)
	{
		fc = "ORANGE";
	}
	else if (FigGfxInfo.DrawClr == NULL)
	{
		fc = "NOT FILLED";
	}

    

	OutFile << "Rect" << s << ID << s << Corner1.x << s << Corner1.y << s << Corner2.x << s << Corner2.y << s << dc << s << fc << endl;
	
}

