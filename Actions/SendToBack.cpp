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
		Output* pOut = pManager->GetOutput();

		if (SelectedFig)
		{
			pManager->SortSTB(SelectedID);
			pOut->PrintMessage("Figure sent to back");

		}
		else
		{
			pOut->PrintMessage("Send To Back: One figure needs to be selected");
		}
	}


