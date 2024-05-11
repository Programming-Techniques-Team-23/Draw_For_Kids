#ifndef CTRI_H
#define CTRI_H
#include<string>
#include "../Figures/CFigure.h"
using namespace std;

class CTriangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;
public:
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
	CTriangle();
	virtual void Draw(Output* pOut) const;
	bool pointchecker(int x, int y);
	double area(Point , Point , Point );
	virtual void Save(ofstream& OutFile);
	string getType();
	string Details();
	virtual void Load(ifstream& Infile);
	void setcor1(Point f);
	void setcor2(Point g);
	void setcor3(Point h);
	void setgfxinfo(GfxInfo gi);
	Point getcor1();
	Point getcor2();
	Point getcor3();
	GfxInfo getgfxinfo();
};

#endif