#include "PlayByBoth.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"



void PickByBoth::PrntScore(int S)
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

PickByBoth::PickByBoth(ApplicationManager* pApp) :Action(pApp)
{
	no_combs = 0;
	wrgSel = 0;
	rigSel = 0;
}


PickByBoth::~PickByBoth()
{

}

void PickByBoth::ReadActionParameters()
{
	int* combinations = pManager->combinations();

	for (int i = 0; i < 30; i++)
		if (combinations[i] != 0)
			no_combs++;
}

void PickByBoth::Execute()
{
	int* combinations = pManager->combinations();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ReadActionParameters();

	if (no_combs > 1)
	{
	
		CFigure* clickedFig;
		CFigure* Fig = pManager->getRandomFig();
		if (Fig->GetGfxInfo().isFilled)
		{
			if (Fig->GetGfxInfo().FillClr == BLACK)
			{
				if (Fig->getType() == "Rectangle")
				{
					picked_comb_no = combinations[0];
					pOut->PrintMessage("Pick up all the black rectangles!");

				}
				else if (Fig->getType() == "Triangle")
				{
					picked_comb_no = combinations[1];
					pOut->PrintMessage("Pick up all the black triangles!");

				}
				else if (Fig->getType() == "Square")
				{
					picked_comb_no = combinations[2];
					pOut->PrintMessage("Pick up all the black squares!");

				}
				else if (Fig->getType() == "Hexagon") {
					picked_comb_no = combinations[3];
					pOut->PrintMessage("Pick up all the black Hexagons!");
				}
				else
				{
					picked_comb_no = combinations[4];
					pOut->PrintMessage("Pick up all the black Circles!");
				}

			}
			else if (Fig->GetGfxInfo().FillClr == YELLOW)
			{
				if (Fig->getType() == "Rectangle")
				{
					picked_comb_no = combinations[5];
					pOut->PrintMessage("Pick up all the white rectangles!");

				}
				else if (Fig->getType() == "Triangle")
				{
					picked_comb_no = combinations[6];
					pOut->PrintMessage("Pick up all the white triangles!");

				}
				else if (Fig->getType() == "Square")
				{
					picked_comb_no = combinations[7];
					pOut->PrintMessage("Pick up all the white squares!");

				}
				else if (Fig->getType() == "Hexagon") {
					picked_comb_no = combinations[8];
					pOut->PrintMessage("Pick up all the white Hexagons!");
				}
				else
				{
					picked_comb_no = combinations[9];
					pOut->PrintMessage("Pick up all the white Circles!");
				}

			}
			else if (Fig->GetGfxInfo().FillClr == BLUE)
			{
				if (Fig->getType() == "Rectangle")
				{
					picked_comb_no = combinations[10];
					pOut->PrintMessage("Pick up all the blue rectangles!");

				}
				else if (Fig->getType() == "Triangle")
				{
					picked_comb_no = combinations[11];
					pOut->PrintMessage("Pick up all the blue triangles!");

				}
				else if (Fig->getType() == "Square")
				{
					picked_comb_no = combinations[12];
					pOut->PrintMessage("Pick up all the blue squares!");

				}
				else if (Fig->getType() == "Hexagon") {
					picked_comb_no = combinations[13];
					pOut->PrintMessage("Pick up all the blue Hexagons!");
				}
				else
				{
					picked_comb_no = combinations[14];
					pOut->PrintMessage("Pick up all the blue Circles!");
				}


			}
			else if (Fig->GetGfxInfo().FillClr == GREEN)
			{
				if (Fig->getType() == "Rectangle")
				{
					picked_comb_no = combinations[15];
					pOut->PrintMessage("Pick up all the green rectangles!");

				}
				else if (Fig->getType() == "Triangle")
				{
					picked_comb_no = combinations[16];
					pOut->PrintMessage("Pick up all the green triangles!");

				}
				else if (Fig->getType() == "Square")
				{
					picked_comb_no = combinations[17];
					pOut->PrintMessage("Pick up all the green squares!");

				}
				else if (Fig->getType() == "Hexagon") {
					picked_comb_no = combinations[18];
					pOut->PrintMessage("Pick up all the green Hexagons!");
				}
				else
				{
					picked_comb_no = combinations[19];
					pOut->PrintMessage("Pick up all the green Circles!");
				}

			}
			else if (Fig->GetGfxInfo().FillClr == RED)
			{
				if (Fig->getType() == "Rectangle")
				{
					picked_comb_no = combinations[20];
					pOut->PrintMessage("Pick up all the red rectangles!");

				}
				else if (Fig->getType() == "Triangle")
				{
					picked_comb_no = combinations[21];
					pOut->PrintMessage("Pick up all the red triangles!");

				}
				else if (Fig->getType() == "Square")
				{
					picked_comb_no = combinations[22];
					pOut->PrintMessage("Pick up all the red squares!");

				}
				else if (Fig->getType() == "Hexagon") {
					picked_comb_no = combinations[23];
					pOut->PrintMessage("Pick up all the red Hexagons!");
				}
				else
				{
					picked_comb_no = combinations[24];
					pOut->PrintMessage("Pick up all the red Circles!");
				}


			}
			else if (Fig->GetGfxInfo().FillClr == ORANGE)
			{
				if (Fig->getType() == "Rectangle")
				{
					picked_comb_no = combinations[25];
					pOut->PrintMessage("Pick up all the orange rectangles!");

				}
				else if (Fig->getType() == "Triangle")
				{
					picked_comb_no = combinations[26];
					pOut->PrintMessage("Pick up all the orange triangles!");

				}
				else if (Fig->getType() == "Square")
				{
					picked_comb_no = combinations[27];
					pOut->PrintMessage("Pick up all the orange squares!");

				}
				else if (Fig->getType() == "Hexagon") {
					picked_comb_no = combinations[28];
					pOut->PrintMessage("Pick up all the orange Hexagons!");
				}
				else
				{
					picked_comb_no = combinations[29];
					pOut->PrintMessage("Pick up all the orange Circles!");
				}


				}
		}
		else
		{
			if (Fig->getType() == "Rectangle")
			{
				picked_comb_no = combinations[30];
				pOut->PrintMessage("Pick up all the unfilled rectangles!");

			}
			else if (Fig->getType() == "Triangle")
			{
				picked_comb_no = combinations[31];
				pOut->PrintMessage("Pick up all the unfilled triangles!");

			}
			else if (Fig->getType() == "Square")
			{
				picked_comb_no = combinations[32];
				pOut->PrintMessage("Pick up all the unfilled squares!");

			}
			else if (Fig->getType() == "Hexagon")
			{
				picked_comb_no = combinations[33];
				pOut->PrintMessage("Pick up all the unfilled hexagons!");

			}
			else if (Fig->getType()=="Circle")
			{
				picked_comb_no = combinations[34];
				pOut->PrintMessage("Pick up all the unfilled circles");

			}
		}
		while (picked_comb_no > 0)
		{

			pIn->GetPointClicked(P.x, P.y);
			if (P.y > UI.ToolBarHeight || P.x > (UI.MenuItemWidth * PLAY_ITM_COUNT))
			{
				clickedFig = pManager->GetFigure(P.x, P.y);
				if (clickedFig != NULL)
				{

					if (clickedFig->getType()=="Hexagon" && Fig->getType() == "Hexagon" && (clickedFig->GetGfxInfo().DrawClr == Fig->GetGfxInfo().DrawClr))
					{
						PrntScore(1);
						clickedFig->Hide();
						pManager->UpdateInterface();
						picked_comb_no--;
					}
					else if (clickedFig->getType() == "Rectangle" && Fig->getType() == "Rectangle" && (clickedFig->GetGfxInfo().FillClr == Fig->GetGfxInfo().FillClr))
					{
						PrntScore(1);
						clickedFig->Hide();
						pManager->UpdateInterface();
						picked_comb_no--;
					}
					else if (clickedFig->getType() == "Circle" && Fig->getType() == "Circle" && (clickedFig->GetGfxInfo().FillClr == Fig->GetGfxInfo().FillClr))
					{
						PrntScore(1);
						clickedFig->Hide();
						pManager->UpdateInterface();
						picked_comb_no--;
					}
					else if (clickedFig->getType() == "Triangle" && Fig->getType() == "Triangle" && (clickedFig->GetGfxInfo().FillClr == Fig->GetGfxInfo().FillClr))
					{
						PrntScore(1);
						clickedFig->Hide();
						pManager->UpdateInterface();
						picked_comb_no--;
					}
					else if (clickedFig->getType() == "Square" && Fig->getType() == "Square" && (clickedFig->GetGfxInfo().FillClr == Fig->GetGfxInfo().FillClr))
					{
						PrntScore(1);
						clickedFig->Hide();
						pManager->UpdateInterface();
						picked_comb_no--;
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
				picked_comb_no = -1;
			}
		}

		if (picked_comb_no == 0)
			PrntScore(3);

	}
	else pOut->PrintMessage("You must have at least two or more combinations to play pick by both!");
	for (int i = 0; i < pManager->GetFigCount(); i++) {
		pManager->ShowAll();
		pManager->UpdateInterface();
	}
	delete[] combinations;
}