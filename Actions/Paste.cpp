#include "Paste.h"
#include"../ApplicationManager.h"
#include"../Figures/CRectangle.h"
#include"../Figures/CSquare.h"
#include"../Figures/CTriangle.h"
#include"../Figures/CCircle.h"
#include"../Figures/CHexagon.h"
Paste::Paste(ApplicationManager* AM) :Action(AM)
{
}

void Paste::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Choose a point to Paste in");
	pIn->GetPointClicked(P.x, P.y);
}

void Paste::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ReadActionParameters();
	if (P.y<UI.StatusBarHeight || P.y > UI.height - UI.StatusBarHeight) {
		int point = 0;
		pOut->PrintMessage("Select valid Point");
		while (point == 0) {
			pIn->GetPointClicked(P.x, P.y);
			if (!(P.y < UI.StatusBarHeight || P.y > UI.height - UI.StatusBarHeight)) {
				point = 1;
			}
		}
	}
	CRectangle* R = dynamic_cast<CRectangle*> (pManager->getclipboard());
	CSquare* S = dynamic_cast<CSquare*>(pManager->getclipboard());
	CTriangle* T = dynamic_cast<CTriangle*>(pManager->getclipboard());
	CCircle* C = dynamic_cast<CCircle*>(pManager->getclipboard());
	CHexagon* H = dynamic_cast<CHexagon*>(pManager->getclipboard());

	Point P1;
	Point P2;
	if (R != NULL) {
		P1 = R->PasteRect(P, pOut);




		if (pManager->getiscut()) {

			GfxInfo Rinfo = pManager->getfiginfo();
			CRectangle* r1 = new CRectangle(P, P1, Rinfo);
			pManager->AddFigure(r1);
			pManager->deletefig();

		}
		else {

			GfxInfo Rinfo = pManager->getclipboard()->GetGfxInfo();

			CRectangle* r1 = new CRectangle(P, P1, Rinfo);
			pManager->AddFigure(r1);
		}

	}


	else if (S != NULL) {
		if (pManager->getiscut()) {
			GfxInfo Sinfo = pManager->getfiginfo();

			CSquare* S1 = new CSquare(P, Sinfo);
			pManager->AddFigure(S1);
			pManager->deletefig();
		}
		else {
			GfxInfo Sinfo = pManager->getclipboard()->GetGfxInfo();
			CSquare* S1 = new CSquare(P, Sinfo);
			pManager->AddFigure(S1);


		}
	}

	else if (T != NULL) {
		Point* P12;
		P12 = T->PasteTri(P, pOut);
		P1 = P12[0]; P2 = P12[1];

		if (pManager->getiscut()) {
			GfxInfo Tinfo = pManager->getfiginfo();
			CTriangle* T1 = new CTriangle(P, P1, P2, Tinfo);
			pManager->AddFigure(T1);
			pManager->deletefig();
		}
		else {
			GfxInfo Tinfo = pManager->getclipboard()->GetGfxInfo();

			CTriangle* T1 = new CTriangle(P, P1, P2, Tinfo);
			pManager->AddFigure(T1);

		}


	}

	else if (H != NULL) {

		if (pManager->getiscut()) {
			GfxInfo Hinfo = pManager->getfiginfo();
			CHexagon* H1 = new CHexagon(P, Hinfo);
			pManager->AddFigure(H1);
			pManager->deletefig();
		}
		else {
			GfxInfo Hinfo = pManager->getclipboard()->GetGfxInfo();
			CHexagon* H1 = new CHexagon(P, Hinfo);
			pManager->AddFigure(H1);

		}
	}
	else if (C != NULL) {
		Point P1;
		P1 = C->PasteCir(P, pOut);
		if (pManager->getiscut()) {
			GfxInfo Cinfo = pManager->getfiginfo();
			CCircle* C1 = new CCircle(P, P1, Cinfo);
			pManager->AddFigure(C1);
			pManager->deletefig();

		}
		else {
			GfxInfo Cinfo = pManager->getclipboard()->GetGfxInfo();
			CCircle* C1 = new CCircle(P, P1, Cinfo);
			pManager->AddFigure(C1);
		}
	}

}
