#include "SelectAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

SelectAction::SelectAction(ApplicationManager* pApp) :Action(pApp)
{}

void SelectAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if(pManager->GetFigCount()==0)
		pOut->PrintMessage("Draw a figure first");
	else
		pOut->PrintMessage("Select a figure");

	//Read Point clicked
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->ClearStatusBar();

}



//Execute the action
void SelectAction::Execute()
{
	//This action needs to read some parameters first

	ReadActionParameters();
	if (pManager->GetFigCount() != 0) {
		CFigure* Figp = pManager->GetFigure(P1.x, P1.y);
		if (Figp != NULL) {
			if (Figp->IsSelected())
				Figp->SetSelected(false);
			else
				Figp->SetSelected(true);
		}
		else {
			pManager->UnselectAll();
		}
	}
	if(pManager->GetFigCount()==1){
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("");

	}



}
