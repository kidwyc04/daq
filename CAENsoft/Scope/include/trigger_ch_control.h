/////////////////////////////////////////////////////////////////////////////
// Name:        trigger_ch_control.h
// Purpose:     
// Author:      NDA
// Modified by: 
// Created:     05/04/2006 15:38:26
// RCS-ID:      
// Copyright:   CAEN S.p.A All rights reserved.
// Licence:     
/////////////////////////////////////////////////////////////////////////////

// Generated by DialogBlocks (unregistered), 05/04/2006 15:38:26

#ifndef _TRIGGER_CH_CONTROL_H_
#define _TRIGGER_CH_CONTROL_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "trigger_ch_control.h"
#endif

/*!
 * Includes
 */

////@begin includes
#include "wx/spinctrl.h"
////@end includes

#include "generic_board.h"
#include "physical_board_channel.h"
/*!
 * Forward declarations
 */

////@begin forward declarations
class wxSpinCtrl;
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_TRIGGER_CH_DIALOG 10015
#define SYMBOL_TRIGGERCHCONTROL_STYLE 0
#define SYMBOL_TRIGGERCHCONTROL_TITLE _("TriggerChControl")
#define SYMBOL_TRIGGERCHCONTROL_IDNAME ID_TRIGGER_CH_DIALOG
#define SYMBOL_TRIGGERCHCONTROL_SIZE wxSize(400, 300)
#define SYMBOL_TRIGGERCHCONTROL_POSITION wxDefaultPosition
#define ID_THRESHOLD_SPINCTRL 10017
#define ID_THR_SAMPLES_SPINCTRL 10018
////@end control identifiers

/*!
 * Compatibility
 */

#ifndef wxCLOSE_BOX
#define wxCLOSE_BOX 0x1000
#endif

/*!
 * TriggerChControl class declaration
 */

class TriggerChControl: public wxPanel
{    
    DECLARE_DYNAMIC_CLASS( TriggerChControl )
        DECLARE_EVENT_TABLE()

        public:
    /// Constructors
    TriggerChControl( );
    TriggerChControl( wxWindow* parent, wxWindowID id = SYMBOL_TRIGGERCHCONTROL_IDNAME, const wxPoint& pos = SYMBOL_TRIGGERCHCONTROL_POSITION, const wxSize& size = SYMBOL_TRIGGERCHCONTROL_SIZE, long style = SYMBOL_TRIGGERCHCONTROL_STYLE );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_TRIGGERCHCONTROL_IDNAME, const wxPoint& pos = SYMBOL_TRIGGERCHCONTROL_POSITION, const wxSize& size = SYMBOL_TRIGGERCHCONTROL_SIZE, long style = SYMBOL_TRIGGERCHCONTROL_STYLE );

    /// Creates the controls and sizers
    void CreateControls();

////@begin TriggerChControl event handler declarations

    /// wxEVT_COMMAND_SPINCTRL_UPDATED event handler for ID_THRESHOLD_SPINCTRL
    void OnThresholdSpinctrlUpdated( wxSpinEvent& event );

    /// wxEVT_COMMAND_SPINCTRL_UPDATED event handler for ID_THR_SAMPLES_SPINCTRL
    void OnThrSamplesSpinctrlUpdated( wxSpinEvent& event );

////@end TriggerChControl event handler declarations
    void OnThresholdSpinctrlTextUpdated( wxCommandEvent& event );
    void OnThrSamplesSpinctrlTextUpdated( wxCommandEvent& event );

////@begin TriggerChControl member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end TriggerChControl member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin TriggerChControl member variables
    wxStaticBox* m_main_sizer_text;
    wxSpinCtrl* m_ch_threshold_control;
    wxSpinCtrl* m_thr_sample_control;
////@end TriggerChControl member variables

    bool SetupBoard( GenericBoard* p_board, int ch_index, int ch_count);
    bool UpdateControls( );
private: 
    // Generic Board pointer
    GenericBoard* m_p_board;
    PhysicalBoardChannel* m_p_board_channel;
    int m_ch_index;
    int m_ch_count;
    void UpdateThreshold( int value);
    void UpdateThrSamples( int value);
};

#endif
// _TRIGGER_CH_CONTROL_H_
