#include "PickByType.h"
#include "ApplicationManager.h"
#include "Figures/CRectangle.h"
#include "Figures/CCircle.h"
#include "Figures/CTriangle.h"
#include "GUI/Input.h"
#include "GUI/Output.h"


PickByType::PickByType(ApplicationManager* pApp) :Action(pApp)
{
	FigureNumbers = 0;
	Correct = 0;
	Wrong = 0;
	for (int i = 0; i < 4; i++)
		Figures[i] = 0;
}
void PickByType::PrntScore(int S)
{
	Output* pOut = pManager->GetOutput();

	string message;
	if (S == 1)
	{
		Correct++;
		message = "Right!, Your score is: " + to_string(Correct) + " Right, and " + to_string(Correct) + " Wrong.";
	}
	else 	if (S == 2)
	{
		Wrong++;
		message = "Wrong!, Your score is: " + to_string(Correct) + " Right, and " + to_string(Wrong) + " Wrong.";
	}
	else
		message = "YOU WIN!, Your score is: " + to_string(Correct) + " Right, and " + to_string(Wrong) + " Wrong.";
	pOut->PrintMessage(message);


}

PickByType::~PickByType()
{
}

void PickByType::ReadActionParameters()
{
	for (int i = 0; i < pManager->GetFigCount(); i++)
	{
		Fig = pManager->DrawnFigs(i);
		if (dynamic_cast<CRectangle*>(Fig))
			Figures[0]++;
		else if (dynamic_cast<CTriangle*>(Fig))
			Figures[1]++;
		else if (dynamic_cast<CCircle*>(Fig))
			Figures[2]++;
		else Figures[3]++;




	}		for (int i = 0; i < 4; i++)
		if (Figures[i] != 0)FigureNumbers++;
}

void PickByType::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ReadActionParameters();
	if (FigureNumbers > 1)
	{
		CFigure* clickedFig;
		//Randomize
		RandomFigureNumbers = rand() % pManager->GetFigCount();
		//counting fig instances
		Fig = pManager->DrawnFigs(RandomFigureNumbers);
		if (dynamic_cast<CRectangle*>(Fig))
		{
			PickedFigureNumbers = Figures[0];
			pOut->PrintMessage("Pick up all the rectangles!");

		}
		else if (dynamic_cast<CTriangle*>(Fig))
		{
			PickedFigureNumbers = Figures[1];
			pOut->PrintMessage("Pick up all the triangles!");

		}
		else if (dynamic_cast<CCircle*>(Fig))
		{
			PickedFigureNumbers = Figures[2];
			pOut->PrintMessage("Pick up all the circles!");

		}
		else
		
			PickedFigureNumbers = Figures[3];
			pOut->PrintMessage("Pick up all the lines!");

		}
		while (PickedFigureNumbers > 0)
		{
			{

				pIn->GetPointClicked(P.x, P.y);
				if (P.y > UI.ToolBarHeight || P.x > (UI.MenuItemWidth * PLAY_ITM_COUNT))
				{
					clickedFig = pManager->GetFigure(P.x, P.y);
					if (clickedFig != NULL)
					{

						
						else if ((dynamic_cast<CTrig*>(clickedFig)) && (dynamic_cast<CTrig*>(Fig)))
						{
							PrntScore(1);
							clickedFig->Hide();
							pManager->UpdateInterface();
							PickedFigureNumbers--;
						}
						else if ((dynamic_cast<CCirc*>(clickedFig)) && (dynamic_cast<CCirc*>(Fig)))
						{
							PrntScore(1);
							clickedFig->Hide();
							pManager->UpdateInterface();
							PickedFigureNumbers--;
						}
						else if ((dynamic_cast<CRectangle*>(clickedFig)) && (dynamic_cast<CRectangle*>(Fig)))
						{
							PrntScore(1);
							clickedFig->Hide();
							pManager->UpdateInterface();
							PickedFigureNumbers--;
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
					PickedFigureNumbers = -1;
				}


			}
			if (PickedFigureNumbers == 0)
				PrntScore(3);



		}
	}
	else
		pOut->PrintMessage("You must have at least two or more figures to play to play pick by figure!");
	for (int i = 0; i < pManager->getFigCount(); i++)
		pManager->DrawnFigs(i)->Show();
	pManager->UpdateInterface();





}
