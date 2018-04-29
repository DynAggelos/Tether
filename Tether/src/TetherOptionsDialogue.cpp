/**************************************************************************
 * Name:      TetherOptionsDialogue.cpp
 * Purpose:   Code for Options Dialogue
 * Author:    Joshua Gerrity (comments@dynaggelos.com)
 * Created:   2018-29-04
 * Copyright: Joshua Gerrity (biblicalwiki.com)
 * License:
 *************************************************************************/

#include "TetherOptionsDialogue.h"

/* Constructor: TetherOptionsDialogue() ***********************************
 * Creates and sets up all the elements of the options window.
 *-------------------------------------------------------------------------
 * Parameters:
 *      parent -- The parent window class this window is associated with
 *      id -- The id of this window
 *      title -- The title to display at the top of the window
 *      position -- The default position of the window
 *      size -- The default size of the window
 *      style -- The style bitwise flags for this window
 * Returns: void
 *************************************************************************/
TetherOptionsDialogue::TetherOptionsDialogue(
    wxWindow* parent,
    const int& id,
    const wxString& title,
    const wxPoint& position,
    const wxSize& size,
    const long& style)
    : wxPropertySheetDialog(
        parent,
        id,
        title,
        position,
        size,
        style)
{
    //ctor
}

/* Destructor: ~TetherOptionsDialogue() ***********************************
 * An empty destructor.
 *-------------------------------------------------------------------------
 * Parameters: void
 * Returns: void
 *************************************************************************/
TetherOptionsDialogue::~TetherOptionsDialogue()
{
    //dtor
}
