#include "PlayByColor.h"
#include "..\CMUgraphicsLib\colors.h" 
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"


color PickByColor::AssignColor(CFigure* Fig)
{

	if (Fig->GetGfxInfo().isFilled)
	{
		if (Fig->GetGfxInfo().FillClr == BLACK)
			return BLACK;
		else if (Fig->GetGfxInfo().FillClr == WHITE)
			return WHITE;
		else if (Fig->GetGfxInfo().FillClr == BLUE)
			return BLUE;
		else if (Fig->GetGfxInfo().FillClr == GREEN)
			return GREEN;
		else if (Fig->GetGfxInfo().FillClr == RED)
			return RED;
	}
	return TURQUOISE;
}

void PickByColor::PrntScore(int S)
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

PickByColor::PickByColor(ApplicationManager* pApp) :Action(pApp)
{
	no_colors = 0;
	wrgSel = 0;
	rigSel = 0;

}


PickByColor::~PickByColor()
{
}

void PickByColor::ReadActionParameters()
{
	int* colours = pManager->colors();



	for (int i = 0; i < 6; i++)
		if (colours[i] != 0)
			no_colors++;


}


void PickByColor::Execute()
{

	int* colours = pManager->colors();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ReadActionParameters();

	if (no_colors > 1)
	{

		CFigure* clickedFig;
		CFigure* Fig = pManager->getRandomFig();


		if (Fig->GetGfxInfo().isFilled)
		{
			if (Fig->GetGfxInfo().FillClr == BLACK)
			{
				picked_color_no = colours[0];
				pOut->PrintMessage("Pick up figures colored black!");
			}
			else if (Fig->GetGfxInfo().FillClr == WHITE)
			{
				picked_color_no = colours[1];
				pOut->PrintMessage("Pick up figures colored white!");
			}
			else if (Fig->GetGfxInfo().FillClr == BLUE)
			{
				picked_color_no = colours[2];
				pOut->PrintMessage("Pick up figures colored blue!");

			}
			else if (Fig->GetGfxInfo().FillClr == GREEN)
			{
				picked_color_no = colours[3];
				pOut->PrintMessage("Pick up figures colored green!");

			}
			else if (Fig->GetGfxInfo().FillClr == RED)
			{
				picked_color_no = colours[4];
				pOut->PrintMessage("Pick up figures colored red!");

			}
		}
		else
		{


			picked_color_no = colours[5];
			pOut->PrintMessage("Pick up uncolored hollow figures!");



		}

		while (picked_color_no > 0)
		{

			pIn->GetPointClicked(P.x, P.y);
			if (P.y > UI.ToolBarHeight || P.x > (UI.MenuItemWidth * PLAY_ITM_COUNT))
			{
				clickedFig = pManager->GetFigure(P.x, P.y);
				if (clickedFig != NULL)
				{

					if ((!(Fig->GetGfxInfo().isFilled)) && (!(clickedFig->GetGfxInfo().isFilled)))
					{
						PrntScore(1);
						clickedFig->Hide();
						pManager->UpdateInterface();
						picked_color_no--;
					}
					else if (clickedFig->GetGfxInfo().isFilled && clickedFig->GetGfxInfo().FillClr == AssignColor(Fig))
					{
						PrntScore(1);
						clickedFig->Hide();
						pManager->UpdateInterface();
						picked_color_no--;
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
				picked_color_no = -1;
			}


		}
		if (picked_color_no == 0)
			PrntScore(3);
	}
	else 			pOut->PrintMessage("You must have at least two or more colors to play pick by color!");
	for (int i = 0; i < pManager->GetFigCount(); i++) {
		pManager->ShowAll();
		pManager->UpdateInterface();
	}
}
