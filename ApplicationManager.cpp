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
#include"../mostafa/Actions/Paste.h"
#include "Actions/SaveAction.h"
#include "Actions/PlayByBoth.h"



#include "Actions/PlayByType.h"
#include "Actions/PlayByColor.h"

#include"Actions/ClearAll.h"

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
		case PASTE:
			pAct = new Paste(this);
			break;

		case SAVE:
			pAct = new SaveAction(this);
			break;

		case TYPE:
			pAct = new PickByType(this);
			break;
		case FILLCLR:
			pAct = new PickByColor(this);

		case TYPENFILLCOLOR:
			pAct = new PickByBoth(this);
			break;
		case CLR_ALL:
			pAct = new ClearAll(this);
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
 CFigure* ApplicationManager::getclipboard()
 {
	 return Clipboard;
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
 CFigure* ApplicationManager::getRandomFig() {
	 return FigList[rand() % FigCount];
 }
 void ApplicationManager::ShowAll() {
	 for (int i = 0;i < FigCount;i++)
		 FigList[i]->Show();
 }

 void ApplicationManager::clear()
 {
	 for (int i = 0; i < FigCount; i++) {
		 delete FigList[i];
		 FigList[i] = NULL;
		 FigCount = 0;
	 }
 }

 void ApplicationManager::setiscut(bool ic)
 {
	 iscut = ic;
 }

 bool ApplicationManager::getiscut()
 {
	 return iscut;
 }

 void ApplicationManager::setgfxinfo(GfxInfo fig)
 {
	figcut = fig;
 }

 GfxInfo ApplicationManager::getfiginfo()
 {
	 return figcut;
 }

	 int* ApplicationManager::colors() {
	 int* colors = new int[6];
	 for (int i = 0; i < 6; i++)
		 colors[i] = 0;
	 for (int i = 0; i < FigCount; i++) {
		 if (FigList[i]->GetGfxInfo().isFilled) //counts color occurance.
		 {
			 if (FigList[i]->GetGfxInfo().FillClr == BLACK)
				 colors[0]++;
			 else if (FigList[i]->GetGfxInfo().FillClr == WHITE)
				 colors[1]++;
			 else if (FigList[i]->GetGfxInfo().FillClr == BLUE)
				 colors[2]++;
			 else if (FigList[i]->GetGfxInfo().FillClr == GREEN)
				 colors[3]++;
			 else if (FigList[i]->GetGfxInfo().FillClr == RED)
				 colors[4]++;
		 }
		 else
		 {

			 colors[5]++;
		 }
	 }
	 return colors;
 }
 int* ApplicationManager::types() {
	 int* types = new int[5];
	 for (int i = 0; i < 5; i++)
		 types[i] = 0;
	 for (int i = 0; i < FigCount; i++) {


		 if (FigList[i]->getType() == "Rectangle")
			 types[0]++;
		 else  if (FigList[i]->getType() == "Triangle")
			 types[1]++;
		 else  if (FigList[i]->getType() == "Square")
			 types[2]++;
		 else  if (FigList[i]->getType() == "Hexagon")
			 types[3]++;
		 else  if (FigList[i]->getType() == "Circle")
			 types[4]++;

	 }
	 return types;

 }
 int* ApplicationManager::combinations() {
	 int *combinations=new int[30];
	 for (int i = 0;i < 30;i++) {
		 combinations[i] = 0;
	 }
	 for (int i = 0; i < FigCount; i++) {
		 if (FigList[i]->GetGfxInfo().isFilled) //counts combinations occurance.
		 {
			 if (FigList[i]->GetGfxInfo().FillClr == BLACK)
			 {
				 if (FigList[i]->getType()=="Rectangle")
					 combinations[0]++;
				 else if (FigList[i]->getType() == "Triangle")
					 combinations[1]++;
				 else if (FigList[i]->getType() == "Square")
					 combinations[2]++;
				 else if (FigList[i]->getType() == "Hexagon")
					 combinations[3]++;
				 else
					 combinations[4]++;
			 }
			 else if (FigList[i]->GetGfxInfo().FillClr == WHITE)
			 {
				 if (FigList[i]->getType() == "Rectangle")
					 combinations[5]++;
				 else if (FigList[i]->getType() == "Triangle")
					 combinations[6]++;
				 else if (FigList[i]->getType() == "Square")
					 combinations[7]++;
				 else if (FigList[i]->getType() == "Hexagon")
					 combinations[8]++;
				 else
					 combinations[9]++;
			 }
			 else if (FigList[i]->GetGfxInfo().FillClr == BLUE)
			 {
				 if (FigList[i]->getType() == "Rectangle")
					 combinations[10]++;
				 else if (FigList[i]->getType() == "Triangle")
					 combinations[11]++;
				 else if (FigList[i]->getType() == "Square")
					 combinations[12]++;
				 else if (FigList[i]->getType() == "Hexagon")
					 combinations[13]++;
				 else
					 combinations[14]++;
			 }
			 else if (FigList[i]->GetGfxInfo().FillClr == GREEN)
			 {
				 if (FigList[i]->getType() == "Rectangle")
					 combinations[15]++;
				 else if (FigList[i]->getType() == "Triangle")
					 combinations[16]++;
				 else if (FigList[i]->getType() == "Square")
					 combinations[17]++;
				 else if (FigList[i]->getType() == "Hexagon")
					 combinations[18]++;
				 else
					 combinations[19]++;
			 }
			 else
			 {
				 if (FigList[i]->getType() == "Rectangle")
					 combinations[20]++;
				 else if (FigList[i]->getType() == "Triangle")
					 combinations[21]++;
				 else if (FigList[i]->getType() == "Square")
					 combinations[22]++;
				 else if (FigList[i]->getType() == "Hexagon")
					 combinations[23]++;
				 else
					 combinations[24]++;
			 }
		 }
		 else {
			 if (FigList[i]->getType() == "Rectangle")
				 combinations[25]++;
			 else if (FigList[i]->getType() == "Triangle")
				 combinations[26]++;
			 else if (FigList[i]->getType() == "Square")
				 combinations[27]++;
			 else if (FigList[i]->getType() == "Hexagon")
				 combinations[28]++;
			 else
				 combinations[29]++;

		 }
	 }
	 return combinations;
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
	 pOut->ClearDrawArea();
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

//Rectangle Count
int ApplicationManager::RecCount() {
	int cRec = 0;
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i]->IsSelected()&& FigList[i]->getType() == "Rectangle")
			cRec++;
	}
	return cRec;
}

//Hexagon Count
int ApplicationManager::HexCount() {
	int cHex = 0;
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i]->IsSelected() && FigList[i]->getType() == "Hexagon")
			cHex++;
	}
	return cHex;
}

//Circle Count
int ApplicationManager::CircCount() {
	int cCirc = 0;
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i]->IsSelected() && FigList[i]->getType() == "Circle")
			cCirc++;
	}
	return cCirc;
}

//Square Count
int ApplicationManager::SquCount() {
	int cSqu = 0;
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i]->IsSelected() && FigList[i]->getType() == "Square")
			cSqu++;
	}
	return cSqu;
}

//Triangle Count
int ApplicationManager::TriCount() {
	int cTri = 0;
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i]->IsSelected() && FigList[i]->getType() == "Triangle")
			cTri++;
	}
	return cTri;
}
int ApplicationManager::SelectedCount() {
	int c = 0;
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i]->IsSelected())
			c++;
	}
	return c;
}

////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;

}
