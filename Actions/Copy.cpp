#include "Copy.h"
#include"../Figures/CFigure.h"

Copy::Copy(ApplicationManager* AM):Action(AM)
{
}
void Copy::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Figure has been copied");
}

void Copy::Execute()
{
	Output* pOut = pManager->GetOutput();
	if (pManager->getselected() != NULL) {
		ReadActionParameters();
		pManager->setclipboard(pManager->getselected());

	}
	else
		pOut->PrintMessage("Copy a Figure first");
}

Copy::~Copy()
{
}

