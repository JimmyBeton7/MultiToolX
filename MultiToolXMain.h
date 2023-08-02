/***************************************************************
 * Name:      MultiToolXMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2023-07-18
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef MULTITOOLXMAIN_H
#define MULTITOOLXMAIN_H

//(*Headers(MultiToolXFrame)
#include <wx/bmpbuttn.h>
#include <wx/frame.h>
#include <wx/panel.h>
//*)

class MultiToolXFrame: public wxFrame
{
    public:

        MultiToolXFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~MultiToolXFrame();

    private:

        //(*Handlers(MultiToolXFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnExitbtnClick(wxCommandEvent& event);
        void OnButton1Click1(wxCommandEvent& event);
        void OnShutdown_btnClick(wxCommandEvent& event);
        void OnBitmapButton1Click(wxCommandEvent& event);
        void OnBitmapButton2Click(wxCommandEvent& event);
        void OnBitmapButton3Click(wxCommandEvent& event);
        void OnBitmapButton4Click(wxCommandEvent& event);
        //*)

        //(*Identifiers(MultiToolXFrame)
        static const long ID_BITMAPBUTTON1;
        static const long ID_BITMAPBUTTON2;
        static const long ID_BITMAPBUTTON3;
        static const long ID_BITMAPBUTTON4;
        static const long ID_PANEL1;
        //*)

        //(*Declarations(MultiToolXFrame)
        wxBitmapButton* BitmapButton1;
        wxBitmapButton* BitmapButton2;
        wxBitmapButton* BitmapButton3;
        wxBitmapButton* BitmapButton4;
        wxPanel* Panel1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // MULTITOOLXMAIN_H
