#include "Notepad.h"
#include <wx/filedlg.h>
#include <wx/filename.h>
#include <wx/wx.h>
#include <fstream>
#include <iostream>
#include <string>


using namespace std;

//(*InternalHeaders(Notepad)
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)

//(*IdInit(Notepad)
const long Notepad::ID_RICHTEXTCTRL1 = wxNewId();
const long Notepad::ID_BUTTON1 = wxNewId();
const long Notepad::ID_BUTTON2 = wxNewId();
const long Notepad::ID_BUTTON3 = wxNewId();
const long Notepad::ID_BUTTON4 = wxNewId();
const long Notepad::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Notepad,wxFrame)
	//(*EventTable(Notepad)
	//*)
END_EVENT_TABLE()

Notepad::Notepad(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(Notepad)
	Create(parent, id, _("NotepadX"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxSize(946,535));
	Move(wxDefaultPosition);
	Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(344,256), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	Panel1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOWFRAME));
	RichTextCtrl1 = new wxRichTextCtrl(Panel1, ID_RICHTEXTCTRL1, wxEmptyString, wxPoint(8,48), wxSize(928,480), wxRE_MULTILINE, wxDefaultValidator, _T("ID_RICHTEXTCTRL1"));
	wxRichTextAttr rchtxtAttr_1;
	rchtxtAttr_1.SetBulletStyle(wxTEXT_ATTR_BULLET_STYLE_ALIGN_LEFT);
	rchtxtAttr_1.SetTextColour(wxColour(0,255,64));
	rchtxtAttr_1.SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENUTEXT));
	RichTextCtrl1->SetBasicStyle(rchtxtAttr_1);
	RichTextCtrl1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENUTEXT));
	exit_btn = new wxButton(Panel1, ID_BUTTON1, _("Exit"), wxPoint(840,8), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	save_as_btn = new wxButton(Panel1, ID_BUTTON2, _("Save as"), wxPoint(8,8), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	save_btn = new wxButton(Panel1, ID_BUTTON3, _("Save"), wxPoint(112,8), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	open_btn = new wxButton(Panel1, ID_BUTTON4, _("Open"), wxPoint(216,8), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Notepad::Onexit_btnClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Notepad::Onsave_as_btnClick);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Notepad::Onsave_btnClick);
	Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Notepad::Onopen_btnClick);
	//*)
}

Notepad::~Notepad()
{
	//(*Destroy(Notepad)
	//*)
}


void Notepad::Onexit_btnClick(wxCommandEvent& event)
{
    Close(true);
}

void Notepad::Onopen_btnClick(wxCommandEvent& event)
{
    wxFileDialog openFileDialog(this, _("Open File"), "", "", "Text files (*.txt)|*.txt", wxFD_OPEN | wxFD_FILE_MUST_EXIST);

    if (openFileDialog.ShowModal() == wxID_CANCEL)
    {
        return;
    }

    wxString openFilePath = openFileDialog.GetPath();
    wxString text = RichTextCtrl1->GetValue();
    ifstream file(openFilePath.ToStdString());

    if(file.is_open())
    {
        string line;
        while(getline(file, line))
        {
            wxString wxline(line);
            text += wxline + wxT('\n');
        }

        RichTextCtrl1->SetValue(text);
        file.close();
    }

    RichTextCtrl1->Refresh();

    //wxMessageBox("File opened.", "Info", wxOK | wxICON_INFORMATION);
}

void Notepad::Onsave_as_btnClick(wxCommandEvent& event)
{
    wxFileDialog saveFileDialog(this, "Save File", "", "", "Text files (*.txt)|*.txt", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);

    if (saveFileDialog.ShowModal() == wxID_CANCEL)
    {
        return;
    }

    wxString saveFilePath = saveFileDialog.GetPath();

    wxFile file(saveFilePath, wxFile::write);

    if (!file.IsOpened())
    {
        wxLogError("Cannot save current contents in file '%s'.", saveFilePath);
        return;
    }

    wxString textToSave = RichTextCtrl1->GetValue();

    if (file.Write(textToSave))
    {
        wxLogMessage("File '%s' successfully saved.", saveFilePath);
    }
    else
    {
        wxLogError("Error occurred while writing to file '%s'.", saveFilePath);
    }

    file.Close();
}

void Notepad::Onsave_btnClick(wxCommandEvent& event)
{
    bool isFileOpen;
    wxString currentFilePath;

    if (!isFileOpen || currentFilePath.empty())
    {
        wxFileDialog saveFileDialog(this, "Save File", "", "", "Text files (*.txt)|*.txt", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);

        if (saveFileDialog.ShowModal() == wxID_CANCEL)
        {
                return;
        }

        currentFilePath = saveFileDialog.GetPath();
        isFileOpen = true;
    }

    wxFile file(currentFilePath, wxFile::write_append); // U¿ywamy flagi wxFile::write_append

    if (!file.IsOpened())
    {
        wxLogError("Cannot save current contents in file '%s'.", currentFilePath);
        return;
    }

    wxString textToSave = RichTextCtrl1->GetValue();

    if (file.Write(textToSave))
    {
        wxLogMessage("File '%s' successfully saved.", currentFilePath);
    }
    else
    {
        wxLogError("Error occurred while writing to file '%s'.", currentFilePath);
    }

    file.Close();
}
