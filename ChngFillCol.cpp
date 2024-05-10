#include "ApplicationManager.h"
#include "ChngFillCol.h"
#include "Actions/Action.h"
#include "GUI\input.h"
#include "GUI\Output.h"
#include "Figures/CFigure.h"
ChngFillCol::ChngFillCol(ApplicationManager* pApp,bool p, color C) :Action(pApp)
{
	Fill = p;
	CLR = C;
}
void ChngFillCol::ReadActionParameters(){
	Output* pOut = pManager->GetOutput();
	if (pManager->GetFigCount() == 0) {
		pOut->PrintMessage("Draw a figure first");
	}
	else if (pManager->SelectedCount() == 0) {
		pOut->PrintMessage("Select a figure first");
	}
	else {
		pOut->PrintMessage("Choose a Color");
	}
}
void ChngFillCol::Execute() {
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	if (CLR != PURPLE) {
		if (!Fill) 
			pOut->PrintMessage("Click on change Border/Fill icons first");
		else
			pManager->getselected()->ChngFillClr(CLR);
	}
}