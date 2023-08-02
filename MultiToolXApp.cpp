/***************************************************************
 * Name:      MultiToolXApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2023-07-18
 * Copyright:  ()
 * License:
 **************************************************************/

#include "MultiToolXApp.h"

//(*AppHeaders
#include "MultiToolXMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(MultiToolXApp);

bool MultiToolXApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	MultiToolXFrame* Frame = new MultiToolXFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
