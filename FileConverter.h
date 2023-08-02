#ifndef FILECONVERTER_H
#define FILECONVERTER_H

//(*Headers(FileConverter)
#include <wx/button.h>
#include <wx/filedlg.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/radiobut.h>
#include <wx/statbox.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class FileConverter: public wxFrame
{
	public:

		FileConverter(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~FileConverter();

		//(*Declarations(FileConverter)
		wxButton* Select_btn;
		wxButton* convert_btn;
		wxButton* exit_btn;
		wxFileDialog* FileDialog1;
		wxPanel* Panel1;
		wxRadioButton* bmp_rb;
		wxRadioButton* csv_rb;
		wxRadioButton* docx_btn;
		wxRadioButton* html_rb;
		wxRadioButton* ico_rb;
		wxRadioButton* jpeg_rb;
		wxRadioButton* jpg_rb;
		wxRadioButton* odt_rb;
		wxRadioButton* pdf_rb;
		wxRadioButton* png_rb;
		wxRadioButton* svg_rb;
		wxRadioButton* txt_rb;
		wxStaticBox* StaticBox1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxTextCtrl* ChosenFile_txt;
		wxTextCtrl* FileFormat_txt;
		//*)

	protected:

		//(*Identifiers(FileConverter)
		static const long ID_TEXTCTRL1;
		static const long ID_BUTTON1;
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL2;
		static const long ID_BUTTON2;
		static const long ID_STATICBOX1;
		static const long ID_RADIOBUTTON1;
		static const long ID_RADIOBUTTON2;
		static const long ID_RADIOBUTTON3;
		static const long ID_RADIOBUTTON4;
		static const long ID_RADIOBUTTON5;
		static const long ID_RADIOBUTTON6;
		static const long ID_RADIOBUTTON7;
		static const long ID_RADIOBUTTON8;
		static const long ID_RADIOBUTTON9;
		static const long ID_RADIOBUTTON10;
		static const long ID_RADIOBUTTON11;
		static const long ID_RADIOBUTTON12;
		static const long ID_BUTTON3;
		static const long ID_STATICTEXT3;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(FileConverter)
		void Onexit_btnClick(wxCommandEvent& event);
		void OnSelect_btnClick(wxCommandEvent& event);
		void Onconvert_btnClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
