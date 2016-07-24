//
//  SGSDL2Input.h
//  sgsdl2
//
//  Created by Andrew Cain on 7/12/2013.
//  Copyright (c) 2013 Andrew Cain. All rights reserved.
//

#ifndef sgsdl2_SGSDL2Input_h
#define sgsdl2_SGSDL2Input_h

#include "backend_types.h"

typedef void (sk_empty_procedure)( void );
typedef void (sk_intp_proc)( int ms );
typedef void (sk_int_intp_proc)( int x, int y );
typedef void (sk_charp_proc)(char* text);
typedef void (sk_window_xy_proc)(pointer window, int x, int y);

struct sk_input_callbacks
{
    sk_empty_procedure * do_quit;

    sk_intp_proc * handle_key_down;
    sk_intp_proc * handle_key_up;

    sk_intp_proc * handle_mouse_up;
    sk_intp_proc * handle_mouse_down;
    sk_int_intp_proc * handle_mouse_wheel;

    sk_charp_proc * handle_input_text;

    sk_window_xy_proc * handle_window_resize;
    sk_window_xy_proc *handle_window_move;
};

extern sk_input_callbacks _input_callbacks;

void sk_process_events();
int sk_window_close_requested(sk_drawing_surface* surf);
int sk_key_pressed(int key_code);
void sk_start_unicode_text_input(int x, int y, int w, int h);
void sk_warp_mouse(sk_drawing_surface *surface, int x, int y);
pointer sk_focus_window();
void sk_window_position(sk_drawing_surface *surface, int *x, int *y);
sk_window_data sk_get_window_event_data(sk_drawing_surface *surface);
void sk_move_window(sk_drawing_surface *surface, int x, int y);


#endif /* defined(__sgsdl2__SGSDL2Input__) */