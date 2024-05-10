#include "Actions/LoadAction.h"
#include "GUI/Output.h"
#include"ApplicationManager.h"
#include"Figures/CFigure.h"
#include"Figures/CTriangle.h"
#include"Figures/CSquare.h"
#include"Figures/CRectangle.h"
#include"Figures/CCircle.h"
#include"Figures/CHexagon.h"
#include<fstream>



LoadAction::LoadAction(ApplicationManager* AM): Action(AM)
{
}

void LoadAction::ReadActionParameters()
{
	
}

void LoadAction::Execute()
{
	Input* pIn = pManager->GetInput();
	Output* pout = pManager->GetOutput();
	string type;
	pout->PrintMessage("Enter File to Load from Name:");

	name = pIn->GetString(pout);
	
	
	ifstream fin(name);

	fin.open(name, ios::in);
	while (!fin.eof())
	{
		fin >> type;
		if (type == "Triangle")
		{
			CTriangle* T = new CTriangle(p1,p2,p3,gi);
			
			T->Load(ifstream(name));
			
			pManager->AddFigure(T);

			
		}
		else if (type == "Square")
		{
			CSquare* T = new CSquare(p1, gi);

			T->Load(ifstream(name));

			pManager->AddFigure(T);
		}
		else if (type == "Hexagon")
		{
			CHexagon* T = new CHexagon(p1, gi);

			T->Load(ifstream(name));
			pManager->AddFigure(T);
			
		}
		else if (type == "Rectangle")
		{
			CRectangle* T = new CRectangle(p1, p2, gi);

			T->Load(ifstream(name));
			pManager->AddFigure(T);
	
		}
		else if (type == "Circle")
		{
			CCircle* T = new CCircle(p1, p2, gi);

			T->Load(ifstream(name));
			pManager->AddFigure(T);
		
		}
	}
	fin.close();
}

void LoadAction::setp1(Point r)
{
	p1 = r;
}

void LoadAction::setp2(Point h)
{
	p2 = h;
}

void LoadAction::setp3(Point k)
{
	p1 = k;
}

void LoadAction::setgi(GfxInfo g)
{
	gi = g;;
}
