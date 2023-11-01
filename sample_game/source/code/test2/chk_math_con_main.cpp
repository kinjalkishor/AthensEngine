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
#include "base_win_util.h"
#include "base_print.h"
//#include "base_def.h"

#include "chk_math.h"

#if 0
#pragma comment(lib, "wren.lib")
extern "C" {
    #include "wren.h"
}
void write(WrenVM* vm, const char* str) {
    printf("%s\n", str);
}
const char* wren_hello_prog = R"(System.print("WREN: Hello, world!"))";
#endif

namespace sdf 
{



}


//#include <iostream>
//#include "base_io.h"
//#include "base_gmath.h"


int main()
{
    set_console_window_pos(40, 35, 960, 540);
    printf("mathchk\n");
    printfln("---------------------");

    //gm::vec3 a(1, 2, 2);
    //println("{}", str(a));

    //---
#if 0
    // create the config that the virtual machine will use
    WrenConfiguration config;
    // fill the config with default values
    wrenInitConfiguration(&config);
    config.writeFn = write;

    WrenVM* vm = wrenNewVM(&config);
    // do something with your vm!
    WrenInterpretResult result = wrenInterpret(vm, "a", wren_hello_prog);
#endif
    //---

    check_math_func();

   

    printf("\n-------------------------\n");



    //printfln("---------------------");

    //-----------
    //do {} while(GetAsyncKeyState(VK_ESCAPE)==0);
    constexpr int ESCAPE = 27; int k = 0; do { k = _getch(); } while (k != ESCAPE);
    //_getch();
    //getch();
    return 0;
}

