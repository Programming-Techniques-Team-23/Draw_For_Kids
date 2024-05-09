#include "ClearAll.h"
#include"../ApplicationManager.h"

ClearAll::ClearAll(ApplicationManager* AM):Action(AM)
{
}

void ClearAll::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Clear All");
}

void ClearAll::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	pManager->clear();
	pOut->ClearDrawArea();
}

ClearAll::~ClearAll()
{
}
