#include "Copy.h"
#include"../Figures/CFigure.h"

Copy::Copy(ApplicationManager* AM):Action(AM)
{
}
void Copy::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();

	pManager->setmessage("Figure has been copied");

}

void Copy::Execute()
{
	Output* pOut = pManager->GetOutput();
	if (pManager->getselected() != NULL) {
		ReadActionParameters();
		pManager->setclipboard(pManager->getselected());

	}
	else
		pManager->setmessage("Copy a Figure first");
}

Copy::~Copy()
{
}

