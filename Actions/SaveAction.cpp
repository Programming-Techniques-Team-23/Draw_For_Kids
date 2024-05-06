#include "SaveAction.h"
#include"../Figures/CFigure.h"
#include<fstream>
#include"../ApplicationManager.h"

SaveAction::SaveAction(ApplicationManager* AM) : Action(AM)
{}

void SaveAction::ReadActionParameters()
{
}


void SaveAction::Execute()
{
	Input* pIn = pManager->GetInput();
	Output* pout = pManager->GetOutput();
	pout->PrintMessage("Enter File Name:");
	string name;
	pIn->GetString(name);

	ofstream fout(name);
	
	ApplicationManager::SaveAll(name);
	ApplicationManager::SaveAll();
	fout.close();

}
