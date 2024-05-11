#include "LoadAction.h"
#include "GUI/Output.h"
#include"ApplicationManager.h"
#include"Figures/CFigure.h"
#include"Figures/CTriangle.h"
#include"Figures/CSquare.h"
#include"Figures/CRectangle.h"
#include"Figures/CCircle.h"
#include"Figures/CHexagon.h"
#include<fstream>



LoadAction::LoadAction(ApplicationManager* pApp) : Action(pApp)
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


	ifstream fin;

	fin.open(name + ".txt", ios::in);
	if (fin.fail())
	{
		pout->PrintMessage(name + ".txt" + "doesn't exist");
	}
	else {
		pout->ClearDrawArea();
		int figcnt;
		fin >> figcnt;
		for (int i = 0;i < figcnt;i++)
		{

			CFigure* F;
			fin >> type;
			if (type == "Square") F = new CSquare;
			else if (type == "Hexagon") F = new CHexagon;
			else if (type == "Circle") F = new CCircle;
			else if (type == "Rectangle") F = new CRectangle;
			else if (type == "Triangle") F = new CTriangle;
			else break;

			F->Load(fin);
			pManager->AddFigure(F);

		}

		pManager->UpdateInterface();
		pManager->UnselectAll();


		fin.close();
		pout->PrintMessage("File loaded");
	}
}
