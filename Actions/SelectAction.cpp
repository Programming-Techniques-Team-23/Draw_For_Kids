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
	Output* pOut = pManager->GetOutput();
	CFigure* Figp = pManager->GetFigure(P1.x, P1.y);
	if (pManager->GetFigCount() != 0) {
		if (Figp != NULL) {
			if (Figp->IsSelected())
				Figp->SetSelected(false);
			else
			{
				Figp->SetSelected(true);
				pManager->setselected(Figp);
			}
		}
		else {
			pManager->UnselectAll();
		}
	}
	if(pManager->SelectedCount()>1){
		string message = "Selected: ";
		int totalSelected = 0;
		if (pManager->RecCount() > 0) {
			message += to_string(pManager->RecCount()) + " Rectangle(s), ";
			totalSelected += pManager->RecCount();
		}
		if (pManager->TriCount() > 0) {
			message += to_string(pManager->TriCount()) + " Triangle(s), ";
			totalSelected += pManager->TriCount();
		}
		if (pManager->HexCount() > 0) {
			message += to_string(pManager->HexCount()) + " Hexagon(s), ";
			totalSelected += pManager->HexCount();
		}
		if (pManager->CircCount() > 0) {
			message += to_string(pManager->CircCount()) + " Circle(s), ";
			totalSelected += pManager->CircCount();
		}
		if (pManager->SquCount() > 0) {
			message += to_string(pManager->SquCount()) + " Square(s), ";
			totalSelected += pManager->SquCount();
		}
		if (totalSelected > 0) {
			message.pop_back(); 
			message.pop_back();
		}
		pOut->PrintMessage(message);
	}
	else if(pManager->SelectedCount() == 1){
		pOut->PrintMessage(Figp->Details());
	}
}
