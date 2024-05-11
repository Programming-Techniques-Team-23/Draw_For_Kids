#include "Cut.h"
#include"../ApplicationManager.h"
#include"../Figures/CFigure.h"

Cut::Cut(ApplicationManager* AM):Action(AM)
{
}

void Cut::ReadActionParameters()
{
	//Get a Pointer to the Output Interfaces
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Selected Figure is Cut");

}

void Cut::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	if ((pManager->getselected() != NULL && pManager->SelectedCount() != 0)) {
		pManager->setiscut(true);
		figcut = pManager->getselected()->GetGfxInfo();
		pManager->setgfxinfo(figcut);

		
		pManager->getselected()->ChngDrawClr(GRAY);
		pManager->getselected()->ChngFillClr(GRAY);
		
		pManager->setclipboard(pManager->getselected());
	}
	else
		pOut->PrintMessage("Select a Figure First");

}

Cut::~Cut()
{
}

