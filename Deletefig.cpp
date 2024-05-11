#include "Deletefig.h"

#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"

Deletefig::Deletefig(ApplicationManager* AM) : Action(AM)
{
}

void Deletefig::ReadActionParameters()
{
	
}

void Deletefig::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Deleted selecteded figures");

	pManager->deletefig();
	pOut->ClearDrawArea();
}
