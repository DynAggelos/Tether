/**************************************************************************
 * Name:      TetherTextCtrl.h
 * Purpose:   Defines Text Editor Box
 * Author:    Joshua Gerrity (comments@dynaggelos.com)
 * Created:   2018-03-08
 * Copyright: Joshua Gerrity (biblicalwiki.com)
 * License:
 *************************************************************************/

#pragma once

#ifndef WX_PRECOMP
#   include <wx/wx.h>
#endif // WX_PRECOMP

class TetherTextCtrl : public wxTextCtrl
{
    public:
        TetherTextCtrl(
            wxWindow* parent,
            const int& id,
            const wxString& title,
            const wxPoint& position = wxDefaultPosition,
            const wxSize& size = wxDefaultSize);
        ~TetherTextCtrl();
};