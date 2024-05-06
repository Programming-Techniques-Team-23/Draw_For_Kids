#include "switchtodraw.h"
#include"../ApplicationManager.h"

SwitchToDraw::SwitchToDraw(ApplicationManager* AM, int *mode):Action(AM)
{
	mode = 0;
	Mode = mode;
}

void SwitchToDraw::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("welcome to DRAW MODE");
}

void SwitchToDraw::Execute()
{
	Output* pOut = pManager->GetOutput();

	ReadActionParameters();
	*Mode = 0;
}

SwitchToDraw::~SwitchToDraw()
{
}
