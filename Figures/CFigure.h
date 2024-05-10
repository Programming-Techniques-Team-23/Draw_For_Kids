#ifndef CFIGURE_H
#define CFIGURE_H
#include<fstream>

#include "..\defs.h"
#include "..\GUI\Output.h"

//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	string Type;  //Type of the figure
	bool PlayHidden;		//hides figures in playmode.
	string DrawColor;
	string FillColor;

	/// Add more parameters if needed.

public:
	CFigure(GfxInfo FigureGfxInfo);
	GfxInfo GetGfxInfo()const;	//returns info about the figure to play mode.
	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected
	void Hide();					//Hides figures in playmode.
	void Show();					//Shows figures in playmode.
	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	bool IsHidden();
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	virtual bool pointchecker(int x, int y) = 0; 
	void Setid(int x);
	int getid() ;
	virtual string getType() = 0;
	virtual string Details() = 0;
	//checks if the point is inside the figure
	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	

	
	virtual void Save(ofstream &OutFile)=0;	//Save the figure parameters to the file
	//virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file
	//virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
};

#endif
