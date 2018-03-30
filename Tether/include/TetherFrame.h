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

#ifndef WX_PRECOMP
#   include <wx/wx.h>
#endif // WX_PRECOMP

class TetherFrame: public wxFrame
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

        /* Stack Objects */
        wxArrayString filePaths;

        /* Creation Member Functions */
        void createMenu();

        /* Event-Handling Member Functions */
        void onNewFile(const wxCommandEvent& event);
        void onOpenFile(const wxCommandEvent& event);
        void OnClose(const wxCloseEvent& event);
};