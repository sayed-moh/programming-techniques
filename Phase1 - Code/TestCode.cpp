#include "GUI\Input.h"
#include "GUI\Output.h"

//This is a test code to test the Input and Output classes

int main()
{
	int x,y;
	//Create Input and Output objects to test
	Output *pOut = new Output();
	Input *pIn = pOut->CreateInput();

	//Starting the test
	pOut->PrintMessage("This demo is to test input and output classes, Click anywhere to start the test");
	pIn->GetPointClicked(x,y);	//Wait for any click


	///////////////////////////////////////////////////////////////////////////////////
	// TEST 1:	
	//			Create The FULL Tool bar, the drawing area and the status bar	
	//			This has already been done through the constrcutor of class Output
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST1: Drawing Tool bar and Status bar, Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	
	///////////////////////////////////////////////////////////////////////////////////
	// TEST 2:	
	//			Drawing all the Figures with all possible states: 
	//			Non-filled, Filled, and highlighted in both cases			
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMessage("TEST2: Now we will show that Output class can draw any figure in any state, Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	GfxInfo gfxInfo;//to be used with draw function of the class Ouput
	Point P1, P2, P3;

	/// 2.1- Rectangle Test ///
	/// =================== 
	pOut->PrintMessage("Drawing a Rectangle, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	
	// 2.1.1 - Drawing non-filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> non-filled,  Click two points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);

	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = BLACK;	//any color for border
	gfxInfo.isFilled = false;	//Figure is NOT filled
	pOut->DrawRect(P1, P2, gfxInfo, false);

	// 2.1.2 - Drawing highlighted non-filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> Highlighted non-filled, Click to Highlight");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->DrawRect(P1, P2, gfxInfo, true);


	// 2.1.3 - Drawing a filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> filled,  Click two points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);

	gfxInfo.BorderWdth = 6;
	gfxInfo.DrawClr = BLUE;	//any color for border
	gfxInfo.FillClr = GREEN;//any color for filling
	gfxInfo.isFilled = true;//Figure is filled
	pOut->DrawRect(P1, P2, gfxInfo, false);


	// 2.1.4 - Drawing a highlighted filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> Highlighted filled, Click to Highlight");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->DrawRect(P1, P2, gfxInfo, true);


	pOut->PrintMessage("Drawing a Rectangle Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawArea();

	/// 2.2- Line Test ///
	/// ============== 
	pOut->PrintMessage("Drawing a Line, normal and Highlighted, Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	///TODO: Add code to draw Line, Normal and Highlighted
	pOut->PrintMessage("Drawing a Line ==> non-filled,  Click two points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);

	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = BLACK;	
	pOut->DrawLine(P1, P2, gfxInfo, false);


	pOut->PrintMessage("Drawing a Line ==> Highlighted, Click to Highlight");
	pIn->GetPointClicked(x, y);	
	pOut->DrawLine(P1, P2, gfxInfo, true);


	pOut->PrintMessage("Drawing a Line Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x,y);	
	pOut->ClearDrawArea();

	/// 2.3- Triangle Test ///
	/// =================== 

	///TODO: Add code to draw Triangle in all possible states


	pOut->PrintMessage("Drawing a Triangle, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	pOut->PrintMessage("Drawing a Triangle ==> non-filled,  Click three points");  //Not-filled, not highlighted Triangle
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);
	pIn->GetPointClicked(P3.x, P3.y);

	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = BLACK;	
	gfxInfo.isFilled = false;	
	pOut->DrawTri(P1, P2, P3, gfxInfo, false);

	pOut->PrintMessage("Drawing a Triangle ==> Highlighted non-filled, Click to Highlight");  //Not filled, highlighted Triangle
	pIn->GetPointClicked(x, y);	
	pOut->DrawTri(P1, P2, P3, gfxInfo, true);

	pOut->PrintMessage("Drawing a Triangle ==> filled,  Click three points"); //filled but not highlighted Triangle
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);
	pIn->GetPointClicked(P3.x, P3.y);

	gfxInfo.BorderWdth = 6;  
	gfxInfo.DrawClr = BLUE;	
	gfxInfo.FillClr = GREEN;
	gfxInfo.isFilled = true;
	pOut->DrawTri(P1, P2, P3, gfxInfo, false);

	pOut->PrintMessage("Drawing a Rectangle ==> Highlighted filled, Click to Highlight"); //highlighted filled Triangle
	pIn->GetPointClicked(x, y);	
	pOut->DrawTri(P1, P2, P3, gfxInfo, true);


	pOut->PrintMessage("Drawing a Triangle Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x, y);	
	pOut->ClearDrawArea();

	
	/// 2.4- Rhombus Test ///
	/// =================== 
	pOut->PrintMessage("Drawing a Rhombus, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	///TODO: Add code to draw Rhombus in all possible states
	pOut->PrintMessage("Drawing a Rhombus ==> non-filled,  Click one point");
	pIn->GetPointClicked(P1.x, P1.y);

	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = BLACK;	
	gfxInfo.isFilled = false;	
	pOut->DrawRhomb(P1, gfxInfo, false);


	pOut->PrintMessage("Drawing a Rhombus ==> Highlighted non-filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	
	pOut->DrawRhomb(P1, gfxInfo, true);


	pOut->PrintMessage("Drawing a Rhombus ==> filled,  Click one point");
	pIn->GetPointClicked(P1.x, P1.y);

	gfxInfo.BorderWdth = 6;
	gfxInfo.DrawClr = BLUE;	
	gfxInfo.FillClr = GREEN;
	gfxInfo.isFilled = true;
	pOut->DrawRhomb(P1, gfxInfo, false);


	pOut->PrintMessage("Drawing a Rhombus ==> Highlighted filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	
	pOut->DrawRhomb(P1, gfxInfo, true);


	pOut->PrintMessage("Drawing a Rhombus Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x,y);	
	pOut->ClearDrawArea();
	
	/// 2.5- Ellipse Test ///
	/// =================== 
	pOut->PrintMessage("Drawing an Ellipse, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	///TODO: Add code to draw Ellipse in all possible states
	pOut->PrintMessage("Drawing a Ellipse ==> non-filled,  Click one point");
	pIn->GetPointClicked(P1.x, P1.y);
	
	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = BLACK;	
	gfxInfo.isFilled = false;	
	pOut->DrawEllip(P1, gfxInfo, false);


	pOut->PrintMessage("Drawing a Ellipse ==> Highlighted non-filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	
	pOut->DrawEllip(P1, gfxInfo, true);


	pOut->PrintMessage("Drawing a Ellipse ==> filled,  Click one point");
	pIn->GetPointClicked(P1.x, P1.y);
	
	gfxInfo.BorderWdth = 6;
	gfxInfo.DrawClr = BLUE;	
	gfxInfo.FillClr = GREEN;
	gfxInfo.isFilled = true;
	pOut->DrawEllip(P1, gfxInfo, false);


	pOut->PrintMessage("Drawing a Ellipse==> Highlighted filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	
	pOut->DrawEllip(P1, gfxInfo, true);

	pOut->PrintMessage("Drawing a Ellipse Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawArea();
	
	///////////////////////////////////////////////////////////////////////////////////
	// TEST 3: 
	//			Input Class: Read strings from the user
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMessage("TEST3: Now Time to test class Input, Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	
	pOut->PrintMessage("Testing Input ability to read strings, Click anywhere to continue");
	
	pOut->PrintMessage("Enter a string: ");
	string z=pIn->GetSrting(pOut);
	pOut->PrintMessage("You Entered: " + z +" ,Click anywhere to continue");

	///TODO: Add code here to 
	// 1- Read a string from the user on the status bar
	// 2- After reading the stirng clear the status bar
	// 3- print on the status bar "You Entered" then print the string

	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawArea();

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 4: 
	//			Input Class : Check for the user action
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMessage("TEST4: Testing Input ability to detect User Action, click anywhere");

	ActionType ActType;
	
	///TODO:  
	//You must add a case for each action (both Draw mode and Play mode actions)
	//Add cases for the missing actions below
	do
	{
		ActType = pIn->GetUserAction();

		switch (ActType)
		{
		case DRAW_RECT:
				pOut->PrintMessage("Action: Draw a Rectangle , Click anywhere");
				break;

		case DRAW_LINE:
				pOut->PrintMessage("Action: Draw a Line , Click anywhere");
				break;

		case DRAW_RHOMBUS:
				pOut->PrintMessage("Action: Draw a Rhombus , Click anywhere");
				break;

		case DRAW_ELLIPSE:
				pOut->PrintMessage("Action: Draw an Ellipse , Click anywhere");
				break;

		case DRAW_TRI:
				pOut->PrintMessage("Action: Draw a Triangle , Click anywhere");
				break;

		case SAVE:
			pOut->PrintMessage("Action: Saving...");
			break;

		case LOAD:
			pOut->PrintMessage("Action: Loading...");
			break;

		case COPY:
			pOut->PrintMessage("Action: Choose a figure to copy");
			break;

		case SAVE_BY_TYPE:
			pOut->PrintMessage("Action: Choose a certain type to save");
			break;

		case PASTE:
			pOut->PrintMessage("Action: Click on an area to paste");
			break;

		case CUT:
			pOut->PrintMessage("Action: Choose a figure to cut");
			break;

		case SELECT:
			pOut->PrintMessage("Action: Select a specific figure or area");
			break;

		case DEL:
			pOut->PrintMessage("Action: Choose a figure to delete");
			break;

		case Black:
			pOut->PrintMessage("Action: Black");
			break;

		case White:
			pOut->PrintMessage("Action: White");
			break;

		case Red:
			pOut->PrintMessage("Action: Red");
			break;

		case Green:
			pOut->PrintMessage("Action: Green");
			break;

		case Blue:
			pOut->PrintMessage("Action: Blue");
			break;

		case CHNG_DRAW_CLR:
				pOut->PrintMessage("Action: Change Figure's drawing color");
				break;

		case CHNG_FILL_CLR:
				pOut->PrintMessage("Action: Change Figure's Fill color");
				break;
			
		case BY_TYPE:
				pOut->PrintMessage("Action: Play Pick and Hide by figure type, pick a figure");
				break;

		case BY_CLR:
				pOut->PrintMessage("Action: Play Pick and Hide by figure color, pick a color");
				break;

		case STATUS:
				pOut->PrintMessage("Action: a click on the Status Bar, Click anywhere");
				break;
 
		case DRAWING_AREA:
				pOut->PrintMessage("Action: a click on the Drawing Area, Click anywhere");
				break;

		case PLAYING_AREA:
				pOut->PrintMessage("Action: a click on the Playing Area, Click anywhere");
				break;

		case EMPTY:
				pOut->PrintMessage("Action: a click on empty area in the Design Tool Bar, Click anywhere");
				break;

		case TO_DRAW:
				pOut->PrintMessage("Action: Switch to Draw Mode, creating simualtion tool bar");
				pOut->CreateDrawToolBar();
				break;

		case TO_PLAY:
				pOut->PrintMessage("Action: Switch to Play Mode, creating Design tool bar");
				pOut->CreatePlayToolBar();
				break;


		case EXIT:				
				break;
		}
	}while(ActType != EXIT);


	/// Exiting
	pOut->PrintMessage("Action: EXIT, test is finished, click anywhere to exit");
	pIn->GetPointClicked(x,y);


	delete pIn;
	delete pOut;	
	return 0;
}


