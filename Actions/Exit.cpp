#include "Exit.h"
#include"../ApplicationManager.h"

Exit::Exit(ApplicationManager* AM):Action(AM)
{
}

void Exit::ReadActionParameters()
{
}

void Exit::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("BYE");
}




