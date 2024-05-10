#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include "Sound.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:

	int FigCount; //Figure Count
	int mode; //Actual number of figures
	string message; //Actual number of figures

	GfxInfo figcut;
  
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	CFigure* SelectedFig; //Pointer to the selected figure

	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;
	bool iscut = false;
	Sound S;
	bool Bor = false;
	bool Fill = false;
	CFigure* Clipboard;  //Pointer to copied/cut figure
	bool V = true;
public:	
	ApplicationManager(); 
	~ApplicationManager();
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
		
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	
    void setclipboard(CFigure* c);
	CFigure* getclipboard();
	void setselected(CFigure*sf);
	CFigure* getselected();
	CFigure* const* GetSelectedFigures() const;		//Returns a pointer to the SelectedFigs array
	void SortSTB(int index);
	void SortBTF(int index);
	int GetFigCount();
	void UnselectAll();
	int* combinations();
	int* types();
	int* colors();
	void SaveAll(string OutFile);
	int RecCount();
	int HexCount();
	int CircCount();
	int SquCount();
	int TriCount();
	int SelectedCount();
	CFigure* getRandomFig();
	void ShowAll();
	void Loadall(string infile);
	void deletefig ();
	void clear();
	void setiscut(bool ic);
	bool getiscut();
	void setgfxinfo(GfxInfo fig);
	GfxInfo getfiginfo();
};

#endif
