#include "CRectangle.h"
#include <fstream>
#include"../ApplicationManager.h"


CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Type = "Rectangle";

}
CRectangle::CRectangle()
{
    Type = "Rectangle";
}
string CRectangle::getType()
{
	return Type;
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
string CRectangle::Details() {
    int x1 = Corner1.x;
    int y1 = Corner1.y;
    int x2 = Corner2.x;
    int y2 = Corner2.y;
    string s = "   ";
    string message = Type + s;
    message += to_string(ID) + s;
    message += to_string(x1) + s;
    message += to_string(y1) + s;
    message += to_string(x2) + s;
    message += to_string(y2) + s;
    message += DrawColor + s + FillColor;
    return message;
}
void CRectangle::Save(ofstream& OutFile)
{
    OutFile.app;
    OutFile << Type << " " << ID << " " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " " << " " << DrawColor << " " << FillColor << endl;
}

void CRectangle::Load(ifstream& Infile)
{
    Infile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> DrawColor >> FillColor;
    FigGfxInfo.DrawClr = stringtoclr(DrawColor);
    FigGfxInfo.FillClr = stringtoclr(FillColor);
}
Point CRectangle::PasteRect(Point P, Output* pOut)
{
    Point P1;
    P1.x= P.x+ abs(Corner1.x - Corner2.x);
    P1.y= P.y + abs(Corner1.y - Corner2.y);
   
    pOut->DrawRect(P, P1 , FigGfxInfo);

    return P1;
}

