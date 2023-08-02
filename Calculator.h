#ifndef CALCULATOR_H
#define CALCULATOR_H

//(*Headers(Calculator)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/statline.h>
#include <wx/textctrl.h>
//*)

class Calculator: public wxFrame
{
	public:

		Calculator(wxWindow* parent,wxWindowID id=wxID_ANY);
		virtual ~Calculator();

		//(*Declarations(Calculator)
		wxButton* Add_btn;
		wxButton* BCSP_btn;
		wxButton* Brackets_btn;
		wxButton* Button2;
		wxButton* Button3;
		wxButton* Button4;
		wxButton* Button5;
		wxButton* Button6;
		wxButton* Button7;
		wxButton* Button8;
		wxButton* C_btn;
		wxButton* Calculate_btn;
		wxButton* Divide_btn;
		wxButton* Eight_btn;
		wxButton* Nine_btn;
		wxButton* One_btn;
		wxButton* Seven_btn;
		wxButton* Sign_change_btn;
		wxButton* Substract_btn;
		wxButton* Three_btn;
		wxButton* Two_btn;
		wxButton* close_btn;
		wxPanel* Panel1;
		wxStaticLine* StaticLine1;
		wxTextCtrl* Result_txtbox;
		wxTextCtrl* Screen_txtbox;
		//*)

	protected:

		//(*Identifiers(Calculator)
		static const long ID_TEXTCTRL1;
		static const long ID_BUTTON1;
		static const long ID_STATICLINE1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON3;
		static const long ID_BUTTON4;
		static const long ID_BUTTON5;
		static const long ID_BUTTON6;
		static const long ID_BUTTON7;
		static const long ID_BUTTON8;
		static const long ID_BUTTON9;
		static const long ID_BUTTON10;
		static const long ID_BUTTON11;
		static const long ID_BUTTON12;
		static const long ID_BUTTON13;
		static const long ID_BUTTON14;
		static const long ID_BUTTON15;
		static const long ID_BUTTON16;
		static const long ID_BUTTON17;
		static const long ID_BUTTON18;
		static const long ID_BUTTON19;
		static const long ID_BUTTON20;
		static const long ID_BUTTON21;
		static const long ID_TEXTCTRL2;
		static const long ID_BUTTON22;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(Calculator)
		void OnButton7Click(wxCommandEvent& event);
		void Onclose_btnClick(wxCommandEvent& event);
		void OnOne_btnClick(wxCommandEvent& event);
		void OnTwo_btnClick(wxCommandEvent& event);
		void OnThree_btnClick(wxCommandEvent& event);
		void OnButton4Click(wxCommandEvent& event);
		void OnButton5Click(wxCommandEvent& event);
		void OnButton6Click(wxCommandEvent& event);
		void OnSeven_btnClick(wxCommandEvent& event);
		void OnEight_btnClick(wxCommandEvent& event);
		void OnNine_btnClick(wxCommandEvent& event);
		void OnBrackets_btnClick(wxCommandEvent& event);
		void OnDivide_btnClick(wxCommandEvent& event);
		void OnButton3Click(wxCommandEvent& event);
		void OnSubstract_btnClick(wxCommandEvent& event);
		void OnAdd_btnClick(wxCommandEvent& event);
		void OnButton8Click(wxCommandEvent& event);
		void OnC_btnClick(wxCommandEvent& event);
		void OnBCSP_btnClick(wxCommandEvent& event);
		void UpdateResult();
		void OnCalculate_btnClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
