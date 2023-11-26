#if _MSC_VER
	#pragma comment( linker, "/subsystem:console" )
#endif

#if defined(_MSC_VER)		
	#pragma comment(lib, "user32.lib")
	#pragma comment(lib, "gdi32.lib")
#endif

#include <stdio.h>
#include <conio.h>

//------------------------------------------------

#include "base_types.h"
#include "base_print.h"
#include "base_io.h"
#include "base_console.h"
#include "base_def.h"

//lua, squirrel, gravity, wren

//#include "exp_allocator.h"
//#include "base_ds_vector.h"

//#include <vector>
//#include <string>

class pool_alloc1 {
public:

};


int main() {
    printf("Hello, World!\n");
    printfln("con_main ds");
    printfln("---------------------");

    


    printfln("---------------------");

    //-----------
    //do {} while(GetAsyncKeyState(VK_ESCAPE)==0);
    constexpr int ESCAPE = 27; int k = 0; do { k = _getch(); } while (k != ESCAPE);
    //_getch();
    //getch();
    return 0;
}

