#include "Calculator.h"
#include<cctype>
#include<string>
#include<stack>
#include <iostream>
#include <sstream>
#include <map>
#include <cmath>

//(*InternalHeaders(Calculator)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)

//(*IdInit(Calculator)
const long Calculator::ID_TEXTCTRL1 = wxNewId();
const long Calculator::ID_BUTTON1 = wxNewId();
const long Calculator::ID_STATICLINE1 = wxNewId();
const long Calculator::ID_BUTTON2 = wxNewId();
const long Calculator::ID_BUTTON3 = wxNewId();
const long Calculator::ID_BUTTON4 = wxNewId();
const long Calculator::ID_BUTTON5 = wxNewId();
const long Calculator::ID_BUTTON6 = wxNewId();
const long Calculator::ID_BUTTON7 = wxNewId();
const long Calculator::ID_BUTTON8 = wxNewId();
const long Calculator::ID_BUTTON9 = wxNewId();
const long Calculator::ID_BUTTON10 = wxNewId();
const long Calculator::ID_BUTTON11 = wxNewId();
const long Calculator::ID_BUTTON12 = wxNewId();
const long Calculator::ID_BUTTON13 = wxNewId();
const long Calculator::ID_BUTTON14 = wxNewId();
const long Calculator::ID_BUTTON15 = wxNewId();
const long Calculator::ID_BUTTON16 = wxNewId();
const long Calculator::ID_BUTTON17 = wxNewId();
const long Calculator::ID_BUTTON18 = wxNewId();
const long Calculator::ID_BUTTON19 = wxNewId();
const long Calculator::ID_BUTTON20 = wxNewId();
const long Calculator::ID_BUTTON21 = wxNewId();
const long Calculator::ID_TEXTCTRL2 = wxNewId();
const long Calculator::ID_BUTTON22 = wxNewId();
const long Calculator::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Calculator,wxFrame)
	//(*EventTable(Calculator)
	//*)
END_EVENT_TABLE()

Calculator::Calculator(wxWindow* parent,wxWindowID id)
{
	//(*Initialize(Calculator)
	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(375,700));
	Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(8,0), wxSize(390,535), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	Screen_txtbox = new wxTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxPoint(16,8), wxSize(344,48), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	wxFont Screen_txtboxFont(20,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	Screen_txtbox->SetFont(Screen_txtboxFont);
	close_btn = new wxButton(Panel1, ID_BUTTON1, _("Close"), wxPoint(280,640), wxSize(80,48), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	wxFont close_btnFont(14,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	close_btn->SetFont(close_btnFont);
	StaticLine1 = new wxStaticLine(Panel1, ID_STATICLINE1, wxPoint(8,632), wxSize(360,3), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
	C_btn = new wxButton(Panel1, ID_BUTTON2, _("C"), wxPoint(16,192), wxSize(80,80), 0, wxDefaultValidator, _T("ID_BUTTON2"));
	C_btn->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
	C_btn->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BACKGROUND));
	wxFont C_btnFont(18,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	C_btn->SetFont(C_btnFont);
	Brackets_btn = new wxButton(Panel1, ID_BUTTON3, _("( )"), wxPoint(104,192), wxSize(80,80), 0, wxDefaultValidator, _T("ID_BUTTON3"));
	wxFont Brackets_btnFont(18,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	Brackets_btn->SetFont(Brackets_btnFont);
	Button2 = new wxButton(Panel1, ID_BUTTON4, _("Label"), wxPoint(192,192), wxSize(80,80), 0, wxDefaultValidator, _T("ID_BUTTON4"));
	Divide_btn = new wxButton(Panel1, ID_BUTTON5, _("/"), wxPoint(280,192), wxSize(80,80), 0, wxDefaultValidator, _T("ID_BUTTON5"));
	Divide_btn->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENUHILIGHT));
	wxFont Divide_btnFont(18,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial Black"),wxFONTENCODING_DEFAULT);
	Divide_btn->SetFont(Divide_btnFont);
	Seven_btn = new wxButton(Panel1, ID_BUTTON6, _("7"), wxPoint(16,280), wxSize(80,80), 0, wxDefaultValidator, _T("ID_BUTTON6"));
	wxFont Seven_btnFont(18,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	Seven_btn->SetFont(Seven_btnFont);
	Eight_btn = new wxButton(Panel1, ID_BUTTON7, _("8"), wxPoint(104,280), wxSize(80,80), 0, wxDefaultValidator, _T("ID_BUTTON7"));
	wxFont Eight_btnFont(18,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	Eight_btn->SetFont(Eight_btnFont);
	Nine_btn = new wxButton(Panel1, ID_BUTTON8, _("9"), wxPoint(192,280), wxSize(80,80), 0, wxDefaultValidator, _T("ID_BUTTON8"));
	wxFont Nine_btnFont(18,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	Nine_btn->SetFont(Nine_btnFont);
	Button3 = new wxButton(Panel1, ID_BUTTON9, _("x"), wxPoint(280,280), wxSize(80,80), 0, wxDefaultValidator, _T("ID_BUTTON9"));
	Button3->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENUHILIGHT));
	wxFont Button3Font(18,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	Button3->SetFont(Button3Font);
	Button4 = new wxButton(Panel1, ID_BUTTON10, _("4"), wxPoint(16,368), wxSize(80,80), 0, wxDefaultValidator, _T("ID_BUTTON10"));
	wxFont Button4Font(18,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	Button4->SetFont(Button4Font);
	Button5 = new wxButton(Panel1, ID_BUTTON11, _("5"), wxPoint(104,368), wxSize(80,80), 0, wxDefaultValidator, _T("ID_BUTTON11"));
	wxFont Button5Font(18,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	Button5->SetFont(Button5Font);
	Button6 = new wxButton(Panel1, ID_BUTTON12, _("6"), wxPoint(192,368), wxSize(80,80), 0, wxDefaultValidator, _T("ID_BUTTON12"));
	wxFont Button6Font(18,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	Button6->SetFont(Button6Font);
	Substract_btn = new wxButton(Panel1, ID_BUTTON13, _("-"), wxPoint(280,368), wxSize(80,80), 0, wxDefaultValidator, _T("ID_BUTTON13"));
	Substract_btn->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENUHILIGHT));
	wxFont Substract_btnFont(18,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	Substract_btn->SetFont(Substract_btnFont);
	One_btn = new wxButton(Panel1, ID_BUTTON14, _("1"), wxPoint(16,456), wxSize(80,80), 0, wxDefaultValidator, _T("ID_BUTTON14"));
	wxFont One_btnFont(18,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	One_btn->SetFont(One_btnFont);
	Two_btn = new wxButton(Panel1, ID_BUTTON15, _("2"), wxPoint(104,456), wxSize(80,80), 0, wxDefaultValidator, _T("ID_BUTTON15"));
	wxFont Two_btnFont(18,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	Two_btn->SetFont(Two_btnFont);
	Three_btn = new wxButton(Panel1, ID_BUTTON16, _("3"), wxPoint(192,456), wxSize(80,80), 0, wxDefaultValidator, _T("ID_BUTTON16"));
	wxFont Three_btnFont(18,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	Three_btn->SetFont(Three_btnFont);
	Add_btn = new wxButton(Panel1, ID_BUTTON17, _("+"), wxPoint(280,456), wxSize(80,80), 0, wxDefaultValidator, _T("ID_BUTTON17"));
	Add_btn->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENUHILIGHT));
	wxFont Add_btnFont(18,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	Add_btn->SetFont(Add_btnFont);
	Button7 = new wxButton(Panel1, ID_BUTTON18, _("0"), wxPoint(104,544), wxSize(80,80), 0, wxDefaultValidator, _T("ID_BUTTON18"));
	wxFont Button7Font(18,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	Button7->SetFont(Button7Font);
	Button8 = new wxButton(Panel1, ID_BUTTON19, _("."), wxPoint(192,544), wxSize(80,80), 0, wxDefaultValidator, _T("ID_BUTTON19"));
	wxFont Button8Font(18,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	Button8->SetFont(Button8Font);
	Sign_change_btn = new wxButton(Panel1, ID_BUTTON20, _("+ / -"), wxPoint(16,544), wxSize(80,80), 0, wxDefaultValidator, _T("ID_BUTTON20"));
	wxFont Sign_change_btnFont(18,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	Sign_change_btn->SetFont(Sign_change_btnFont);
	Calculate_btn = new wxButton(Panel1, ID_BUTTON21, _("="), wxPoint(280,544), wxSize(80,80), 0, wxDefaultValidator, _T("ID_BUTTON21"));
	Calculate_btn->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INFOBK));
	wxFont Calculate_btnFont(18,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	Calculate_btn->SetFont(Calculate_btnFont);
	Result_txtbox = new wxTextCtrl(Panel1, ID_TEXTCTRL2, wxEmptyString, wxPoint(16,64), wxSize(168,48), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	wxFont Result_txtboxFont(20,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	Result_txtbox->SetFont(Result_txtboxFont);
	BCSP_btn = new wxButton(Panel1, ID_BUTTON22, _("Backspace"), wxPoint(192,128), wxSize(168,56), 0, wxDefaultValidator, _T("ID_BUTTON22"));
	wxFont BCSP_btnFont(14,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	BCSP_btn->SetFont(BCSP_btnFont);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Calculator::Onclose_btnClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Calculator::OnC_btnClick);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Calculator::OnBrackets_btnClick);
	Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Calculator::OnDivide_btnClick);
	Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Calculator::OnSeven_btnClick);
	Connect(ID_BUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Calculator::OnEight_btnClick);
	Connect(ID_BUTTON8,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Calculator::OnNine_btnClick);
	Connect(ID_BUTTON9,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Calculator::OnButton3Click);
	Connect(ID_BUTTON10,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Calculator::OnButton4Click);
	Connect(ID_BUTTON11,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Calculator::OnButton5Click);
	Connect(ID_BUTTON12,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Calculator::OnButton6Click);
	Connect(ID_BUTTON13,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Calculator::OnSubstract_btnClick);
	Connect(ID_BUTTON14,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Calculator::OnOne_btnClick);
	Connect(ID_BUTTON15,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Calculator::OnTwo_btnClick);
	Connect(ID_BUTTON16,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Calculator::OnThree_btnClick);
	Connect(ID_BUTTON17,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Calculator::OnAdd_btnClick);
	Connect(ID_BUTTON18,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Calculator::OnButton7Click);
	Connect(ID_BUTTON19,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Calculator::OnButton8Click);
	Connect(ID_BUTTON21,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Calculator::OnCalculate_btnClick);
	Connect(ID_BUTTON22,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Calculator::OnBCSP_btnClick);
	//*)
}

Calculator::~Calculator()
{
	//(*Destroy(Calculator)
	//*)
}

using namespace std;

//---------------------------------------------------------
//---------------------------------------------------------

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == 'x' || c == '/';
}

bool isHigherPrecedence(char op1, char op2)
{
    int prec1 = (op1 == '+' || op1 == '-') ? 1 : 2;
    int prec2 = (op2 == '+' || op2 == '-') ? 1 : 2;
    return (prec1 >= prec2);
}

//---------------------------------------------------------

wxString StringToONP(const wxString& wyrazenie)
{
    stack<char> stos_znakow;
    wxString wyrazenie_wyjscia = "";

    for (int i = 0; i < wyrazenie.length(); i++)
    {
        if (isdigit(wyrazenie[i]))
        {
            while (i < wyrazenie.length() && (isdigit(wyrazenie[i]) || wyrazenie[i] == '.'))
            {
                wyrazenie_wyjscia += wyrazenie[i];
                i++;
            }
            wyrazenie_wyjscia += ' ';
            i--;
        }
        else if (wyrazenie[i] == '(')
        {
            stos_znakow.push(wyrazenie[i]);
        }
        else if (wyrazenie[i] == ')')
        {
            while (!stos_znakow.empty() && stos_znakow.top() != '(')
            {
                wyrazenie_wyjscia += stos_znakow.top();
                stos_znakow.pop();
            }
            stos_znakow.pop();
        }
        else if (isOperator(wyrazenie[i]))
        {
            while (!stos_znakow.empty() && isOperator(stos_znakow.top()) && isHigherPrecedence(stos_znakow.top(), wyrazenie[i]))
            {
                wyrazenie_wyjscia += stos_znakow.top();
                stos_znakow.pop();
            }
            stos_znakow.push(wyrazenie[i]);
        }
    }

    while (!stos_znakow.empty())
    {
        wyrazenie_wyjscia += stos_znakow.top();
        stos_znakow.pop();
    }

    return wyrazenie_wyjscia;
}

//---------------------------------------------------------

double CalculateRPN(const wxString& rpn)
{
    stack<double> stos_wynikowy;
    wxString liczba = "";

    for(int i = 0; i < rpn.length(); i++)
    {
        if (isdigit(rpn[i]))
        {
            while (i < rpn.length() && (isdigit(rpn[i]) || rpn[i] == '.'))
            {
                liczba += rpn[i];
                i++;
            }
            i--;

            double n;
            //double n = wxString::ToDouble(liczba);
            if(!liczba.ToDouble(&n)){ /* error! */ }
            stos_wynikowy.push(n);
            liczba = "";
        }
        else if(isOperator(rpn[i]))
        {
            char oper = rpn[i];
            double result;
            double a = stos_wynikowy.top();
            stos_wynikowy.pop();
            double b = stos_wynikowy.top();
            stos_wynikowy.pop();

            switch(oper)
            {
                case '+': result = b + a; break;
                case '-': result = b - a; break;
                case 'x': result = b * a; break;
                case '/': result = b / a; break;
            }

            stos_wynikowy.push(result);
        }
    }

    if(stos_wynikowy.size() == 1)
    {
        double wynik = stos_wynikowy.top();
        stos_wynikowy.pop();
        return wynik;
    }
    else
    {
        wxString message = "Syntax error";
    }
}

//---------------------------------------------------------

void Calculator::UpdateResult()
{
    wxString rownanie = Screen_txtbox->GetValue();
    wxString rownanie_rpn = StringToONP(rownanie);
    double wynik = CalculateRPN(rownanie_rpn);
    wxString wynik_ost = wxString::FromDouble(wynik);
    Result_txtbox->SetValue(wynik_ost);
}
//---------------------------------------------------------
//---------------------------------------------------------

wxString GetLastCharacter(wxTextCtrl* txtbox)
{
    wxString last_char;
    wxString text = txtbox->GetValue();
    if(text != "")
    {
        last_char = text[text.length() - 1];
        return last_char;
    }
    else
    {
        last_char = ' ';
        return last_char;
    }
}

bool separator_possible = true;

void Calculator::OnBCSP_btnClick(wxCommandEvent& event)
{
    wxString currentText = Screen_txtbox->GetValue();
    wxString newText = "";

    if(currentText == "")
    {
        return;
    }

    for(int i = 0; i < currentText.Length() - 1; i++)
    {
        newText += currentText[i];
    }

    Screen_txtbox->SetValue(newText);
    Result_txtbox->SetValue("");
}

void Calculator::OnButton7Click(wxCommandEvent& event)
{
    wxString currentText = Screen_txtbox->GetValue();
    currentText += "0";
    Screen_txtbox->SetValue(currentText);

    //wxString RPNequation = EquationToRPN(currentText);
    //wxString result = wxString::FromDouble(evaluateRPN(RPNequation));
    //Result_txtbox->SetValue(result);
    UpdateResult();
}

void Calculator::Onclose_btnClick(wxCommandEvent& event)
{
    Close(true);
}

void Calculator::OnOne_btnClick(wxCommandEvent& event)
{
    wxString currentText = Screen_txtbox->GetValue();
    currentText += "1";
    Screen_txtbox->SetValue(currentText);

    //wxString RPNequation = EquationToRPN(currentText);
    //wxString result = wxString::FromDouble(evaluateRPN(RPNequation));
    //Result_txtbox->SetValue(result);
    UpdateResult();
}

void Calculator::OnTwo_btnClick(wxCommandEvent& event)
{
    wxString currentText = Screen_txtbox->GetValue();
    currentText += "2";
    Screen_txtbox->SetValue(currentText);

    //wxString RPNequation = EquationToRPN(currentText);
    //wxString result = wxString::FromDouble(evaluateRPN(RPNequation));
    //Result_txtbox->SetValue(result);
    UpdateResult();
}

void Calculator::OnThree_btnClick(wxCommandEvent& event)
{
    wxString currentText = Screen_txtbox->GetValue();
    currentText += "3";
    Screen_txtbox->SetValue(currentText);

    //wxString RPNequation = EquationToRPN(currentText);
    //wxString result = wxString::FromDouble(evaluateRPN(RPNequation));
    //Result_txtbox->SetValue(result);
    UpdateResult();
}

void Calculator::OnButton4Click(wxCommandEvent& event)
{
    wxString currentText = Screen_txtbox->GetValue();
    currentText += "4";
    Screen_txtbox->SetValue(currentText);

    //wxString RPNequation = EquationToRPN(currentText);
    //wxString result = wxString::FromDouble(evaluateRPN(RPNequation));
    //Result_txtbox->SetValue(result);
    UpdateResult();
}

void Calculator::OnButton5Click(wxCommandEvent& event)
{
    wxString currentText = Screen_txtbox->GetValue();
    currentText += "5";
    Screen_txtbox->SetValue(currentText);

    //wxString RPNequation = EquationToRPN(currentText);
    //wxString result = wxString::FromDouble(evaluateRPN(RPNequation));
    //Result_txtbox->SetValue(result);
    UpdateResult();
}

void Calculator::OnButton6Click(wxCommandEvent& event)
{
    wxString currentText = Screen_txtbox->GetValue();
    currentText += "6";
    Screen_txtbox->SetValue(currentText);

    //wxString RPNequation = EquationToRPN(currentText);
    //wxString result = wxString::FromDouble(evaluateRPN(RPNequation));
    //Result_txtbox->SetValue(result);
    UpdateResult();
}

void Calculator::OnSeven_btnClick(wxCommandEvent& event)
{
    wxString currentText = Screen_txtbox->GetValue();
    currentText += "7";
    Screen_txtbox->SetValue(currentText);

    //wxString RPNequation = EquationToRPN(currentText);
    //wxString result = wxString::FromDouble(evaluateRPN(RPNequation));
    //Result_txtbox->SetValue(result);
    UpdateResult();
}

void Calculator::OnEight_btnClick(wxCommandEvent& event)
{
    wxString currentText = Screen_txtbox->GetValue();
    currentText += "8";
    Screen_txtbox->SetValue(currentText);

    //wxString RPNequation = EquationToRPN(currentText);
    //wxString result = wxString::FromDouble(evaluateRPN(RPNequation));
    //Result_txtbox->SetValue(result);
    UpdateResult();
}

void Calculator::OnNine_btnClick(wxCommandEvent& event)
{
    wxString currentText = Screen_txtbox->GetValue();
    currentText += "9";
    Screen_txtbox->SetValue(currentText);

    //wxString RPNequation = EquationToRPN(currentText);
    //wxString result = wxString::FromDouble(evaluateRPN(RPNequation));
    //Result_txtbox->SetValue(result);
    UpdateResult();
}

void Calculator::OnBrackets_btnClick(wxCommandEvent& event)
{
    wxString currentText = Screen_txtbox->GetValue();
    if(GetLastCharacter(Screen_txtbox) == '(' || GetLastCharacter(Screen_txtbox) == ' ' || GetLastCharacter(Screen_txtbox) == '+' || GetLastCharacter(Screen_txtbox) == '-' || GetLastCharacter(Screen_txtbox) == '/' || GetLastCharacter(Screen_txtbox) == 'x')
    {
        currentText += "(";
        Screen_txtbox->SetValue(currentText);
        separator_possible = true;
    }
    else
    {
        currentText += ")";
        Screen_txtbox->SetValue(currentText);
        separator_possible = true;
    }
}

void Calculator::OnDivide_btnClick(wxCommandEvent& event)
{
    if (GetLastCharacter(Screen_txtbox) == '/' || GetLastCharacter(Screen_txtbox) == 'x' || GetLastCharacter(Screen_txtbox) == '+' || GetLastCharacter(Screen_txtbox) == '-')
    {
        OnBCSP_btnClick(event);
        wxString currentText = Screen_txtbox->GetValue();
        currentText += "/";
        Screen_txtbox->SetValue(currentText);
        separator_possible = true;
    }
    else if (GetLastCharacter(Screen_txtbox) == ' ')
    {
        return;
    }
    else
    {
        wxString currentText = Screen_txtbox->GetValue();
        currentText += "/";
        Screen_txtbox->SetValue(currentText);
        separator_possible = true;
    }
}

void Calculator::OnButton3Click(wxCommandEvent& event)
{
    if (GetLastCharacter(Screen_txtbox) == '/' || GetLastCharacter(Screen_txtbox) == 'x' || GetLastCharacter(Screen_txtbox) == '+' || GetLastCharacter(Screen_txtbox) == '-')
    {
        OnBCSP_btnClick(event);
        wxString currentText = Screen_txtbox->GetValue();
        currentText += "x";
        Screen_txtbox->SetValue(currentText);
        separator_possible = true;
    }
    else if (GetLastCharacter(Screen_txtbox) == ' ')
    {
        return;
    }
    else
    {
        wxString currentText = Screen_txtbox->GetValue();
        currentText += "x";
        Screen_txtbox->SetValue(currentText);
        separator_possible = true;
    }
}

void Calculator::OnSubstract_btnClick(wxCommandEvent& event)
{
    if (GetLastCharacter(Screen_txtbox) == '/' || GetLastCharacter(Screen_txtbox) == 'x' || GetLastCharacter(Screen_txtbox) == '+' || GetLastCharacter(Screen_txtbox) == '-')
    {
        OnBCSP_btnClick(event);
        wxString currentText = Screen_txtbox->GetValue();
        currentText += "-";
        Screen_txtbox->SetValue(currentText);
        separator_possible = true;
    }
    else if (GetLastCharacter(Screen_txtbox) == ' ')
    {
        return;
    }
    else
    {
        wxString currentText = Screen_txtbox->GetValue();
        currentText += "-";
        Screen_txtbox->SetValue(currentText);
        separator_possible = true;
    }
}

void Calculator::OnAdd_btnClick(wxCommandEvent& event)
{
    if (GetLastCharacter(Screen_txtbox) == '/' || GetLastCharacter(Screen_txtbox) == 'x' || GetLastCharacter(Screen_txtbox) == '+' || GetLastCharacter(Screen_txtbox) == '-')
    {
        OnBCSP_btnClick(event);
        wxString currentText = Screen_txtbox->GetValue();
        currentText += "+";
        Screen_txtbox->SetValue(currentText);
        separator_possible = true;
    }
    else if (GetLastCharacter(Screen_txtbox) == ' ')
    {
        return;
    }
    else
    {
        wxString currentText = Screen_txtbox->GetValue();
        currentText += "+";
        Screen_txtbox->SetValue(currentText);
        separator_possible = true;
    }
}

void Calculator::OnButton8Click(wxCommandEvent& event)
{
    wxString last = GetLastCharacter(Screen_txtbox);
    if(last.IsNumber() == true && separator_possible == true)
    {
        separator_possible = false;
        wxString currentText = Screen_txtbox->GetValue();
        currentText += ".";
        Screen_txtbox->SetValue(currentText);
    }
}

void Calculator::OnC_btnClick(wxCommandEvent& event)
{
    wxString currentText = Screen_txtbox->GetValue();
    currentText = "";
    Screen_txtbox->SetValue(currentText);

    wxString currentTextR = Result_txtbox->GetValue();
    currentTextR = "";
    Result_txtbox->SetValue(currentTextR);

    separator_possible = true;
}



void Calculator::OnCalculate_btnClick(wxCommandEvent& event)
{
    UpdateResult();
}
