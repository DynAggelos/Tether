/**************************************************************************
 * Name:      TetherTextCtrl.cpp
 * Purpose:   Code for Text Editor Box Class
 * Author:    Joshua Gerrity (comments@dynaggelos.com)
 * Created:   2018-03-08
 * Copyright: Joshua Gerrity (biblicalwiki.com)
 * License:
 *************************************************************************/

#include "TetherTextCtrl.h"

TetherTextCtrl::TetherTextCtrl(
    wxWindow* parent,
    const int& id,
    const wxPoint& position,
    const wxSize& size)
    : wxStyledTextCtrl(
        parent,
        id,
        position,
        size)
{
    /* Settings ---------------------------------------------------------*/
    /* Margins */
    //this->SetMarginLeft(0);
    this->SetMarginWidth(margin1, margin1Width);    // Set margin to x px's
    this->SetMarginSensitive(margin1, true);        // no clicking margin
    this->SetMarginType(margin1, wxSTC_MARGIN_NUMBER);
    this->SetMarginCursor(margin1, wxSTC_CURSORARROW);

    /* Word Wrap */
    this->SetWrapMode(wxSTC_WRAP_WORD);
    this->SetWrapIndentMode(wxSTC_WRAPINDENT_SAME);
    this->SetWrapVisualFlags(wxSTC_WRAPVISUALFLAG_MARGIN);
}

TetherTextCtrl::~TetherTextCtrl()
{}