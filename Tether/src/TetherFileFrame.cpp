/**************************************************************************
 * Name:      TetherFileFrame.cpp
 * Purpose:   Code for the File Dialog Frame
 * Author:    Joshua Gerrity (comments@dynaggelos.com)
 * Created:   2018-03-24
 * Copyright: Joshua Gerrity (biblicalwiki.com)
 * License:
 *************************************************************************/

#include "TetherFileFrame.h"

TetherFileFrame::TetherFileFrame(
    wxWindow* parent,
    wxWindowID id,
    const wxString& title,
    const wxString& fileOperation)
: wxFrame(parent, id, title)
{
    this->SetSize(wxSize(600, 500));
    this->SetMinSize(wxSize(400, 400));
    this->Center(wxBOTH);

    /* Instantiate File Dialogue */
    createFileDialogue(fileOperation);

    if (fileDialogue->ShowModal() != wxID_CANCEL)
    {
        /* Populate filePaths */
        filePath = fileDialogue->GetPath();
    }
}

TetherFileFrame::~TetherFileFrame()
{
    delete fileDialogue;
    fileDialogue = nullptr;
}

void TetherFileFrame::createFileDialogue(const wxString& fileOperation)
{
    if (fileOperation == "load")
    {
        fileDialogue = new wxFileDialog(
            this,
            _("Load File"),
            wxEmptyString,
            wxEmptyString,
            wxFileSelectorDefaultWildcardStr,
            (
                wxFD_OPEN
                | wxFD_FILE_MUST_EXIST
                | wxFD_CHANGE_DIR),
            wxDefaultPosition,
            wxDefaultSize,
            _("Load File"));
    }
    else
    {
        fileDialogue = new wxFileDialog(
            this,
            _("Save File"),
            wxEmptyString,
            wxEmptyString,
            wxFileSelectorDefaultWildcardStr,
            (
                wxFD_SAVE
                | wxFD_OVERWRITE_PROMPT
#               ifdef WIN32
                | wxFD_NO_FOLLOW
#               endif // WIN32
                | wxFD_CHANGE_DIR),
            wxDefaultPosition,
            wxDefaultSize,
            _("Save File"));
    }
}