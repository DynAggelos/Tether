/**************************************************************************
 * Name:      TetherFrame.cpp
 * Purpose:   Code for Application Frame
 * Author:    Joshua Gerrity (comments@dynaggelos.com)
 * Created:   2018-03-04
 * Copyright: Joshua Gerrity (biblicalwiki.com)
 * License:
 *************************************************************************/

#include "TetherFrame.h"
#include "TetherTextCtrl.h"
#include "TetherFileFrame.h"

#include "Untitled.xpm"

/* Constructor: TetherFrame() *********************************************
 * Creates and binds all the elements of the main window frame in the app.
 *-------------------------------------------------------------------------
 * Parameters: void
 * Returns: void
 *************************************************************************/
TetherFrame::TetherFrame()
    : wxFrame(NULL, -1, _("Tether"))
{
    /* Position and Size Frame */
    this->SetSize(wxSize(700, 600));
    this->SetMinSize(wxSize(400, 400));
    this->Center(wxBOTH);

    /* Create Menu Bar Above */
    this->createMenu();

    /* Create Status Bar Below */
    this->CreateStatusBar(2);

    /* Create Toolbar */
    this->createToolbar();

    /* Set up textBox1 */
    textBox1 = new TetherTextCtrl(
        this);

    /* Bind Events */
    // Frame Binding
    Bind(wxEVT_CLOSE_WINDOW, &TetherFrame::OnClose, this);

    // Menu Bindings
    Bind(wxEVT_MENU, &TetherFrame::onNewFile, this, wxID_NEW);
    Bind(wxEVT_MENU, &TetherFrame::onOpenFile, this, wxID_OPEN);
    Bind(wxEVT_MENU, &TetherFrame::onSaveFile, this, wxID_SAVE);
    Bind(wxEVT_MENU, &TetherFrame::onSaveAsFile, this, wxID_SAVEAS);
}

/* Destructor: ~TetherFrame() *********************************************
 * An empty destructor.
 *-------------------------------------------------------------------------
 * Parameters: void
 * Returns: void
 *************************************************************************/
TetherFrame::~TetherFrame()
{}

/* Member Function: createMenu() ******************************************
 * Handles the creation of the menubar and all of its objects.
 *-------------------------------------------------------------------------
 * Parameters: void
 * Returns: void
 *************************************************************************/
void TetherFrame::createMenu()
{
    menuBar = new wxMenuBar();

    /* Create File Menu */
    fileMenu = new wxMenu();
    fileMenu->SetTitle(_("Files"));

    fileMenu->Append(wxID_NEW, _("New"), _("Start a new file"));
    fileMenu->Append(wxID_OPEN, _("Open"), _("Open an existing file"));
    fileMenu->Append(wxID_SAVE, _("Save"), _("Save an open file"));
    fileMenu->Append(
        wxID_SAVEAS,
        _("Save As"),
        _("Specify how to save an open file"));

    /* Create Tools Menu */
    toolsMenu = new wxMenu();
    toolsMenu->SetTitle(_("Tools"));
    toolsMenu->Append(
        wxID_PREFERENCES, _("Settings"), _("Open up the settings window"));

    /* Append Menus to Menubar */
    menuBar->Append(fileMenu, fileMenu->GetTitle());
    menuBar->Append(toolsMenu, toolsMenu->GetTitle());

    /* Associate Menubar with Frame */
    this->SetMenuBar(menuBar);
}

/* Member Function: createToolbar() ***************************************
 * Handles the creation of the toolbar and all of its objects.
 *-------------------------------------------------------------------------
 * Parameters: void
 * Returns: void
 *************************************************************************/
void TetherFrame::createToolbar()
{
    /* Instantiate Toolbar Bitmaps */
    toolBitmaps[0] = new wxBitmap(Untitled_xpm);

    /* Instantiate Toolbar */
    toolbar = this->CreateToolBar(wxTB_DEFAULT_STYLE | wxTB_TOP);
    toolbar->AddTool(
        wxID_ANY,
        _("Undo"),
        (const char**) toolBitmaps[0],
        _("Undo operation"));
    
    /* Display Toolbar */
    toolbar->Realize();
}

/* Member Function: onNewFile() *******************************************
 * Clears textBox1 when the associated menu event takes place.
 *-------------------------------------------------------------------------
 * Parameters:
 *      event -- A parameter required by wxWidgets
 * Returns: void
 *************************************************************************/
void TetherFrame::onNewFile(const wxCommandEvent& event)
{
    textBox1->ClearAll();
    if (textBox1->IsModified())
    {
        textBox1->DiscardEdits();
    }
}

/* Member Function: onOpenFile() ******************************************
 * Creates a new file window frame when the associated menu event takes
 * place. Loads the selected file into textBox1.
 *-------------------------------------------------------------------------
 * Parameters:
 *      event -- A parameter required by wxWidgets
 * Returns: void
 *************************************************************************/
void TetherFrame::onOpenFile(const wxCommandEvent& event)
{
    /* Warning Box if Unsaved Content */
    if (textBox1->IsModified())
    {
        noticeBox = new wxMessageDialog(
            this,
            _("There are unsaved changes at the moment."),
            wxMessageBoxCaptionStr,
            wxOK | wxICON_WARNING | wxCENTRE);
        noticeBox->ShowModal();

        // Clear Memory Once Selection Chosen
        delete noticeBox;
        noticeBox = nullptr;
    }

    /* Instantiate File Frame and Process Choice */
    fileFrame = new TetherFileFrame(
        this,
        wxID_AUTO_HIGHEST,
        _("Load"),
        wxT("load"));

    /* Get Chosen File Path for Processing */
    filePath = fileFrame->getFilePath();

    /* If Cancel Was Chosen */
    if (filePath == wxT(""))
    {
        // Do nothing
    }

    /* If File Doesn't Exist */
    else if (wxFileExists(filePath) == false)
    {
        noticeBox = new wxMessageDialog(
            this,
            _("Oops! That file couldn't be loaded."),
            wxMessageBoxCaptionStr,
            wxOK | wxICON_ERROR | wxCENTRE);
        noticeBox->ShowModal();

        // Clear Memory Once Selection Chosen
        delete noticeBox;
        noticeBox = nullptr;
    }

    /* Else Load File into Text Box 1 */
    else
    {
        textBox1->LoadFile(filePath);
        textBox1LoadPath = filePath;
    }
}

/* Member Function: onSaveFile() ******************************************
 * Saves the file from textBox1 with the same path it was opened with.
 *-------------------------------------------------------------------------
 * Parameters:
 *      event -- A parameter required by wxWidgets
 * Returns: void
 *************************************************************************/
void TetherFrame::onSaveFile(const wxCommandEvent& event)
{
    /* Don't Save if No Changes */
    if (textBox1->IsModified() == false)
    {
        // Do nothing
    }

    /* Proceed with Save if Changes */
    else
    {
        textBox1->SaveFile(textBox1LoadPath);
    }
}

/* Member Function: onSaveAsFile() ****************************************
 * Creates a new file window frame when the associated menu event takes
 * place. Saves the file from textBox1 as specified.
 *-------------------------------------------------------------------------
 * Parameters:
 *      event -- A parameter required by wxWidgets
 * Returns: void
 *************************************************************************/
void TetherFrame::onSaveAsFile(const wxCommandEvent& event)
{
    /* Instantiate File Frame and Process Choice */
    fileFrame = new TetherFileFrame(
        this,
        wxID_AUTO_HIGHEST,
        _("Save"),
        wxT("save"));

    /* Get Chosen File Path for Processing */
    filePath = fileFrame->getFilePath();

    /* If Cancel Was Chosen */
    if (filePath == wxT(""))
    {
        // Do nothing
    }

    /* Else Save File */
    else
    {
        textBox1->SaveFile(filePath);
    }
}

/* Member Function: OnClose() *********************************************
 * Destroys the Tether window frame when the close event takes place (the
 * X button on the window is used).
 *-------------------------------------------------------------------------
 * Parameters:
 *      event -- A parameter required by wxWidgets
 * Returns: void
 *************************************************************************/
void TetherFrame::OnClose(const wxCloseEvent& event)
{
    Destroy();
}