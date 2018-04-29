/**************************************************************************
 * Name:      TetherApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Joshua Gerrity (comments@dynaggelos.com)
 * Created:   2018-03-04
 * Copyright: Joshua Gerrity (biblicalwiki.com)
 * License:
 *************************************************************************/

#ifndef WX_PRECOMP
#   include <wx/wx.h>
#endif // WX_PRECOMP

/* Compiler Setup ********************************************************/
#ifdef WX_PRECOMP
#   include "wx_pch.h"
#endif // WX_PRECOMP

#ifdef __BORLANDC__
#   pragma hdrstop
#endif // __BORLANDC__

/* wxWidgets Build Setup */
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#       if defined(__WXMSW__)
            wxbuild << _T("-Windows");
#       elif defined(__WXMAC__)
            wxbuild << _T("-Mac");
#       elif defined(__UNIX__)
            wxbuild << _T("-Linux");
#       endif

#       if wxUSE_UNICODE
            wxbuild << _T("-Unicode build");
#       else
            wxbuild << _T("-ANSI build");
#       endif // wxUSE_UNICODE
    }

    return wxbuild;
}

/* Begin *****************************************************************/
#include "TetherApp.h"
#include "TetherFrame.h"

wxIMPLEMENT_APP(TetherApp);     // Bind TetherApp to wx startup process

/* Member Function: OnInit() **********************************************
 * Automatically called by wxWidgets once library setup is complete. This
 * is essentially the apps "main".
 *-------------------------------------------------------------------------
 * Parameters: void
 * Returns: (true)
 *************************************************************************/
bool TetherApp::OnInit()
{
    /* Set Up Handlers */
    // Image Handlers
    wxImage::AddHandler(new wxXPMHandler);
    
    /* Instantiate Main Window */
    TetherFrame *mainWindow = new TetherFrame();

    mainWindow->Show();

    return true;
}