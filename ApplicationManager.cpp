#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddHexAction.h"
#include "Actions\AddCircAction.h"
#include "Actions\AddSquAction.h"
#include "Actions\AddTriAction.h"
#include "Figures/CFigure.h"
#include "Actions/SelectAction.h"
#include"Actions/Switchtoplay.h"
#include"ApplicationManager.h"
#include"Actions/Exit.h"
#include"Actions/switchtodraw.h"
#include"Actions/Copy.h"
#include"Actions/Cut.h"
#include "Actions/SaveAction.h"


//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
		
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;
		case DRAW_SQUR:
			pAct = new AddSquAction(this);
		break;
		case DRAW_CIRC:
			pAct = new AddCircAction(this);
			break;
		case DRAW_TRI:
			pAct = new AddTriAction(this);
			break;
		case DRAW_HEX:
			pAct = new AddHexAction(this);
			break;
		case SELECT:
			pAct = new SelectAction(this);
			break;
		case TO_PLAY:
			pAct = new SwitchToPlay(this, mode);//1
			break;
		case TO_DRAW:
			pAct = new SwitchToDraw(this, &mode);//0
			break;
		case COPY:
			pAct = new Copy(this);
			break;
		case CUT:
			pAct = new Cut(this);
			break;
		case SAVE:
			pAct = new SaveAction(this);
			break;

		case EXIT:

			pAct = new Exit(this);
			
			///create ExitAction here
			
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//You may need to change this line depending to your implementation
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount)
	{
		FigList[FigCount++] = pFig;
		pFig->Setid(FigCount);
	}
}
////////////////////////////////////////////////////////////////////////////////////
CFigure* ApplicationManager::GetFigure(int x, int y) const
{
	CFigure* Figp = NULL;
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i]->pointchecker(x, y)) {
			Figp = FigList[i];
		}
	}
	return Figp;
}
 void ApplicationManager::setclipboard(CFigure* c)    //the clipboard to store on it figures 
{
	Clipboard = c;
}
 void ApplicationManager::setselected(CFigure* sf) {      //set the selcted figure. We need it on copy, cut, paste and delete actions
	 SelectedFig = sf;
 }
 CFigure *ApplicationManager::getselected() {
	 return SelectedFig;

 }
 int ApplicationManager::GetFigCount() {
	 return FigCount;
 }
 void ApplicationManager::UnselectAll() {
	 for (int i = 0; i < FigCount; i++) {
		 FigList[i]->SetSelected(false);
	 }
 }



 void ApplicationManager::SaveAll( string fname )
 {
	 
	 for (int i = 0; i < FigCount; i++)
	 {
		 
		 FigList[i]->Save(ofstream (fname));
	 }
 }

	 


	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL


	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
 void ApplicationManager::UpdateInterface() const
 {
	 for (int i = 0; i < FigCount; i++)
		 FigList[i]->Draw(pOut);
	 if (mode == 0) {
		 pOut->CreateDrawToolBar();
	 }
	 else if (mode == 1) {
		 pOut->CreatePlayToolBar();
	 }//Call Draw function (virtual member fn)
	 
 }
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}
