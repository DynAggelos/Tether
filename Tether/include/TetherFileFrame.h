/**************************************************************************
 * Name:      TetherFileFrame.h
 * Purpose:   Defines the File Dialog Frame
 * Author:    Joshua Gerrity (comments@dynaggelos.com)
 * Created:   2018-03-24
 * Copyright: Joshua Gerrity (biblicalwiki.com)
 * License:
 *************************************************************************/

#pragma once

#ifndef WX_PRECOMP
#   include <wx/wx.h>
#endif // WX_PRECOMP

class TetherFileFrame : public wxFrame
{
    public:
        TetherFileFrame(
            wxWindow* parent,
            wxWindowID id,
            const wxString& title,
            const wxString& fileOperation);
        ~TetherFileFrame();

        const wxArrayString& getFilePath();

    private:
        /* Pointers to Objects */
        wxFileDialog* fileDialogue = nullptr;

        /* Static Objects */
        wxArrayString filePath;

        /* Creation Member Functions */
        void createFileDialogue(const wxString& fileOperation);

        /* Unused Constructor */
        TetherFileFrame() {}
};