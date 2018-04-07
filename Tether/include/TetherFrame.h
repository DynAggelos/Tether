/**************************************************************************
 * Name:      TetherFrame.h
 * Purpose:   Defines Application Frame
 * Author:    Joshua Gerrity (comments@dynaggelos.com)
 * Created:   2018-03-04
 * Copyright: Joshua Gerrity (biblicalwiki.com)
 * License:
 *************************************************************************/

#pragma once

#include "TetherTextCtrl.h"
#include "TetherFileFrame.h"

#ifndef WX_FRAME
#   include <wx/frame.h>
#endif // WX_FRAME

#ifndef WX_MSG_DLG
#   include <wx/msgdlg.h>
#endif // WX_MSG_DLG

#ifndef WX_MENU
#   include <wx/menu.h>
#endif // WX_MENU

class TetherFrame : public wxFrame
{
    public:
        TetherFrame();
        ~TetherFrame();

    private:
        /* Class Pointers */
        wxMenuBar* menuBar = nullptr;
        wxMenu* fileMenu = nullptr;
        wxMenu* toolsMenu = nullptr;

        TetherTextCtrl* textBox1 = nullptr;
        TetherTextCtrl* textBox2 = nullptr;

        TetherFileFrame* fileFrame = nullptr;

        wxMessageDialog* noticeBox = nullptr;

        /* Objects (in Stack) */
        wxString filePath;
        wxString textBox1LoadPath;

        /* Creation Member Functions */
        void createMenu();

        /* Event-Handling Member Functions */
        void onNewFile(const wxCommandEvent& event);
        void onOpenFile(const wxCommandEvent& event);
        void onSaveFile(const wxCommandEvent& event);
        void onSaveAsFile(const wxCommandEvent& event);
        void OnClose(const wxCloseEvent& event);
};