/**************************************************************************
 * Name:      TetherFileFrame.h
 * Purpose:   Defines the File Dialog Frame
 * Author:    Joshua Gerrity (comments@dynaggelos.com)
 * Created:   2018-03-24
 * Copyright: Joshua Gerrity (biblicalwiki.com)
 * License:
 *************************************************************************/

#pragma once

#ifndef WX_FRAME
#   include <wx/frame.h>
#endif // WX_FRAME

#ifndef WX_FILE_DLG
#   include <wx/filedlg.h>
#endif // WX_FILE_DLG

class TetherFileFrame : public wxFrame
{
    public:
        TetherFileFrame(
            wxWindow* parent,
            wxWindowID id,
            const wxString& title,
            const wxString& fileOperation);
        ~TetherFileFrame();

        const wxString& getFilePath()
        {
            return filePath;
        }

    private:
        /* Class Pointers */
        wxFileDialog* fileDialogue = nullptr;

        /* Objects (in Stack) */
        wxString filePath;

        /* Creation Member Functions */
        void createFileDialogue(const wxString& fileOperation);

        /* Unused Constructor */
        TetherFileFrame() {}
};