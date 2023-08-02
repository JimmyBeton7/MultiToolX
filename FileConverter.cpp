#include "FileConverter.h"
#include <wx/filedlg.h>
#include <wx/filename.h>
#include <wx/wx.h>
#include <cstdlib>
//#include <Aspose.Words.Cpp/Model/Document/Document.h>
//#include

//(*InternalHeaders(FileConverter)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(FileConverter)
const long FileConverter::ID_TEXTCTRL1 = wxNewId();
const long FileConverter::ID_BUTTON1 = wxNewId();
const long FileConverter::ID_STATICTEXT1 = wxNewId();
const long FileConverter::ID_STATICTEXT2 = wxNewId();
const long FileConverter::ID_TEXTCTRL2 = wxNewId();
const long FileConverter::ID_BUTTON2 = wxNewId();
const long FileConverter::ID_STATICBOX1 = wxNewId();
const long FileConverter::ID_RADIOBUTTON1 = wxNewId();
const long FileConverter::ID_RADIOBUTTON2 = wxNewId();
const long FileConverter::ID_RADIOBUTTON3 = wxNewId();
const long FileConverter::ID_RADIOBUTTON4 = wxNewId();
const long FileConverter::ID_RADIOBUTTON5 = wxNewId();
const long FileConverter::ID_RADIOBUTTON6 = wxNewId();
const long FileConverter::ID_RADIOBUTTON7 = wxNewId();
const long FileConverter::ID_RADIOBUTTON8 = wxNewId();
const long FileConverter::ID_RADIOBUTTON9 = wxNewId();
const long FileConverter::ID_RADIOBUTTON10 = wxNewId();
const long FileConverter::ID_RADIOBUTTON11 = wxNewId();
const long FileConverter::ID_RADIOBUTTON12 = wxNewId();
const long FileConverter::ID_BUTTON3 = wxNewId();
const long FileConverter::ID_STATICTEXT3 = wxNewId();
const long FileConverter::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(FileConverter,wxFrame)
	//(*EventTable(FileConverter)
	//*)
END_EVENT_TABLE()

FileConverter::FileConverter(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(FileConverter)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxSize(474,455));
	Move(wxDefaultPosition);
	Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(312,248), wxSize(474,480), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	ChosenFile_txt = new wxTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxPoint(16,104), wxSize(360,40), wxTE_MULTILINE|wxTE_READONLY|wxTE_WORDWRAP, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	Select_btn = new wxButton(Panel1, ID_BUTTON1, _("Select file"), wxPoint(16,24), wxSize(150,50), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Selected file:"), wxPoint(16,80), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("File format:"), wxPoint(384,80), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	FileFormat_txt = new wxTextCtrl(Panel1, ID_TEXTCTRL2, wxEmptyString, wxPoint(392,104), wxSize(65,30), wxTE_READONLY|wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	wxFont FileFormat_txtFont(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	FileFormat_txt->SetFont(FileFormat_txtFont);
	exit_btn = new wxButton(Panel1, ID_BUTTON2, _("Exit"), wxPoint(304,392), wxSize(150,50), 0, wxDefaultValidator, _T("ID_BUTTON2"));
	StaticBox1 = new wxStaticBox(Panel1, ID_STATICBOX1, _("Select the file format:"), wxPoint(16,160), wxSize(440,224), 0, _T("ID_STATICBOX1"));
	pdf_rb = new wxRadioButton(Panel1, ID_RADIOBUTTON1, _("PDF"), wxPoint(40,200), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON1"));
	pdf_rb->SetValue(true);
	docx_btn = new wxRadioButton(Panel1, ID_RADIOBUTTON2, _("DOCX"), wxPoint(40,240), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON2"));
	jpg_rb = new wxRadioButton(Panel1, ID_RADIOBUTTON3, _("JPG"), wxPoint(256,200), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON3"));
	png_rb = new wxRadioButton(Panel1, ID_RADIOBUTTON4, _("PNG"), wxPoint(256,240), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON4"));
	svg_rb = new wxRadioButton(Panel1, ID_RADIOBUTTON5, _("SVG"), wxPoint(256,280), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON5"));
	txt_rb = new wxRadioButton(Panel1, ID_RADIOBUTTON6, _("TXT"), wxPoint(40,280), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON6"));
	html_rb = new wxRadioButton(Panel1, ID_RADIOBUTTON7, _("HTML"), wxPoint(152,200), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON7"));
	odt_rb = new wxRadioButton(Panel1, ID_RADIOBUTTON8, _("ODT"), wxPoint(152,240), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON8"));
	csv_rb = new wxRadioButton(Panel1, ID_RADIOBUTTON9, _("CSV"), wxPoint(152,280), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON9"));
	jpeg_rb = new wxRadioButton(Panel1, ID_RADIOBUTTON10, _("JPEG"), wxPoint(352,200), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON10"));
	bmp_rb = new wxRadioButton(Panel1, ID_RADIOBUTTON11, _("BMP"), wxPoint(352,240), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON11"));
	ico_rb = new wxRadioButton(Panel1, ID_RADIOBUTTON12, _("ICO"), wxPoint(352,280), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON12"));
	convert_btn = new wxButton(Panel1, ID_BUTTON3, _("Convert"), wxPoint(32,320), wxSize(150,50), 0, wxDefaultValidator, _T("ID_BUTTON3"));
	StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("FILE CONVENTER"), wxPoint(256,32), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	wxFont StaticText3Font(14,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	StaticText3->SetFont(StaticText3Font);
	FileDialog1 = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, wxFileSelectorDefaultWildcardStr, wxFD_DEFAULT_STYLE|wxFD_OPEN|wxFD_FILE_MUST_EXIST, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&FileConverter::OnSelect_btnClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&FileConverter::Onexit_btnClick);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&FileConverter::Onconvert_btnClick);
	//*)
}

FileConverter::~FileConverter()
{
	//(*Destroy(FileConverter)
	//*)
}

wxString chosenFileFormat;
wxString filePath;
wxString fileExtension;
wxString saveFilePath;

void FileConverter::Onexit_btnClick(wxCommandEvent& event)
{
    Close(true);
}

void FileConverter::OnSelect_btnClick(wxCommandEvent& event)
{
    wxFileDialog openFileDialog(this, _("Choose a file to convert"), "", "", "All files (*.*)|*.*", wxFD_OPEN | wxFD_FILE_MUST_EXIST);

    if (openFileDialog.ShowModal() == wxID_CANCEL)
    {
        return; // U¿ytkownik anulowa³ wybór pliku
    }

    filePath = openFileDialog.GetPath();
    wxFileName fileName(filePath);
    fileExtension = fileName.GetExt();

    if (fileExtension == "pdf") //.Lower()
    {
        chosenFileFormat = "pdf";
        ChosenFile_txt->SetLabel(filePath);
        FileFormat_txt->SetLabel(chosenFileFormat);
        ChosenFile_txt->Refresh();
        FileFormat_txt->Refresh();

    }
    else if (fileExtension.Lower() == "docx")
    {
        chosenFileFormat = "docx";
        ChosenFile_txt->SetLabel(filePath);
        FileFormat_txt->SetLabel(chosenFileFormat);
        ChosenFile_txt->Refresh();
        FileFormat_txt->Refresh();
    }
    else
    {
        chosenFileFormat = fileExtension;
        ChosenFile_txt->SetLabel(filePath);
        FileFormat_txt->SetLabel(chosenFileFormat);
        ChosenFile_txt->Refresh();
        FileFormat_txt->Refresh();
    }
}

void ConvertPDFToDOCX(const wxString& inputPDF, const wxString& outputDOCX)
{
    wxString defaultFileName = "converted_" + wxFileName(inputPDF).GetFullName();
    wxString wildcard = "Microsoft Word (*.docx)|*.docx";
    wxFileDialog saveFileDialog(nullptr, _("Save File"), wxEmptyString, defaultFileName, wildcard, wxFD_SAVE | wxFD_OVERWRITE_PROMPT);

    if (saveFileDialog.ShowModal() == wxID_CANCEL)
    {
        return;
    }

    saveFilePath = saveFileDialog.GetPath();
    //wxString saveFileName = saveFileDialog.GetFilename();
    //wxString outputFile = wxFileName::Combine(saveFilePath, saveFileName);

    //wxString command = "libreoffice --headless --convert-to docx --outdir " + saveFilePath + " " + filePath;
    //wxString command = "libreoffice --headless --convert-to docx --outdir " + wxFileName(saveFilePath).GetPath() + " " + inputPDF;
    //wxString command = "libreoffice --headless --convert-to docx --outdir " + wxFileName(saveFilePath);
    //wxString command = "libreoffice --headless --convert-to docx --outdir " + saveFilePath + " " + filePath;
    wxString command = "libreoffice --headless --convert-to docx --outdir " + saveFilePath+ " " + filePath;
    wxExecute(command);
}

void FileConverter::Onconvert_btnClick(wxCommandEvent& event)
{
    if(docx_btn->GetValue())
    {
        ConvertPDFToDOCX(filePath,saveFilePath);
    }

}


