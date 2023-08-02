/***************************************************************
 * Name:      MultiToolXMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2023-07-18
 * Copyright:  ()
 * License:
 **************************************************************/

#include "MultiToolXMain.h"
#include <wx/msgdlg.h>
#include "Calculator.h"
#include "Shutdown.h"
#include "FileConverter.h"
#include "Notepad.h"

//(*InternalHeaders(MultiToolXFrame)
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(MultiToolXFrame)
const long MultiToolXFrame::ID_BITMAPBUTTON1 = wxNewId();
const long MultiToolXFrame::ID_BITMAPBUTTON2 = wxNewId();
const long MultiToolXFrame::ID_BITMAPBUTTON3 = wxNewId();
const long MultiToolXFrame::ID_BITMAPBUTTON4 = wxNewId();
const long MultiToolXFrame::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(MultiToolXFrame,wxFrame)
    //(*EventTable(MultiToolXFrame)
    //*)
END_EVENT_TABLE()

MultiToolXFrame::MultiToolXFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(MultiToolXFrame)
    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(250,250));
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(184,200), wxSize(400,224), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    Panel1->SetBackgroundColour(wxColour(0,0,0));
    BitmapButton1 = new wxBitmapButton(Panel1, ID_BITMAPBUTTON1, wxBitmap(wxImage(_T("C:\\Users\\Mateusz\\Desktop\\MultiToolX\\pictures\\calc.png"))), wxPoint(16,16), wxSize(100,100), wxBU_AUTODRAW|wxBORDER_NONE, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
    BitmapButton1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INFOTEXT));
    BitmapButton2 = new wxBitmapButton(Panel1, ID_BITMAPBUTTON2, wxBitmap(wxImage(_T("C:\\Users\\Mateusz\\Desktop\\MultiToolX\\pictures\\shut.png"))), wxPoint(128,16), wxSize(100,100), wxBU_AUTODRAW|wxBORDER_NONE, wxDefaultValidator, _T("ID_BITMAPBUTTON2"));
    BitmapButton2->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENUTEXT));
    BitmapButton3 = new wxBitmapButton(Panel1, ID_BITMAPBUTTON3, wxBitmap(wxImage(_T("C:\\Users\\Mateusz\\Desktop\\MultiToolX\\pictures\\exit.png"))), wxPoint(128,128), wxSize(100,100), wxBU_AUTODRAW|wxBORDER_NONE, wxDefaultValidator, _T("ID_BITMAPBUTTON3"));
    BitmapButton3->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INFOTEXT));
    BitmapButton4 = new wxBitmapButton(Panel1, ID_BITMAPBUTTON4, wxBitmap(wxImage(_T("C:\\Users\\Mateusz\\Desktop\\MultiToolX\\pictures\\notepad.png"))), wxPoint(16,128), wxSize(100,100), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON4"));

    Connect(ID_BITMAPBUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MultiToolXFrame::OnBitmapButton1Click);
    Connect(ID_BITMAPBUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MultiToolXFrame::OnBitmapButton2Click);
    Connect(ID_BITMAPBUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MultiToolXFrame::OnBitmapButton3Click);
    Connect(ID_BITMAPBUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MultiToolXFrame::OnBitmapButton4Click);
    //*)
}

MultiToolXFrame::~MultiToolXFrame()
{
    //(*Destroy(MultiToolXFrame)
    //*)
}

void MultiToolXFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void MultiToolXFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

//void MultiToolXFrame::OnButton1Click(wxCommandEvent& event)
//{
//}

void MultiToolXFrame::OnExitbtnClick(wxCommandEvent& event)
{
    Close(true);
}

void MultiToolXFrame::OnButton1Click1(wxCommandEvent& event)
{
    Calculator* newWindow = new Calculator(this);
    newWindow->Show(true);
}

void MultiToolXFrame::OnShutdown_btnClick(wxCommandEvent& event)
{
    Shutdown* newWindow = new Shutdown(this);
    newWindow->Show(true);
}

void MultiToolXFrame::OnBitmapButton1Click(wxCommandEvent& event)
{
    Calculator* newWindow = new Calculator(this);
    newWindow->Show(true);
}

void MultiToolXFrame::OnBitmapButton2Click(wxCommandEvent& event)
{
    Shutdown* newWindow = new Shutdown(this);
    newWindow->Show(true);
}

void MultiToolXFrame::OnBitmapButton3Click(wxCommandEvent& event)
{
    Close(true);
}

void MultiToolXFrame::OnBitmapButton4Click(wxCommandEvent& event)
{
    //FileConverter* newWindow = new FileConverter(this);
    Notepad* newWindow = new Notepad(this);
    newWindow->Show(true);
}
