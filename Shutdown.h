#ifndef SHUTDOWN_H
#define SHUTDOWN_H

//(*Headers(Shutdown)
#include <wx/button.h>
#include <wx/choice.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/stattext.h>
#include <wx/timer.h>
//*)

class Shutdown: public wxFrame
{
	public:

		Shutdown(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~Shutdown();

		//(*Declarations(Shutdown)
		wxButton* exit_btn;
		wxButton* reset_btn;
		wxButton* start_btn;
		wxChoice* Choice1;
		wxPanel* Panel1;
		wxStaticText* Clocklabel;
		wxStaticText* StaticText1;
		wxStaticText* started_label;
		wxTimer Timer1;
		//*)

	protected:

		//(*Identifiers(Shutdown)
		static const long ID_CHOICE1;
		static const long ID_STATICTEXT1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON3;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT3;
		static const long ID_PANEL1;
		static const long ID_TIMER1;
		//*)

	private:

		//(*Handlers(Shutdown)
		void Onexit_btnClick(wxCommandEvent& event);
		void OnTimer1Trigger(wxTimerEvent& event);
		void Onstart_btnClick(wxCommandEvent& event);
		void Onreset_btnClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
