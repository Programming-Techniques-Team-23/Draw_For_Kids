#include "ApplicationManager.h"
#include "ChngFillCol.h"
#include "Actions/Action.h"
#include "GUI\input.h"
#include "GUI\Output.h"
#include "Figures/CFigure.h"
#include "DEFS.h"
ChngFillCol::ChngFillCol(ApplicationManager* pApp) :Action(pApp)
{
	CLR = PURPLE;
	Output* pOut = pManager->GetOutput();
	if (pManager->GetFigCount() == 0) {
		pOut->PrintMessage("Draw a figure first");
		return;
	}
	else {
		if (pManager->SelectedCount() == 0) {
			pOut->PrintMessage("Select a figure first");
			return;
		}
		else if (pManager->SelectedCount() > 1) {
			pOut->PrintMessage("Choose only 1 figure");
			return;
		}
		else {
			pOut->PrintMessage("Choose a Color");
		}
	}
}
void ChngFillCol::ReadActionParameters(){
	Input* pIn = pManager->GetInput();
	ActionType ActType = pIn->GetUserAction();
	if (pManager->SelectedCount() == 1) {
			switch (ActType) {
			case BLCK:
				CLR = BLACK;
				break;
			case YEL:
				CLR = YELLOW;
				break;
			case ORG:
				CLR = ORANGE;
				break;
			case GRN:
				CLR = GREEN;
				break;
			case BLU:
				CLR = BLUE;
				break;
			case RD:
				CLR = RED;
				break;
			}
	}
}
void ChngFillCol::Execute() {
	ReadActionParameters();
	if(CLR==BLACK||CLR==YELLOW||CLR==GREEN||CLR==BLUE||CLR==RED||CLR==ORANGE && pManager->SelectedCount() == 1)
		pManager->getselected()->ChngFillClr(CLR);
}