#ifndef NOTEPAD_H
#define NOTEPAD_H

//(*Headers(Notepad)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/richtext/richtextctrl.h>
//*)

class Notepad: public wxFrame
{
	public:

		Notepad(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~Notepad();

		//(*Declarations(Notepad)
		wxButton* exit_btn;
		wxButton* open_btn;
		wxButton* save_as_btn;
		wxButton* save_btn;
		wxPanel* Panel1;
		wxRichTextCtrl* RichTextCtrl1;
		//*)

	protected:

		//(*Identifiers(Notepad)
		static const long ID_RICHTEXTCTRL1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON3;
		static const long ID_BUTTON4;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(Notepad)
		void Onexit_btnClick(wxCommandEvent& event);
		void Onopen_btnClick(wxCommandEvent& event);
		void Onsave_as_btnClick(wxCommandEvent& event);
		void Onsave_btnClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
