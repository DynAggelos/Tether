/**************************************************************************
 * Name:      TetherOptionsFrame.h
 * Purpose:   Defines Options Dialogue
 * Author:    Joshua Gerrity (comments@dynaggelos.com)
 * Created:   2018-29-04
 * Copyright: Joshua Gerrity (biblicalwiki.com)
 * License:
 *************************************************************************/

#pragma once

#ifndef WX_PROPDLG
#   include <wx/propdlg.h>
#endif // WX_PROPDLG

#ifndef WX_CHECKBOX
#   include <wx/checkbox.h>
#endif // WX_CHECKBOX

class TetherOptionsDialogue : public wxPropertySheetDialog
{
    public:
        TetherOptionsDialogue(
            wxWindow* parent,
            const int& id,
            const wxString& title,
            const wxPoint& position,
            const wxSize& size,
            const long& style);
        ~TetherOptionsDialogue();

    private:
        //
};
