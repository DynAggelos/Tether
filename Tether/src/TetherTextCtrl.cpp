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
    // Default Styling
}

TetherTextCtrl::~TetherTextCtrl()
{}