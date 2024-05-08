#include "SaveAction.h"
#include"../Figures/CFigure.h"
#include<fstream>
#include"../ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

SaveAction::SaveAction(ApplicationManager* AM) : Action(AM)
{
}

void SaveAction::ReadActionParameters()
{
}

void SaveAction::Execute()
{
	Input* pIn = pManager->GetInput() ;
	Output* pout = pManager->GetOutput() ;
	pout->PrintMessage("Enter File Name:") ;

	name =pIn->GetString(pout) ;
	ofstream fout(name) ;
	
	pManager->SaveAll(name) ;
	
	fout.close();

}
