#if defined(_MSC_VER)
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")
#endif

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <stdint.h>
#include <stdio.h>

#include <format>

#include <chrono>
#include <thread>

namespace sdf2 {

//-------------------
template <class... _Types>
inline void print(const std::string_view _Fmt, const _Types&... _Args) {
    printf("%s", std::vformat(_Fmt, std::make_format_args(_Args...)).c_str());
}

//-------------------
class std_console {
private:
    void* hconsole = nullptr;

    static const uint32_t color_black = 0;
    static const uint32_t color_blue = 1;
    static const uint32_t color_green = 2;
    static const uint32_t color_cyan = 3;
    static const uint32_t color_red = 4;
    static const uint32_t color_magenta = 5;
    static const uint32_t color_yellow = 6;
    static const uint32_t color_white = 7;

    ptrdiff_t wstr_assign_ansi(wchar_t* dest, ptrdiff_t dest_capacity, const char* src, ptrdiff_t src_len) {
        ptrdiff_t copy_len = (src_len > dest_capacity) ? dest_capacity : src_len;
        const int dest_cap_with_null_char = dest_capacity + 1;
        int result = MultiByteToWideChar(CP_UTF8, 0, src, copy_len, dest, dest_cap_with_null_char);
        if (!result) {
            return 0;
        }
        dest[copy_len] = L'\0';
        return copy_len;
    }

public:
    std_console() { }
    ~std_console() { FreeConsole(); }

    bool create_window(const char* window_title, int xpos, int ypos, int width, int height) {
        if (!AllocConsole()) {
            MessageBoxW(nullptr, L"Couldn't create output console", L"Error", 0);
            return false;
        }

        HWND console_window = GetConsoleWindow();
        MoveWindow(console_window, xpos, ypos, width, height, TRUE);

        wchar_t wconsole_title[256] = {};
        // sdf::wstr_assign_ansi(wconsole_title, sdf::strz_cap(wconsole_title), window_title, sdf::strz_len(window_title));
        wstr_assign_ansi(wconsole_title, (sizeof(wconsole_title) / sizeof(wconsole_title[0]) - 1), window_title, strlen(window_title));
        SetWindowTextW(console_window, wconsole_title);

        // The freopen_s function closes the file currently associated with stream and reassigns stream to the file specified by path.
        freopen("conin$", "r", stdin);
        freopen("conout$", "w", stdout);
        freopen("conout$", "w", stderr);
        // printf("Debugging Window:\n");

        hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hconsole, color_yellow);

        // win_console_enable_color_print();

        return true;
    }
};

//-------------------
void sys_sleep(uint32_t dwMilliseconds) {
    // Sleep(dwMilliseconds);
    std::this_thread::sleep_for(std::chrono::milliseconds(dwMilliseconds));
}

//-------------------
class game_timer_qpc {
public:
    float period() {
        int64_t cnts_per_sec = 0;
        QueryPerformanceFrequency((LARGE_INTEGER*)&cnts_per_sec);
        // secs_per_cnt_qpc is 0.0000001f, 1e-07;
        float secs_per_cnt_qpc = 1.0f / static_cast<float>(cnts_per_sec);
        // println("{}", secs_per_cnt_qpc);
        return secs_per_cnt_qpc;
    }

    int64_t get_time() {
        // Retrieves the current value of the performance counter,
        // which is a high resolution (<1 micro second) time stamp.
        int64_t prev_time_qpc = 0;
        QueryPerformanceCounter((LARGE_INTEGER*)&prev_time_qpc);
        return prev_time_qpc;
    }
};

}

using namespace sdf2;

//-------------------------
namespace wm_wnd2 {

class wm_irenderer {
public:
    wm_irenderer() { }
    virtual ~wm_irenderer() { }

    virtual bool init_r(HINSTANCE hInstance, HWND hwnd, int width, int height, bool fullscreen) { return false; }
    virtual void deinit_r() { }

    virtual void setup() { }
    virtual void cleanup() { }
    virtual void render(float dt) { }
    virtual void swap_buffers() { }
};

class wm_rd3d11 : public wm_irenderer {
public:
    bool init_r(HINSTANCE hInstance, HWND hwnd, int width, int height, bool fullscreen) { return true; }
    void deinit_r() { }

    void setup() { }
    void cleanup() { }
    void render(float dt) { }
    void swap_buffers() { }
};

class app_vars {
public:
    bool app_quit = false;
    bool app_active = true;
    bool app_minimized = false;
};
app_vars g_av;

//-------------------------
class winapp {
private:
    ptrdiff_t wstr_assign_ansi(wchar_t* dest, ptrdiff_t dest_capacity, const char* src, ptrdiff_t src_len) {
        ptrdiff_t copy_len = (src_len > dest_capacity) ? dest_capacity : src_len;
        const int dest_cap_with_null_char = dest_capacity + 1;
        int result = MultiByteToWideChar(CP_UTF8, 0, src, copy_len, dest, dest_cap_with_null_char);
        if (!result) {
            return 0;
        }
        dest[copy_len] = L'\0';
        return copy_len;
    }

public:
    wchar_t m_app_class_name[64] = { L'S', L'A', L'\0' };
    WNDPROC m_wnd_proc = nullptr;
    HINSTANCE m_hInstance = nullptr;
    HWND m_hwnd = nullptr;
    MSG m_msg = {};

    bool init(WNDPROC wnd_proc, HINSTANCE hInstance, const char* app_class_name) {

        // sdf::wstr_assign_ansi(m_app_class_name, sdf::strz_cap(m_app_class_name), app_class_name, sdf::strz_len(app_class_name));
        wstr_assign_ansi(m_app_class_name, (sizeof(m_app_class_name) / sizeof(m_app_class_name[0]) - 1), app_class_name, strlen(app_class_name));

        m_wnd_proc = wnd_proc;
        m_hInstance = hInstance;

        // Register window class
        WNDCLASSEX wc = {};
        wc.cbSize = sizeof(wc);
        wc.style = CS_OWNDC; // CS_HREDRAW|CS_VREDRAW;
        wc.lpfnWndProc = m_wnd_proc;
        wc.cbClsExtra = 0;
        wc.cbWndExtra = 0;
        wc.hInstance = m_hInstance;
        wc.hIcon = LoadIconW(nullptr, IDI_APPLICATION);
        wc.hCursor = LoadCursorW(nullptr, IDC_ARROW);
        // wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
        wc.hbrBackground = CreateSolidBrush(RGB(25, 25, 112));
        wc.lpszMenuName = nullptr;
        wc.lpszClassName = m_app_class_name;
        wc.hIconSm = LoadIconW(nullptr, IDI_APPLICATION);

        if (!RegisterClassExW(&wc)) {
            printf("Cannot Register WinApi Class.\n");
            return false;
        }
        return true;
    }

    bool create_window(const char* wnd_title, int xpos, int ypos, int width, int height, bool fullscreen, bool borderless) {
        uint32_t dwStyle = 0;
        uint32_t dwExStyle = 0;
        dwStyle = WS_OVERLAPPEDWINDOW | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;
        dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;

        int x, y, w, h;
        RECT window_rect = { 0, 0, width, height };
        AdjustWindowRectEx(&window_rect, dwStyle, false, dwExStyle);
        x = xpos + window_rect.left;
        y = ypos + window_rect.top;
        w = window_rect.right - window_rect.left;
        h = window_rect.bottom - window_rect.top;

        wchar_t wstr_wnd_title[256] = {};
        // sdf::wstr_assign_ansi(wstr_wnd_title, sdf::strz_cap(wstr_wnd_title), wnd_title, sdf::strz_len(wnd_title));
        wstr_assign_ansi(wstr_wnd_title, (sizeof(wstr_wnd_title) / sizeof(wstr_wnd_title[0]) - 1), wnd_title, strlen(wnd_title));

        HWND handle_wnd = CreateWindowExW(dwExStyle,
            m_app_class_name,
            wstr_wnd_title,
            dwStyle,
            x, y, w, h,
            nullptr, nullptr, m_hInstance, nullptr);

        if (!handle_wnd) {
            printf("Cannot Create Window.\n");
            return false;
        }

        ShowWindow(handle_wnd, SW_SHOW);
        UpdateWindow(handle_wnd);
        SetForegroundWindow(handle_wnd);
        SetFocus(handle_wnd);

        m_hwnd = handle_wnd;
        return true;
    }

    HWND get_main_hwnd() {
        return m_hwnd;
    }

    void poll_events() {
        if (PeekMessageW(&m_msg, nullptr, 0, 0, PM_REMOVE)) {
            TranslateMessage(&m_msg);
            DispatchMessageW(&m_msg);
        }
    }

    bool is_quit_msg() {
        return (m_msg.message == WM_QUIT);
    }

    int msg_return() {
        return static_cast<int>(m_msg.wParam);
    }

    void deinit() {
        DestroyWindow(m_hwnd);
        UnregisterClassW(m_app_class_name, m_hInstance);
    }
};

}

using namespace wm_wnd2;

//---------------------------------------------
LRESULT CALLBACK MainWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

//======================================
// WinMain
//======================================
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow) {
    std_console gconstd;
    gconstd.create_window("Std Console", 864, 0, 640, 640);
    printf("SysConsole Initialized.\n");
    print("Sample program\n");

    //-------------------------
    int xpos = 10;
    int ypos = 50;
    int width = 720;
    int height = 405;
    bool fullscreen = false;
    const char* wnd_title = "Sample window";

    const char* APP_CLASS_NAME = "SAMPLE_APP_CLASS";
    HWND m_hwnd = nullptr;

    winapp nw_app;
    nw_app.init(MainWndProc, hInstance, APP_CLASS_NAME);
    nw_app.create_window(wnd_title, xpos, ypos, width, height, false, false);
    m_hwnd = nw_app.get_main_hwnd();

    std::unique_ptr<wm_irenderer> rs;
    rs = std::make_unique<wm_rd3d11>();
    rs->init_r(hInstance, m_hwnd, width, height, fullscreen);
    rs->setup();
    //---
    game_timer_qpc nw_timer;
    int64_t prev_time_qpc = nw_timer.get_time();

    // program main loop
    while (!g_av.app_quit) {
        // nw_app.poll_events();
        nw_app.poll_events();

        // if (nw_app.is_quit_msg()) { g_av.sys_quit(); }
        if (nw_app.is_quit_msg()) {
            g_av.app_quit = true;
        }

        if (g_av.app_active && !g_av.app_minimized) {
            int64_t curr_time_qpc = nw_timer.get_time();
            float delta_time_qpc = (curr_time_qpc - prev_time_qpc) * nw_timer.period();

            // process_input();
            // calculate_frame_stats();
            rs->render(delta_time_qpc);
            rs->swap_buffers();

            prev_time_qpc = curr_time_qpc;

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

