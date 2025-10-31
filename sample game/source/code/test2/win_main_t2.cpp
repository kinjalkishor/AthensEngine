#if defined(_MSC_VER)
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")
#endif

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <stdint.h>
#include <stdio.h>

#include "bs_console.h"
#include "bs_format.h"

#include "wa_app_simple.h"
#include "wa_sys.h"

//#include "en_game_timer.h"

#include "t2_rs_d3d11.h"

//---
#include "bg_gmath.h"
// #include "bg_gmath_d3d9xwn.h"
//-------------------------

class app_vars {
public:
    bool app_quit = false;
    bool app_active = true;
    bool app_minimized = false;
};
app_vars g_av;

//---------------------------------------------
LRESULT CALLBACK MainWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

//======================================
// WinMain
//======================================
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow) {
    std_console gconstd;
    gconstd.create_window("Std Console", 864, 0, 640, 640);
    printf("SysConsole Initialized.\n");
    print("Sample t2\n");

    //-------------------------
    int xpos = 10;
    int ypos = 50;
    int width = 720;
    int height = 405;
    bool fullscreen = false;
    const char* wnd_title = "Sample t2";

    const char* APP_CLASS_NAME = "SAMPLE_APP_CLASS";
    HWND m_hwnd = nullptr;

    winapp nw_app;
    nw_app.init(MainWndProc, hInstance, APP_CLASS_NAME);
    nw_app.create_window(wnd_title, xpos, ypos, width, height, false, false);
    m_hwnd = nw_app.get_main_hwnd();

    std::unique_ptr<irenderer> rs;
    rs = std::make_unique<rd3d11>();
    rs->init_r(hInstance, m_hwnd, width, height, fullscreen);
    rs->setup();
    //---
            //---game_timer_qpc nw_timer;
            //---int64_t prev_time_qpc = nw_timer.get_time();

    // program main loop
    while (!g_av.app_quit) {
        // nw_app.poll_events();
        nw_app.poll_events();

        // if (nw_app.is_quit_msg()) { g_av.sys_quit(); }
        if (nw_app.is_quit_msg()) {
            g_av.app_quit = true;
        }

        if (g_av.app_active && !g_av.app_minimized) {
                //---int64_t curr_time_qpc = nw_timer.get_time();
                //---float delta_time_qpc = (curr_time_qpc - prev_time_qpc) * nw_timer.period();

            // process_input();
            // calculate_frame_stats();
                //---rs->render(delta_time_qpc);
            rs->swap_buffers();

                //---prev_time_qpc = curr_time_qpc;

        } else {
            sys_sleep(1);
            continue;
        }

    } // while: not app_quit

    rs->cleanup();
    rs->deinit_r();

    nw_app.deinit();

    return nw_app.msg_return();
}

//======================================
// Window Procedure
//======================================
LRESULT CALLBACK MainWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_ACTIVATE:
        g_av.app_active = static_cast<bool>(LOWORD(wParam) != WA_INACTIVE);
        g_av.app_minimized = static_cast<bool>(HIWORD(wParam));
        return 0;

    case WM_CREATE:
        return 0;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_CLOSE:
        PostQuitMessage(0);
        return 0;

    case WM_QUIT:
        PostQuitMessage(0);
        return 0;

    case WM_KEYDOWN:
        // gkeys[wParam] = true;
        switch (wParam) {
        case VK_ESCAPE:
            PostQuitMessage(0);
            return 0;
        }
        return 0;

    case WM_KEYUP:
        // gkeys[wParam] = false;
        return 0;

    default:
        break;
    }

    return DefWindowProcW(hWnd, uMsg, wParam, lParam);
}