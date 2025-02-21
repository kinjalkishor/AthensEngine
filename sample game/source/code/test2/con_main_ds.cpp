#if _MSC_VER
	#pragma comment( linker, "/subsystem:console" )
#endif

#if defined(_MSC_VER)		
	#pragma comment(lib, "user32.lib")
	#pragma comment(lib, "gdi32.lib")
#endif

#include <stdio.h>
#include <conio.h>


int main() {
    printf("Hello, World!\n");
    //printfln("---------------------");




    //printfln("---------------------");

    //-----------
    //do {} while(GetAsyncKeyState(VK_ESCAPE)==0);
    constexpr int ESCAPE = 27; int k = 0; do { k = _getch(); } while (k != ESCAPE);
    //_getch();
    //getch();
    return 0;
}

