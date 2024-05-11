#pragma once
#include "SaveAction.h"
#include"../Figures/CFigure.h"
#include<fstream>
#include"../ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

SaveAction::SaveAction(ApplicationManager* pApp) : Action(pApp)
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

	name =pIn->GetString(pout);
	
   fout.open( name + ".txt", ios::out);
	

	
		pManager->SaveAll(fout);
		
	fout.close();

	pout->PrintMessage("File Saved Successfully");
}
