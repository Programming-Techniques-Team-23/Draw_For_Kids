#include "CHexagon.h"
#include "CTriangle.h"
#include <fstream>

CHexagon::CHexagon(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Centre = P1;
	Type = "Hexagon";
}

void CHexagon::Draw(Output* pOut) const
{
	//Call Output::DrawHex to draw a hexagon on the screen	
	pOut->DrawHex(Centre, FigGfxInfo, Selected);
}
string CHexagon::getType()
{
	return Type;
}
bool CHexagon::pointchecker(int x, int y) {
	Point P1 = { Centre.x + 60, Centre.y };
	Point P2 = { Centre.x + 30, Centre.y + 52 };
	Point P3 = { Centre.x - 30, Centre.y + 52 };
	Point P4 = { Centre.x - 60, Centre.y };
	Point P5 = { Centre.x - 30, Centre.y - 52 };
	Point P6 = { Centre.x + 30, Centre.y - 52 };

	CTriangle T1(P1, P2, Centre, FigGfxInfo);
	CTriangle T2(P2, P3, Centre, FigGfxInfo);
	CTriangle T3(P3, P4, Centre, FigGfxInfo);
	CTriangle T4(P4, P5, Centre, FigGfxInfo);
	CTriangle T5(P5, P6, Centre, FigGfxInfo);
	CTriangle T6(P6, P1, Centre, FigGfxInfo);

	if (T1.pointchecker(x, y) || T2.pointchecker(x, y) || T3.pointchecker(x, y) || T4.pointchecker(x, y) || T5.pointchecker(x, y) || T6.pointchecker(x, y))
		return true;
	else
		return false;
}
string CHexagon::Details() {
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

void CHexagon::Save(ofstream& OutFile)
{
	OutFile << Details() << endl;
	
}

