#include "PlayByBoth.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CHexagon.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\CCircle.h"
#include "Figures/CSquare.h"
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
	for (int i = 0; i < 23; i++)
		combinations[i] = 0;
}


PickByBoth::~PickByBoth()
{

}

void PickByBoth::ReadActionParameters()
{
	for (int i = 0; i < pManager->GetFigCount(); i++) {
		Fig = pManager->DrawnFigs(i);
		if ((Fig->GetGfxInfo().isFilled) && !(dynamic_cast<CTriangle*>(Fig) || dynamic_cast<CHexagon*>(Fig) ||
		dynamic_cast<CSquare*>(Fig) || dynamic_cast<CCircle*>(Fig) || dynamic_cast<CRectangle*>(Fig))) //counts combinations occurance.
		{
			if (Fig->GetGfxInfo().FillClr == BLACK)
			{
				if (dynamic_cast<CRectangle*>(Fig))
					combinations[0]++;
				else if (dynamic_cast<CTriangle*>(Fig))
					combinations[1]++;
				else if (dynamic_cast<CSquare*>(Fig))
					combinations[2]++;
				else if (dynamic_cast<CHexagon*>(Fig))
					combinations[3]++;
				else
					combinations[4]++;
			}
			else if (Fig->GetGfxInfo().FillClr == WHITE)
			{
				if (dynamic_cast<CRectangle*>(Fig))
					combinations[5]++;
				else if (dynamic_cast<CTriangle*>(Fig))
					combinations[6]++;
				else if (dynamic_cast<CSquare*>(Fig))
					combinations[7]++;
				else if (dynamic_cast<CHexagon*>(Fig))
					combinations[8]++;
				else
					combinations[9]++;
			}
			else if (Fig->GetGfxInfo().FillClr == BLUE)
			{
				if (dynamic_cast<CRectangle*>(Fig))
					combinations[10]++;
				else if (dynamic_cast<CTriangle*>(Fig))
					combinations[11]++;
				else if (dynamic_cast<CSquare*>(Fig))
					combinations[12]++;
				else if (dynamic_cast<CHexagon*>(Fig))
					combinations[13]++;
				else
					combinations[14]++;
			}
			else if (Fig->GetGfxInfo().FillClr == GREEN)
			{
				if (dynamic_cast<CRectangle*>(Fig))
					combinations[15]++;
				else if (dynamic_cast<CTriangle*>(Fig))
					combinations[16]++;
				else if (dynamic_cast<CSquare*>(Fig))
					combinations[17]++;
				else if (dynamic_cast<CHexagon*>(Fig))
					combinations[18]++;
				else
					combinations[19]++;
			}
			else
			{
				if (dynamic_cast<CRectangle*>(Fig))
					combinations[20]++;
				else if (dynamic_cast<CTriangle*>(Fig))
					combinations[21]++;
				else if (dynamic_cast<CSquare*>(Fig))
					combinations[22]++;
				else if (dynamic_cast<CHexagon*>(Fig))
					combinations[23]++;
				else
					combinations[24]++;
			}
		}
		else {
			if (dynamic_cast<CRectangle*>(Fig))
				combinations[25]++;
			else if (dynamic_cast<CTriangle*>(Fig))
				combinations[26]++;
			else if (dynamic_cast<CSquare*>(Fig))
				combinations[27]++;
			else if (dynamic_cast<CHexagon*>(Fig))
				combinations[28]++;
			else
				combinations[29]++;
		
		}
	}

	for (int i = 0; i < 30; i++)
		if (combinations[i] != 0)
			no_combs++;


}

void PickByBoth::Execute()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ReadActionParameters();

	if (no_combs > 1)
	{
		//Figure to be hidden
		CFigure* clickedFig;
		//Randomize
		rand_fig_no = rand() % pManager->GetFigCount();
		//Counting the the color instances.
		Fig = pManager->DrawnFigs(rand_fig_no);
		if ((Fig->GetGfxInfo().isFilled) && !(dynamic_cast<CTriangle*>(Fig) || dynamic_cast<CHexagon*>(Fig) ||
			dynamic_cast<CSquare*>(Fig) || dynamic_cast<CCircle*>(Fig)))
		{
			if (Fig->GetGfxInfo().FillClr == BLACK)
			{
				if (dynamic_cast<CRectangle*>(Fig))
				{
					picked_comb_no = combinations[0];
					pOut->PrintMessage("Pick up all the black rectangles!");

				}
				else if (dynamic_cast<CTriangle*>(Fig))
				{
					picked_comb_no = combinations[1];
					pOut->PrintMessage("Pick up all the black triangles!");

				}
				else if (dynamic_cast<CSquare*>(Fig))
				{
					picked_comb_no = combinations[2];
					pOut->PrintMessage("Pick up all the black squares!");

				}
				else if (dynamic_cast<CHexagon*>(Fig)) {
					picked_comb_no = combinations[3];
					pOut->PrintMessage("Pick up all the black Hexagons!");
				}
				else
				{
					picked_comb_no = combinations[4];
					pOut->PrintMessage("Pick up all the black Circles!");
				}

			}
			else if (Fig->GetGfxInfo().FillClr == WHITE)
			{
				if (dynamic_cast<CRectangle*>(Fig))
				{
					picked_comb_no = combinations[5];
					pOut->PrintMessage("Pick up all the white rectangles!");

				}
				else if (dynamic_cast<CTriangle*>(Fig))
				{
					picked_comb_no = combinations[6];
					pOut->PrintMessage("Pick up all the white triangles!");

				}
				else if (dynamic_cast<CSquare*>(Fig))
				{
					picked_comb_no = combinations[7];
					pOut->PrintMessage("Pick up all the white squares!");

				}
				else if (dynamic_cast<CHexagon*>(Fig)) {
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
				if (dynamic_cast<CRectangle*>(Fig))
				{
					picked_comb_no = combinations[10];
					pOut->PrintMessage("Pick up all the blue rectangles!");

				}
				else if (dynamic_cast<CTriangle*>(Fig))
				{
					picked_comb_no = combinations[11];
					pOut->PrintMessage("Pick up all the blue triangles!");

				}
				else if (dynamic_cast<CSquare*>(Fig))
				{
					picked_comb_no = combinations[12];
					pOut->PrintMessage("Pick up all the blue squares!");

				}
				else if (dynamic_cast<CHexagon*>(Fig)) {
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
				if (dynamic_cast<CRectangle*>(Fig))
				{
					picked_comb_no = combinations[15];
					pOut->PrintMessage("Pick up all the green rectangles!");

				}
				else if (dynamic_cast<CTriangle*>(Fig))
				{
					picked_comb_no = combinations[16];
					pOut->PrintMessage("Pick up all the green triangles!");

				}
				else if (dynamic_cast<CSquare*>(Fig))
				{
					picked_comb_no = combinations[17];
					pOut->PrintMessage("Pick up all the green squares!");

				}
				else if (dynamic_cast<CHexagon*>(Fig)) {
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
				if (dynamic_cast<CRectangle*>(Fig))
				{
					picked_comb_no = combinations[20];
					pOut->PrintMessage("Pick up all the red rectangles!");

				}
				else if (dynamic_cast<CTriangle*>(Fig))
				{
					picked_comb_no = combinations[21];
					pOut->PrintMessage("Pick up all the red triangles!");

				}
				else if (dynamic_cast<CSquare*>(Fig))
				{
					picked_comb_no = combinations[22];
					pOut->PrintMessage("Pick up all the red squares!");

				}
				else if (dynamic_cast<CHexagon*>(Fig)) {
					picked_comb_no = combinations[23];
					pOut->PrintMessage("Pick up all the red Hexagons!");
				}
				else
				{
					picked_comb_no = combinations[24];
					pOut->PrintMessage("Pick up all the red Circles!");
				}


			}
		}
		else
		{
			if (dynamic_cast<CRectangle*>(Fig))
			{
				picked_comb_no = combinations[25];
				pOut->PrintMessage("Pick up all the unfilled rectangles!");

			}
			else if (dynamic_cast<CTriangle*>(Fig))
			{
				picked_comb_no = combinations[26];
				pOut->PrintMessage("Pick up all the unfilled triangles!");

			}
			else if (dynamic_cast<CSquare*>(Fig))
			{
				picked_comb_no = combinations[27];
				pOut->PrintMessage("Pick up all the unfilled squares!");

			}
			else if (dynamic_cast<CHexagon*>(Fig))
			{
				picked_comb_no = combinations[28];
				pOut->PrintMessage("Pick up all the unfilled hexagons!");

			}
			else if (dynamic_cast<CCircle*>(Fig))
			{
				picked_comb_no = combinations[29];
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

					if (dynamic_cast<CHexagon*>(Fig) && dynamic_cast<CHexagon*>(clickedFig) && (clickedFig->GetGfxInfo().DrawClr == Fig->GetGfxInfo().DrawClr))
					{
						PrntScore(1);
						clickedFig->Hide();
						pManager->UpdateInterface();
						picked_comb_no--;
					}
					else if (dynamic_cast<CRectangle*>(Fig) && dynamic_cast<CRectangle*>(clickedFig) && (clickedFig->GetGfxInfo().FillClr == Fig->GetGfxInfo().FillClr))
					{
						PrntScore(1);
						clickedFig->Hide();
						pManager->UpdateInterface();
						picked_comb_no--;
					}
					else if (dynamic_cast<CCircle*>(Fig) && dynamic_cast<CCircle*>(clickedFig) && (clickedFig->GetGfxInfo().FillClr == Fig->GetGfxInfo().FillClr))
					{
						PrntScore(1);
						clickedFig->Hide();
						pManager->UpdateInterface();
						picked_comb_no--;
					}
					else if (dynamic_cast<CTriangle*>(Fig) && dynamic_cast<CTriangle*>(clickedFig) && (clickedFig->GetGfxInfo().FillClr == Fig->GetGfxInfo().FillClr))
					{
						PrntScore(1);
						clickedFig->Hide();
						pManager->UpdateInterface();
						picked_comb_no--;
					}
					else if (dynamic_cast<CSquare*>(Fig) && dynamic_cast<CSquare*>(clickedFig) && (clickedFig->GetGfxInfo().FillClr == Fig->GetGfxInfo().FillClr))
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
	for (int i = 0; i < pManager->GetFigCount(); i++)
		pManager->DrawnFigs(i)->Show();
	pManager->UpdateInterface();
}
