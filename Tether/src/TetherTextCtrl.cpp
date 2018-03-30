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
    const wxString& title,
    const wxPoint& position,
    const wxSize& size)
    : wxTextCtrl(
        parent,
        id,
        title,
        position,
        size,
        (wxTE_MULTILINE | wxTE_RICH | wxTE_NOHIDESEL))
{}

TetherTextCtrl::~TetherTextCtrl()
{}

/* bool wxTextCtrl::LoadFile(
    const wxString& filename,
    int fileType = wxTEXT_TYPE_ANY)
{

}*/