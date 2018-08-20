/**************************************************************************
 * Name:      TetherTextCtrl.h
 * Purpose:   Defines Text Editor Box
 * Author:    Joshua Gerrity (comments@dynaggelos.com)
 * Created:   2018-03-08
 * Copyright: Joshua Gerrity (biblicalwiki.com)
 * License:
 *************************************************************************/

#pragma once

#ifndef WX_STC
#   include <wx/stc/stc.h>
#endif // WX_STC

class TetherTextCtrl : public wxStyledTextCtrl
{
    public:
        TetherTextCtrl(
            wxWindow* parent,
            const int& id = wxID_ANY,
            const wxPoint& position = wxDefaultPosition,
            const wxSize& size = wxDefaultSize);
        ~TetherTextCtrl();
    
    private:
        /* Constants */
        const int margin1 = 1;

        /* Variables */
        int margin1Width = 35;
};