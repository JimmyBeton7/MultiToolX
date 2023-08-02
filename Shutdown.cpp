#include "Shutdown.h"
#include <Windows.h>

//(*InternalHeaders(Shutdown)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(Shutdown)
const long Shutdown::ID_CHOICE1 = wxNewId();
const long Shutdown::ID_STATICTEXT1 = wxNewId();
const long Shutdown::ID_BUTTON1 = wxNewId();
const long Shutdown::ID_BUTTON2 = wxNewId();
const long Shutdown::ID_BUTTON3 = wxNewId();
const long Shutdown::ID_STATICTEXT2 = wxNewId();
const long Shutdown::ID_STATICTEXT3 = wxNewId();
const long Shutdown::ID_PANEL1 = wxNewId();
const long Shutdown::ID_TIMER1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Shutdown,wxFrame)
	//(*EventTable(Shutdown)
	//*)
END_EVENT_TABLE()

Shutdown::Shutdown(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(Shutdown)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxSize(400,176));
	Move(wxDefaultPosition);
	Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(216,80), wxSize(400,144), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	Choice1 = new wxChoice(Panel1, ID_CHOICE1, wxPoint(16,40), wxSize(208,50), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	Choice1->SetSelection( Choice1->Append(_("10min")) );
	Choice1->Append(_("15min"));
	Choice1->Append(_("30min"));
	Choice1->Append(_("45min"));
	Choice1->Append(_("1hour"));
	Choice1->Append(_("2hours"));
	Choice1->Append(_("3hours"));
	Choice1->Append(_("5hours"));
	Choice1->Append(_("10hours"));
	Choice1->Append(_("12hours"));
	wxFont Choice1Font(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	Choice1->SetFont(Choice1Font);
	StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Set timer:"), wxPoint(16,8), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	wxFont StaticText1Font(14,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	exit_btn = new wxButton(Panel1, ID_BUTTON1, _("Exit"), wxPoint(272,120), wxSize(120,50), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	start_btn = new wxButton(Panel1, ID_BUTTON2, _("Start timer"), wxPoint(272,8), wxSize(120,50), 0, wxDefaultValidator, _T("ID_BUTTON2"));
	reset_btn = new wxButton(Panel1, ID_BUTTON3, _("Reset"), wxPoint(272,64), wxSize(120,50), 0, wxDefaultValidator, _T("ID_BUTTON3"));
	started_label = new wxStaticText(Panel1, ID_STATICTEXT2, _("Computer will be turned off in:"), wxPoint(16,88), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	started_label->Hide();
	wxFont started_labelFont(11,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	started_label->SetFont(started_labelFont);
	Clocklabel = new wxStaticText(Panel1, ID_STATICTEXT3, _("00:00:00"), wxPoint(64,120), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	wxFont ClocklabelFont(18,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	Clocklabel->SetFont(ClocklabelFont);
	Timer1.SetOwner(this, ID_TIMER1);
	Timer1.Start(1000, false);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Shutdown::Onexit_btnClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Shutdown::Onstart_btnClick);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Shutdown::Onreset_btnClick);
	Connect(ID_TIMER1,wxEVT_TIMER,(wxObjectEventFunction)&Shutdown::OnTimer1Trigger);
	//*)
}

Shutdown::~Shutdown()
{
	//(*Destroy(Shutdown)
	//*)
}

bool TimerRunning = false;
wxDateTime EndTime;
wxTimeSpan remainingTime;
wxDateTime startTime;
wxTimeSpan timeSpan;
wxTimeSpan selected;

void Shutdown::Onexit_btnClick(wxCommandEvent& event)
{
    Close(true);
}

void UpdateClockLabel(const wxTimeSpan& time, wxStaticText* clock)
{
    wxString formattedTime = time.Format("%H:%M:%S");
    clock->SetLabel(formattedTime);
}

void Shutdown::OnTimer1Trigger(wxTimerEvent& event)
{
    if(TimerRunning)
    {
        if (remainingTime.IsPositive()) // SprawdŸ, czy pozosta³y czas jest dodatni
        {
            remainingTime = remainingTime.Subtract(wxTimeSpan(0, 0, 1));
            UpdateClockLabel(remainingTime, Clocklabel);
        }
        else
        {
            Timer1.Stop();
            //wxMessageBox("Czas min¹³!");
            UpdateClockLabel(wxTimeSpan(0, 0, 0), Clocklabel);
            TimerRunning = false;
            ::ExitWindowsEx(EWX_SHUTDOWN | EWX_FORCE, 0);
        }
    }
}

void Shutdown::Onstart_btnClick(wxCommandEvent& event)
{
    wxString selectedOption = Choice1->GetString(Choice1->GetSelection());

    if (selectedOption == "10min")
    {
        timeSpan = wxTimeSpan(0, 10, 0);
    }
    else if (selectedOption == "15min")
    {
        timeSpan = wxTimeSpan(0, 15, 0);
    }
    else if(selectedOption == "30min")
    {
        timeSpan = wxTimeSpan(0, 30, 0);
    }
    else if(selectedOption == "45min")
    {
        timeSpan = wxTimeSpan(0, 45, 0);
    }
    else if(selectedOption == "1hour")
    {
        timeSpan = wxTimeSpan(1, 0, 0);
    }
    else if(selectedOption == "2hours")
    {
        timeSpan = wxTimeSpan(2, 0, 0);
    }
    else if(selectedOption == "3hours")
    {
        timeSpan = wxTimeSpan(3, 0, 0);
    }
    else if(selectedOption == "5hours")
    {
        timeSpan = wxTimeSpan(5, 0, 0);
    }
    else if(selectedOption == "10hours")
    {
        timeSpan = wxTimeSpan(10, 0, 0);
    }
    else if(selectedOption == "12hours")
    {
        timeSpan = wxTimeSpan(12, 0, 0);
    }

    selected = timeSpan;
    startTime = wxDateTime::Now();
    EndTime = startTime + timeSpan;
    remainingTime = EndTime.Subtract(wxDateTime::Now());

    UpdateClockLabel(remainingTime, Clocklabel);

    if (!TimerRunning)
    {
        Timer1.Start(1000);
        TimerRunning = true;
        started_label->Show(true);
    }
}


void Shutdown::Onreset_btnClick(wxCommandEvent& event)
{
    // Zatrzymaj timer
    Timer1.Stop();

    // Zresetuj czas do wartoœci wybranej wczeœniej przez u¿ytkownika
    //EndTime = startTime + selected;
    remainingTime = EndTime.Subtract(wxDateTime::Now());
    UpdateClockLabel(selected, Clocklabel);

    // Ustaw flage TimerRunning na false, aby wiedzieæ, ¿e timer jest zatrzymany
    TimerRunning = false;
    started_label->Show(false);
}
