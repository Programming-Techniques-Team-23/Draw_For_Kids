#ifndef CTRI_H
#define CTRI_H
#include<string>
#include "CFigure.h"

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
	Point* PasteTri(Point P, Output* pOut);
};

#endif