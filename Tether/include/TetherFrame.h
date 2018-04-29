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
#include "TetherOptionsDialogue.h"

#ifndef WX_FRAME
#   include <wx/frame.h>
#endif // WX_FRAME

#ifndef WX_MSG_DLG
#   include <wx/msgdlg.h>
#endif // WX_MSG_DLG

#ifndef WX_MENU
#   include <wx/menu.h>
#endif // WX_MENU

#ifndef WX_TOOLBAR
#   include <wx/toolbar.h>
#endif // WX_TOOLBAR

#ifndef WX_BITMAP
#   include <wx/bitmap.h>
#endif // WX_BITMAP

class TetherFrame : public wxFrame
{
    public:
        TetherFrame();
        ~TetherFrame();

    private:
        /* Class Pointers */
        // Menu Pointers
        wxMenuBar* menuBar = nullptr;
        wxMenu* fileMenu = nullptr;
        wxMenu* toolsMenu = nullptr;

        // Bitmap Pointers
        //wxBitmap* toolBitmap = nullptr;

        // Toolbar Pointers
        wxToolBar* toolbar = nullptr;

        // Text Box Pointers
        TetherTextCtrl* textBox1 = nullptr;
        TetherTextCtrl* textBox2 = nullptr;

        // File-Frame Pointers
        TetherFileFrame* fileFrame = nullptr;

        // Dialogue Pointers
        wxMessageDialog* noticeBox = nullptr;
        wxPropertySheetDialog* propertyDialogue = nullptr;

        // Frame Pointers
        wxFrame* optionsFrame = nullptr;

        /* Object Identifiers (in Stack) */
        wxString filePath;
        wxString textBox1LoadPath;

        /* Creation Member Functions */
        void createMenu();
        void createToolbar();

        /* Event-Handling Member Functions */
        // Menu
        void onNewFile(const wxCommandEvent& event);
        void onOpenFile(const wxCommandEvent& event);
        void onSaveFile(const wxCommandEvent& event);
        void onSaveAsFile(const wxCommandEvent& event);

        // Toolbar
        void onUndoTextAction(const wxCommandEvent& event);
        void onRedoTextAction(const wxCommandEvent& event);

        // Close
        void OnClose(const wxCloseEvent& event);
};