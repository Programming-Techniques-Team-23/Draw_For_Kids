#include "CSquare.h"
#include <fstream>


CSquare::CSquare(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Centre = P1;
	Type = "Square";

}
CSquare::CSquare()
{
	Type = "Square";
}
string CSquare::getType()
{
	return Type;
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
string CSquare::Details() {
	int x1 = Centre.x;
	int y1 = Centre.y;
	string s = "   ";
	string message = Type + s;
	message += to_string(ID) + s;
	message += to_string(x1) + s;
	message += to_string(y1) + s;
	message += DrawColor + s + FillColor;
	return message;
}

void CSquare::Save(ofstream& OutFile)
{
	OutFile.app;
	OutFile << Type << " " << ID << " " << Centre.x << " " << Centre.y << " " << DrawColor << " " << FillColor << endl;
}

void CSquare::Load(ifstream& Infile)
{
	Infile >> ID >> Centre.x >> Centre.y >> DrawColor >> FillColor;
	FigGfxInfo.DrawClr = stringtoclr(DrawColor);

	FigGfxInfo.FillClr = stringtoclr(FillColor);

}
