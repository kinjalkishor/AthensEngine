#if _MSC_VER
	#pragma comment( linker, "/subsystem:console" )
#endif

#if defined(_MSC_VER)		
	#pragma comment(lib, "user32.lib")
	#pragma comment(lib, "gdi32.lib")
#endif

#include <stdio.h>
#include <conio.h>

#include "base_types.h"
#include "base_print.h"
#include "base_io.h"
#include "base_console.h"
#include "base_def.h"

#include "base_win_util.h"


#include "fg_std.h"

// hello.c
//#include <GL/glut.h>
#include <stdlib.h>

void display_01_01(void) {
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glClear (GL_COLOR_BUFFER_BIT);
   glColor3f (1.0, 1.0, 1.0);
   glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
   glBegin(GL_POLYGON);
      glVertex3f (0.25, 0.25, 0.0);
      glVertex3f (0.75, 0.25, 0.0);
      glVertex3f (0.75, 0.75, 0.0);
      glVertex3f (0.25, 0.75, 0.0);
   glEnd();
   glFlush();
}

void display_01_02_hello(void)
{
/* clear all pixels  */
   glClear (GL_COLOR_BUFFER_BIT);

/* draw white polygon (rectangle) with corners at
 * (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)  
 */
   glColor3f (1.0, 1.0, 1.0);
   glBegin(GL_POLYGON);
      glVertex3f (0.25, 0.25, 0.0);
      glVertex3f (0.75, 0.25, 0.0);
      glVertex3f (0.75, 0.75, 0.0);
      glVertex3f (0.25, 0.75, 0.0);
   glEnd();

/* don't wait!  
 * start processing buffered OpenGL routines 
 */
   glFlush ();
}

void init_hello (void) 
{
/* select clearing color 	*/
   glClearColor (0.2, 0.2, 0.2, 0.0);

/* initialize viewing values  */
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

//======================================
LRESULT CALLBACK MainWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

//======================================
// WinMain
//======================================
/* 
 * Declare initial window size, position, and display mode
 * (single buffer and RGBA).  Open window with "hello"
 * in its title bar.  Call initialization routines.
 * Register callback function to display graphics.
 * Enter main loop and process events.
 */

//int main(int argc, char** argv) {
int main() {
    set_console_window_pos( 864, 0, 640, 640);
    set_console_window_colors();

    printf("Hello, World!\n");
    printfln("win_main fg");	
    //printfln("---------------------");

    fgState.hInstance = nullptr;
    fgState.wnd_proc = MainWndProc;

    int argc = 0; char** argv = nullptr;

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    //glutInitWindowSize (250, 250); 
    //glutInitWindowPosition (100, 100);
    glutCreateWindow ("fg window", 10, 50, 800, 450);
    fg_init_gl();

    init_hello();
    glutDisplayFunc(display_01_02_hello); 


    glutMainLoop();

    fg_deinit_gl();
    fg_deinit();
    //printfln("---------------------");

    //return scast<int>(fgState.m_msg.wParam);

    //-----------
    //do {} while(GetAsyncKeyState(VK_ESCAPE)==0);
    //constexpr int ESCAPE = 27; int k = 0; do { k = _getch(); } while (k != ESCAPE);
    //_getch();
    //getch();
    return 0;
}


//======================================
// Window Procedure
//======================================

LRESULT CALLBACK MainWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

    switch (uMsg) {
    case WM_ACTIVATE:			
		if (LOWORD(wParam) == WA_INACTIVE) {
			fgState.app_active = false;
		} else {
			fgState.app_active = true;
		}
		return 0;		

    case WM_CREATE:
        return 0;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_CLOSE:
		//DestroyWindow(hWnd);
        PostQuitMessage(0);        
        return 0;

    case WM_QUIT:
        PostQuitMessage(0);        
        return 0;

    case WM_KEYDOWN:
        switch (wParam) {
		case VK_ESCAPE:
            PostQuitMessage(0);
            return 0;
        }
        return 0;								


    default: break;
    } 
    
    return DefWindowProcW(hWnd, uMsg, wParam, lParam);
}



