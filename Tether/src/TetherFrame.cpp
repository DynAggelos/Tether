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
    this->SetMinSize(wxSize(750, 500));
    this->Center(wxBOTH);

    /* Create Menu Bar Above */
    this->createMenu();

    /* Create Status Bar Below */
    this->CreateStatusBar(2);

    /* Set up textBox1 */
    textBox1 = new TetherTextCtrl(
        this,
        -1,
        _("---"),
        wxDefaultPosition,
        wxDefaultSize);

    /* Bind Events */
    // Frame Binding
    Bind(wxEVT_CLOSE_WINDOW, &TetherFrame::OnClose, this);

    // Menu Bindings
    Bind(wxEVT_MENU, &TetherFrame::onNewFile, this, wxID_NEW);
    Bind(wxEVT_MENU, &TetherFrame::onOpenFile, this, wxID_OPEN);
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
 * Handles the creation of the menu and all of its objects.
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

/* Member Function: onNewFile() *******************************************
 * Clears textBox1 when the associated menu event takes place.
 *-------------------------------------------------------------------------
 * Parameters:
 *      event -- A parameter required by wxWidgets
 * Returns: void
 *************************************************************************/
void TetherFrame::onNewFile(const wxCommandEvent& event)
{
    textBox1->Clear();
}

/* Member Function: onOpenFile() ******************************************
 * Creates a new file window frame when the associated menu event takes
 * place.
 *-------------------------------------------------------------------------
 * Parameters:
 *      event -- A parameter required by wxWidgets
 * Returns: void
 *************************************************************************/
void TetherFrame::onOpenFile(const wxCommandEvent& event)
{
    if (textBox1->IsModified())
    {
        // Dialogue box about losing changes
    }
    
    fileFrame = new TetherFileFrame(
        this,
        wxID_AUTO_HIGHEST,
        _("Load"),
        wxT("load"));
    
    filePaths = fileFrame->getFilePaths();

    for (unsigned short i = 0; i < (filePaths.GetCount()); i++)
    {
        textBox1->LoadFile(filePaths.Index(i));
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