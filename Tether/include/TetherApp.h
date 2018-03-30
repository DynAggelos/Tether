/**************************************************************************
 * Name:      TetherApp.h
 * Purpose:   Defines Application Class
 * Author:    Joshua Gerrity (comments@dynaggelos.com)
 * Created:   2018-03-04
 * Copyright: Joshua Gerrity (biblicalwiki.com)
 * License:
 *************************************************************************/

#pragma once

#ifndef WX_PRECOMP
#   include <wx/wx.h>
#endif // WX_PRECOMP

class TetherApp : public wxApp
{
    public:
        virtual bool OnInit();
};