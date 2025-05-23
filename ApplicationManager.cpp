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
#include"Actions/Paste.h"
#include "SaveAction.h"
#include "Actions/PlayByBoth.h"
#include "Actions/PlayByType.h"
#include "Actions/PlayByColor.h"
#include "Actions/SendToBack.h"
#include "Actions/BringToFront.h"
#include"Actions/ClearAll.h"
#include "ChngFillCol.h"
#include "ChngBorCol.h"
#include "Sound.h"
#include "Deletefig.h"
#include "LoadAction.h"
#include "SaveAction.h"

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
		case Voice:
			if (V)
				V = false;
			else
				V = true;
			break;
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			S.play(1,V);
			break;
		case DRAW_SQUR:
			pAct = new AddSquAction(this);
			S.play(2,V);
			break;
		case DRAW_TRI:
			pAct = new AddTriAction(this);
			S.play(3,V);
			break;
		case DRAW_HEX:
			pAct = new AddHexAction(this);
			S.play(4, V);
			break;
		case DRAW_CIRC:
			pAct = new AddCircAction(this);
			S.play(5, V);
			break;
		case SELECT:
			pAct = new SelectAction(this);
			S.play(6, V);
			break;
		case CHANGE_BORDER_COLOR:
			pAct = new ChngBorCol(this);
			S.play(7, V);
			break;
		case CHANGE_FILING_COLOR:
			pAct = new ChngFillCol(this);
			S.play(8, V);
			break;
		case DELETE_FIG:
			pAct = new Deletefig(this);
			S.play(15, V);
			break;
		case CLR_ALL:
			pAct = new ClearAll(this);
			S.play(16, V);
			break;
		case COPY:
			pAct = new Copy(this);
			S.play(17, V);
			break;
		case CUT:
			pAct = new Cut(this);
			S.play(18, V);
			break;
		case PASTE:
			pAct = new Paste(this);
			S.play(19, V);
			break;
		case SNDTOFRNT:
			pAct = new BringToForward(this);
			S.play(20, V);
			break;
		case SNDTOBACK:
			pAct = new SendToBack(this);
			S.play(21, V);
			break;
		case SAVE:
			pAct = new SaveAction(this);
			S.play(22, V);
			break;
		case LOAD:
			pAct = new LoadAction(this);
			S.play(23, V);
			break;
		case TO_PLAY:
			pAct = new SwitchToPlay(this, mode);//1
			S.play(24, V);
			break;
		case TYPE:
			pAct = new PickByType(this);
			S.play(25, V);
			break;
		case FILLCLR:
			pAct = new PickByColor(this);
			S.play(26, V);
			break;
		case TYPENFILLCOLOR:
			pAct = new PickByBoth(this);
			S.play(27, V);
			break;
		case TO_DRAW:
			pAct = new SwitchToDraw(this, &mode);//0
			S.play(28, V);
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
		FigList[FigCount] = pFig;
		pFig->Setid(FigCount);
		FigCount++;

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
	 for (int i = 0; i < FigCount; i++) {
		 if (FigList[i]->IsSelected())
			 SelectedFig = FigList[i];
		 break;
	 }
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
	 int* colors = new int[7];
	 for (int i = 0; i < 6; i++)
		 colors[i] = 0;
	 for (int i = 0; i < FigCount; i++) {
		 if (FigList[i]->GetGfxInfo().isFilled) //counts color occurance.
		 {
			 if (FigList[i]->GetGfxInfo().FillClr == BLACK)
				 colors[0]++;
			 else if (FigList[i]->GetGfxInfo().FillClr == YELLOW)
				 colors[1]++;
			 else if (FigList[i]->GetGfxInfo().FillClr == BLUE)
				 colors[2]++;
			 else if (FigList[i]->GetGfxInfo().FillClr == GREEN)
				 colors[3]++;
			 else if (FigList[i]->GetGfxInfo().FillClr == RED)
				 colors[4]++;
			 else if (FigList[i]->GetGfxInfo().FillClr == ORANGE)
				 colors[5]++;
		 
		 }
		 else
		 {

			 colors[6]++;
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
	 int *combinations=new int[35];
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
			 else if (FigList[i]->GetGfxInfo().FillClr == YELLOW)
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
			 else if (FigList[i]->GetGfxInfo().FillClr == RED)
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
			 else if (FigList[i]->GetGfxInfo().FillClr == ORANGE)
			 {
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
		 else if(FigList[i]->GetGfxInfo().isFilled==false) {
			 if (FigList[i]->getType() == "Rectangle")
				 combinations[30]++;
			 else if (FigList[i]->getType() == "Triangle")
				 combinations[31]++;
			 else if (FigList[i]->getType() == "Square")
				 combinations[32]++;
			 else if (FigList[i]->getType() == "Hexagon")
				 combinations[33]++;
			 else
				 combinations[34]++;

		 }
	 }
	 return combinations;
 }



 void ApplicationManager::SortSTB(int index) {
	 if (index < 0 || index >= FigCount) {
		 pOut->PrintMessage("Invalid index");
	 }
	 else if (index == 0) {
		 pOut->PrintMessage("Figure is already at the back");
	 }
	 else {
		 CFigure* temp = FigList[index];
		 for (int i = index; i > 0; i--) {
			 FigList[i] = FigList[i - 1];
			 FigList[i]->Setid(i);
		 }
		 FigList[0] = temp;
		 FigList[0]->Setid(0);
	 }
 }

 void ApplicationManager::SortBTF(int index) {
	 if (index < 0 || index >= FigCount) {
		 pOut->PrintMessage("Invalid index");
	 }
	 else if (index == FigCount - 1) {
		 pOut->PrintMessage("Figure is already at the front");
	 }
	 else {
		 CFigure* temp = FigList[index];
		 for (int i = index; i < FigCount - 1; i++) {
			 FigList[i] = FigList[i + 1];
			 FigList[i]->Setid(i);
		 }
		 FigList[FigCount - 1] = temp;
		 FigList[FigCount - 1]->Setid(FigCount - 1);
	 }
 }


 void ApplicationManager::SaveAll(ofstream& prout) const
 {
	 prout << FigCount << endl;
	 for (int i = 0; i < FigCount; i++)
	 {
		 FigList[i]->Save(prout);

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
	 for (int i = 0; i < FigCount; i++) {
		 if(FigList[i]->IsHidden()==false)
		 FigList[i]->Draw(pOut);
	 }
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
void ApplicationManager::deletefig()
{
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i]->IsSelected())
		{
			delete FigList[i];
			FigCount--;
			for (int j = i; j < (FigCount);j++)
			{
				FigList[j] = FigList[j + 1];
			}


		}
	}
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
