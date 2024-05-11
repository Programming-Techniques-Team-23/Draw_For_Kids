#include "ApplicationManager.h"
#include "ChngBorCol.h"
#include "Actions/Action.h"
#include "GUI\input.h"
#include "GUI\Output.h"
#include "Figures/CFigure.h"
#include "DEFS.h"
ChngBorCol::ChngBorCol(ApplicationManager* pApp) :Action(pApp)
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
	}
}
void ChngBorCol::ReadActionParameters() {
	Input* pIn = pManager->GetInput();
	ActionType ActType = pIn->GetUserAction();
	Output* pOut = pManager->GetOutput();
	if (pManager->SelectedCount() == 1) {
		pOut->PrintMessage("Choose a Color");
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
			CLR = BLU;
			break;
		case RD:
			CLR = RED;
			break;
		}
	}
}
void ChngBorCol::Execute() {
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	if (CLR != PURPLE)
		pManager->getselected()->ChngDrawClr(CLR);
}