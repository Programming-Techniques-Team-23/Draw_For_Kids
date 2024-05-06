#include "Switchtoplay.h"
#include"../ApplicationManager.h"
#include"Action.h"

SwitchToPlay::SwitchToPlay(ApplicationManager*AM,int &mode):Action(AM)
{
	mode = 1;
}
void SwitchToPlay::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("welcome to playmode");
}

void SwitchToPlay::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();



}

SwitchToPlay::~SwitchToPlay()
{
}