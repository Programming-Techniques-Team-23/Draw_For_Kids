#include "ClearAll.h"
#include"../ApplicationManager.h"

ClearAll::ClearAll(ApplicationManager* AM):Action(AM)
{
}

void ClearAll::ReadActionParameters()
{

}

void ClearAll::Execute()
{
	Output* pOut = pManager->GetOutput();
	pOut->ClearDrawArea();
}

ClearAll::~ClearAll()
{
}
