#include "Paste.h"
#include"../ApplicationManager.h"

Paste::Paste(ApplicationManager* AM):Action(AM)
{
}

void Paste::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Coose a point to Paste in");
	pIn->GetPointClicked(P.x, P.y);
}

void Paste::Execute()
{


}
