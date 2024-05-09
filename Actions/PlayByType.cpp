#include "PlayByType.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CTriangle.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"


PickByType::PickByType(ApplicationManager* pApp) :Action(pApp)
{
	no_figs = 0;
	rigSel = 0;
	wrgSel = 0;

}
void PickByType::PrntScore(int S)
{
	Output* pOut = pManager->GetOutput();

	string message;
	if (S == 1)
	{
		rigSel++;
		message = "Right!, Your score is: " + to_string(rigSel) + " Right, and " + to_string(wrgSel) + " Wrong.";
	}
	else 	if (S == 2)
	{
		wrgSel++;
		message = "Wrong!, Your score is: " + to_string(rigSel) + " Right, and " + to_string(wrgSel) + " Wrong.";
	}
	else
		message = "YOU WIN!, Your score is: " + to_string(rigSel) + " Right, and " + to_string(wrgSel) + " Wrong.";
	pOut->PrintMessage(message);


}

PickByType::~PickByType()
{
}

void PickByType::ReadActionParameters()
{
	int* figs = pManager->types();
	for (int i = 0; i < 4; i++)
		if (figs[i] != 0)
			no_figs++;
}

void PickByType::Execute()
{
	int* figs = pManager->types();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ReadActionParameters();
	if (no_figs > 1)
	{
		CFigure* clickedFig;
		CFigure* Fig = pManager->getRandomFig();
		if (Fig->getType() == "Rectangle")
		{
			picked_fig_no = figs[0];
			pOut->PrintMessage("Pick up all the rectangles!");

		}
		else if (Fig->getType() == "Triangle")
		{
			picked_fig_no = figs[1];
			pOut->PrintMessage("Pick up all the triangles!");

		}
		else if (Fig->getType() == "Square")
		{
			picked_fig_no = figs[2];
			pOut->PrintMessage("Pick up all the squares!");

		}
		else if (Fig->getType() == "Hexagon")
		{
			picked_fig_no = figs[3];
			pOut->PrintMessage("Pick up all the hexagons!");

		}
		else if (Fig->getType() == "Circle")
		{
			picked_fig_no = figs[4];
			pOut->PrintMessage("Pick up all the circles!");

		}

		while (picked_fig_no > 0)
		{
			{

				pIn->GetPointClicked(P.x, P.y);
				if (P.y > UI.ToolBarHeight || P.x > (UI.MenuItemWidth * PLAY_ITM_COUNT))
				{
					clickedFig = pManager->GetFigure(P.x, P.y);
					if (clickedFig != NULL)
					{


						if (clickedFig->getType() == "Rectangle" && Fig->getType() == "Rectangle")
						{
							PrntScore(1);
							clickedFig->Hide();
							pManager->UpdateInterface();
							picked_fig_no--;
						}
						else if (clickedFig->getType() == "Circle" && Fig->getType() == "Circle")
						{
							PrntScore(1);
							clickedFig->Hide();
							pManager->UpdateInterface();
							picked_fig_no--;
						}
						else if (clickedFig->getType() == "Triangle" && Fig->getType() == "Triangle")
						{
							PrntScore(1);
							clickedFig->Hide();
							pManager->UpdateInterface();
							picked_fig_no--;
						}
						else if (clickedFig->getType() == "Hexagon" && Fig->getType() == "Hexagon")
						{
							PrntScore(1);
							clickedFig->Hide();
							pManager->UpdateInterface();
							picked_fig_no--;
						}
						else if (clickedFig->getType() == "Square" && Fig->getType() == "Square")
						{
							PrntScore(1);
							clickedFig->Hide();
							pManager->UpdateInterface();
							picked_fig_no--;
						}
						else
						{
							PrntScore(2);
							clickedFig->Hide();
							pManager->UpdateInterface();
						}
					}
				}
				else
				{
					pOut->PrintMessage("Toolbar clicked, game aborted.");
					picked_fig_no = -1;
				}


			}
			if (picked_fig_no == 0)
				PrntScore(3);



		}
	}
	else
		pOut->PrintMessage("You must have at least two or more figures to play to play pick by figure!");
	for (int i = 0; i < pManager->GetFigCount(); i++) {
		pManager->ShowAll();
		pManager->UpdateInterface();
	}
	delete[]figs;





}
