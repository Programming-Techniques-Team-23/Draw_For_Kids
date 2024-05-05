#include "Switchtoplay.h"
#include"../ApplicationManager.h"
#include"Action.h"

SwitchToPlay::SwitchToPlay(ApplicationManager*AM):Action(AM)
{
}
void SwitchToPlay::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pManager->setmessage("welcome to playmode");

}

void SwitchToPlay::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();



}

SwitchToPlay::~SwitchToPlay()
{
}