#if defined(_MSC_VER)		
	#pragma comment(lib, "user32.lib")
	#pragma comment(lib, "gdi32.lib")
#endif

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <stdio.h>

using uint = unsigned int;
using int64 = signed long long int;
using uint64 = unsigned long long int;


bool app_quit = false;
bool app_active = true;
bool app_minimized = false;


LRESULT CALLBACK MainWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

//======================================
// WinMain
//======================================
int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow) {
    //static TCHAR szAppName[] = TEXT("HelloWin");
    const wchar_t* APP_CLASS_NAME = L"SAMPLE_APP_CLASS";

    HWND m_hwnd = nullptr;
    MSG m_msg = {};

    // Register window class
    WNDCLASSEX wc = {};
    wc.cbSize = sizeof(wc);
	wc.style = CS_HREDRAW|CS_VREDRAW;
	wc.lpfnWndProc = MainWndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIconW(nullptr, IDI_APPLICATION);
	wc.hCursor = LoadCursorW(nullptr, IDC_ARROW);
	//wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.hbrBackground = CreateSolidBrush(RGB(25, 25, 112));
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = APP_CLASS_NAME;
	wc.hIconSm = LoadIconW(nullptr, IDI_APPLICATION);

    if (!RegisterClassExW(&wc)) {
		//MessageBoxW(nullptr, L"Cannot Register WinApi Class.\n", L"Error", MB_ICONEXCLAMATION|MB_OK);
		printf("Cannot Register WinApi Class.\n");
		//return false;
	}


    //-------------------------
    int xpos = 10;
	int ypos = 50;
	int width = 720;
	int height = 405;
	const wchar_t* wnd_title = L"Sample window";

	uint dwStyle = 0;
	uint dwExStyle = 0;
	dwStyle = WS_OVERLAPPEDWINDOW | WS_VISIBLE | WS_CLIPSIBLINGS|WS_CLIPCHILDREN;
	dwExStyle = WS_EX_APPWINDOW|WS_EX_WINDOWEDGE;

	int x, y, w, h;
	RECT window_rect = {0, 0, width, height};
	AdjustWindowRectEx(&window_rect, dwStyle, false, dwExStyle);
	x = xpos + window_rect.left;
	y = ypos + window_rect.top;
	w = window_rect.right - window_rect.left;
	h = window_rect.bottom - window_rect.top;	

	HWND handle_wnd = CreateWindowExW(dwExStyle,					
						APP_CLASS_NAME,			        
						wnd_title,	 		
						dwStyle,
						x, y, w, h,
						nullptr, nullptr, hInstance, nullptr);									

	if (!handle_wnd) {							
		printf("Cannot Create Window.\n");
		//return false;
	}  
		
	//ShowWindow(handle_wnd, iCmdShow);
	ShowWindow(handle_wnd, SW_SHOW);   	
	UpdateWindow(handle_wnd); 
	SetForegroundWindow(handle_wnd);						
	SetFocus(handle_wnd);									

	m_hwnd = handle_wnd;


    while (GetMessageW(&m_msg, nullptr, 0, 0)) {
        TranslateMessage(&m_msg);
        DispatchMessageW(&m_msg);
    }    
	     

	/*
	while (m_msg.message != WM_QUIT) {
		if (PeekMessageW(&m_msg, nullptr, 0, 0, PM_REMOVE)) {
			TranslateMessage(&m_msg);
			DispatchMessageW(&m_msg);
		} else {	
			//do rendering
		}
	}
	*/
	
	/*	
	while (!app_quit) {
		if (PeekMessageW(&m_msg, nullptr, 0, 0, PM_REMOVE)) {
			TranslateMessage(&m_msg);
			DispatchMessageW(&m_msg);
		}

		if (m_msg.message == WM_QUIT) { app_quit = true; }	

		if (app_active && !app_minimized) {		
            // do rendering
		} else {
    		Sleep(1);
			continue;
		}         
    } // while: not app_quit
	*/


    DestroyWindow(m_hwnd);
	UnregisterClassW(APP_CLASS_NAME, hInstance);

    return static_cast<int>(m_msg.wParam);
}


//======================================
// Window Procedure
//======================================
LRESULT CALLBACK MainWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg) {
    case WM_ACTIVATE:	
		// Check for WA_INACTIVE, as active has various states.
		//if (LOWORD(wParam) == WA_INACTIVE) {
		//	app_active = false;
		//} else {
		//	app_active = true;
		//}
		app_active = static_cast<bool>(LOWORD(wParam) != WA_INACTIVE);
		app_minimized = static_cast<bool>(HIWORD(wParam));
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






     




