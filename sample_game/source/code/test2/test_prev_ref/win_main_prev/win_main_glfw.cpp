
#if defined(_MSC_VER)		
	#pragma comment(lib, "user32.lib")
	#pragma comment(lib, "gdi32.lib")
#endif

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <stdio.h>

using int64 = signed long long int;
using uint = unsigned int;
using uint64 = unsigned long long int;
#define scast	static_cast

bool app_active = true;
bool app_quit = false;

LRESULT CALLBACK MainWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

//======================================
// WinMain
//======================================

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow) {
     //static TCHAR szAppName[] = TEXT ("HelloWin") ;
    const wchar_t* APP_CLASS_NAME = L"SAMPLE_APP_CLASS";
    HWND m_hwnd = nullptr;
    MSG m_msg = {};

    // register window class
	WNDCLASSEX wcex = {};
	wcex.cbSize = sizeof(wcex);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = MainWndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIconW(nullptr, IDI_APPLICATION);
	wcex.hCursor = LoadCursorW(nullptr, IDC_ARROW);
	//wcex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wcex.hbrBackground = CreateSolidBrush(RGB(25, 25, 112));
	wcex.lpszMenuName = nullptr;
	wcex.lpszClassName = APP_CLASS_NAME;
	wcex.hIconSm = LoadIconW(nullptr, IDI_APPLICATION);

    if (!RegisterClassExW(&wcex)) {
		printf("Cannot Register WinApi Class.\n");
	}


    //-------------------------
    int xpos = 10;
	int ypos = 50;
	int width = 800;
	int height = 450;
	const wchar_t* wnd_title = L"Sample window";

	uint dwStyle = 0;
	uint dwExStyle = 0;
	dwStyle = WS_OVERLAPPEDWINDOW | WS_VISIBLE | WS_CLIPSIBLINGS|WS_CLIPCHILDREN;
	dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;

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
	}  
		
	//ShowWindow(handle_wnd, iCmdShow);
	ShowWindow(handle_wnd, SW_SHOW);   	
	UpdateWindow(handle_wnd); 
	SetForegroundWindow(handle_wnd);						
	SetFocus(handle_wnd);									

	m_hwnd = handle_wnd;

     
    while (GetMessageW(&m_msg, nullptr, 0, 0)) {
        TranslateMessage(&m_msg) ;
        DispatchMessageW(&m_msg) ;
    }

	/*
	while(m_msg.message != WM_QUIT) {
		if(PeekMessageW(&m_msg, nullptr, 0, 0, PM_REMOVE)) {
			TranslateMessage(&m_msg);
			DispatchMessageW(&m_msg);
		} else {	
			//do rendering
		}
	}
	*/
	
	/*	
	while (!app_quit) {
		if(PeekMessageW(&m_msg, nullptr, 0, 0, PM_REMOVE)) {
			TranslateMessage(&m_msg);
			DispatchMessageW(&m_msg);
		}

		if (m_msg.message == WM_QUIT) { app_quit = true; }	

		if (app_active) {			
            // do rendering
		} else {
    		Sleep(1);
			continue;
		}         
    } // while: not app_quit
	*/

    DestroyWindow(handle_wnd);
	UnregisterClassW(APP_CLASS_NAME, hInstance);
    return scast<int>(m_msg.wParam);
}


//======================================
// Window Procedure
//======================================

LRESULT CALLBACK MainWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

    switch (uMsg) {
    case WM_ACTIVATE:			
		if (LOWORD(wParam) == WA_INACTIVE) {
			app_active = false;
		} else {
			app_active = true;
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
