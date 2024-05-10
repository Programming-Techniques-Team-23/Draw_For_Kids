#include "SendToBack.h"
#include "..\ApplicationManager.h"

#include "..\GUI/Input.h"
#include "..\GUI/output.h"


SendToBack::SendToBack(ApplicationManager* pApp) :Action(pApp)
{
}
//Read parameters for the STB action
void SendToBack::ReadActionParameters()
{
	//Checks if a single figure is selected
	if (pManager->SelectedCount()==1) {
		//a pointer to the selected Fig.
		SelectedFig = pManager->getselected();
		//if there is a figure selected store its id
		SelectedID = pManager->getselected()->getid();
	}
	else
		//NULL if no figures, or more than one figure are selected
		SelectedFig = NULL;
}
//excute the STB action
void SendToBack::Execute()
{
	ReadActionParameters();
	//Get a Pointer to the Output Interface
	Output* pOut = pManager->GetOutput();
	// if one figure is selected send it to the back
	if (SelectedFig)
	{
		pManager->SortSTB(SelectedID);
		pOut->PrintMessage("Figure sent to back");
	}
	//else print one figure needs to be selected
	else
		pOut->PrintMessage("Send To Back : One figure needs to be selected");

}