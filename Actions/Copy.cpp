#include "Copy.h"
#include"../Figures/CFigure.h"

Copy::Copy(ApplicationManager* AM):Action(AM)
{
}
void Copy::ReadActionParameters()
{
	
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	
}

void Copy::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	 
	if (pManager->getselected() != NULL) {
	
		pManager->setclipboard(pManager->getselected());
		pOut->PrintMessage("Figure has been copied");

	}
	else
		pOut->PrintMessage("Copy a Figure first");
	return;
}

Copy::~Copy()
{
}

