#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib/CMUgraphics.h" // Corrected the include path

// This file contains some global constants and definitions to be used in the project.
enum ActionType // The actions supported (you can add more if needed)
{
	DRAW_RECT,		//Draw Rectangle
	DRAW_SQUR,
	DRAW_TRI,
	DRAW_HEX,
	DRAW_CIRC,
	EXIT,		//Exit
	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY,		//Switch interface to Play mode
	EMPTY,			//A click on empty place in the toolbar
	DRAWING_AREA,	//A click on the drawing area
	STATUS,			//A click on the status bar
	SELECT,
	DELETE_FIG,
	CLR_ALL,
	COPY,
	CUT,
	PASTE,
	SNDTOFRNT,
	SNDTOBACK,
	LOAD,
	SAVE,
	CHANGE_BORDER_COLOR,
	CHANGE_FILING_COLOR,
	BLCK,
	YEL,
	ORG,
	RD,
	GRN,
	BLU,
	PICKNHIDE,
	TYPE,
	FILLCLR,
	TYPENFILLCOLOR,	// Type and fill color
	// Add other action types of the two modes as needed
};

struct Point	// To be used for figures points
{
	int x, y;
};

struct GfxInfo	// Graphical info of each figure (you may add more members)
{
	color DrawClr;	// Draw color of the figure
	color FillClr;	// Fill color of the figure
	bool isFilled;	// Figure filled or not
	int BorderWdth;	// Width of figure borders
};

#endif // DEFS_H
