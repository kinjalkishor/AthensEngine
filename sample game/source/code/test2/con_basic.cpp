#if _MSC_VER
#pragma comment(linker, "/subsystem:console")
#endif

#if defined(_MSC_VER)
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")
#endif

#include <conio.h>
#include <stdio.h>

// GetAsyncKeyState
// #define WIN32_LEAN_AND_MEAN
// #include <Windows.h>
// #if defined(_MSC_VER)
//	#pragma comment(lib, "user32.lib")
// #endif

int main() {
    printf("Hello, World!\n");
    // printfln("---------------------");

    // printfln("---------------------");

    //-----------
    // do {} while(GetAsyncKeyState(VK_ESCAPE)==0);
    constexpr int ESCAPE = 27;
    int k = 0;
    do {
        k = _getch();
    } while (k != ESCAPE);
    //_getch();
    // getch();
    return 0;
}
