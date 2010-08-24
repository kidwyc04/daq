/////////////////////////////////////////////////////////////////////////////
// Name:        drawing_panel.h
// Purpose:     
// Author:      NDA
// Modified by: 
// Created:     06/04/2006 16:00:41
// RCS-ID:      
// Copyright:   CAEN S.p.A All rights reserved.
// Licence:     
/////////////////////////////////////////////////////////////////////////////

// Generated by DialogBlocks (unregistered), 06/04/2006 16:00:41

#ifndef _DRAWING_PANEL_H_
#define _DRAWING_PANEL_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "drawing_panel.h"
#endif
#include "appsettings.h"
#include "drawing_left_canvas.h"
#include "drawing_canvas.h"

/*!
 * Includes
 */

////@begin includes
////@end includes

/*!
 * Forward declarations
 */

////@begin forward declarations
class DrawingLeftCanvas;
class DrawingCanvas;
////@end forward declarations
class wxBufferedPaintDC ;
class wxMutex;
class AppSettings;
/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_MYDIALOG 10026
#define SYMBOL_DRAWINGPANEL_STYLE 0
#define SYMBOL_DRAWINGPANEL_TITLE _("DrawingPanel")
#define SYMBOL_DRAWINGPANEL_IDNAME ID_MYDIALOG
#define SYMBOL_DRAWINGPANEL_SIZE wxSize(400, 300)
#define SYMBOL_DRAWINGPANEL_POSITION wxDefaultPosition
#define ID_LEFT_PANEL 10027
#define ID_DRAW_PANEL 10028
////@end control identifiers

/*!
 * Compatibility
 */

#ifndef wxCLOSE_BOX
#define wxCLOSE_BOX 0x1000
#endif

/*!
 * DrawingPanel class declaration
 */

class DrawingPanel: public wxPanel
{    
    DECLARE_DYNAMIC_CLASS( DrawingPanel )
        DECLARE_EVENT_TABLE()

        public:
    /// Constructors
    DrawingPanel( );
    DrawingPanel( int scope_index, wxWindow* parent, wxWindowID id = SYMBOL_DRAWINGPANEL_IDNAME, const wxPoint& pos = SYMBOL_DRAWINGPANEL_POSITION, const wxSize& size = SYMBOL_DRAWINGPANEL_SIZE, long style = SYMBOL_DRAWINGPANEL_STYLE );
    ~DrawingPanel( );
 
    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_DRAWINGPANEL_IDNAME, const wxPoint& pos = SYMBOL_DRAWINGPANEL_POSITION, const wxSize& size = SYMBOL_DRAWINGPANEL_SIZE, long style = SYMBOL_DRAWINGPANEL_STYLE );

    /// Creates the controls and sizers
    void CreateControls();

////@begin DrawingPanel event handler declarations

    /// wxEVT_SIZE event handler for ID_MYDIALOG
    void OnSize( wxSizeEvent& event );

    /// wxEVT_PAINT event handler for ID_MYDIALOG
    void OnPaint( wxPaintEvent& event );

    /// wxEVT_ERASE_BACKGROUND event handler for ID_MYDIALOG
    void OnEraseBackground( wxEraseEvent& event );

////@end DrawingPanel event handler declarations

////@begin DrawingPanel member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end DrawingPanel member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin DrawingPanel member variables
////@end DrawingPanel member variables

    DrawingLeftCanvas* m_draw_left_canvas;
    DrawingCanvas* m_draw_canvas;
    AppSettings *m_app_settings;
    void Freeze( void);
    bool IsFreezed( void){ return this->m_freezed;}
    void RefreshBackBitmap( void);
    void RefreshLeftBackBitmap( void);
protected:
    bool m_freezed;
    int m_scope_index;

    wxMutex m_mutex;

};

#endif
// _DRAWING_PANEL_H_
