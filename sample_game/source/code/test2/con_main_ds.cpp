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
#include <stdio.h>
#include <conio.h>

#include "base_types.h"
#include "base_print.h"
#include "base_io.h"
#include "base_console.h"
#include "base_def.h"

//#include "exp_allocator.h"
#include "base_ds_vector.h"

//#include <vector>
//#include <string>

class pool_alloc1 {
public:
    char* block8 = nullptr;
    isz chunk_size = 2;
    char* free8_head = nullptr;

    void allocate_memory() { //isz num_blocks) {
        block8 = scast<char*>(malloc(
            sizeof(char)*8*chunk_size + sizeof(size_t)
        ));

        free8_head = block8;
    }

    void deallocate_memory() {
        free(block8);
        block8 = nullptr;
    }
};


int main() {
    printf("Hello, World!\n");
    printfln("con_main ds");
    printfln("---------------------");

    pool_alloc1 pa1;
    pa1.allocate_memory();

    strcpy(pa1.block8, "hello1");
    strcpy(pa1.block8 + 8, "hello2");

    println("{}", pa1.block8);
    println("{}", pa1.block8 + 8);

    pa1.deallocate_memory();

#if 0
    //sdf::vector<int> vc2;

    //vc2.resize(8);
    //println("{}, {}", vc2.size(), vc2.capacity());
    //vc2.push_back(3);
    //println("{}, {}", vc2.size(), vc2.capacity());

    sdf::basic_string<char> vc2;
    vc2.resize(33);
    println("{}, {}", vc2.size(), vc2.capacity());
    vc2.resize(40);
    println("{}, {}", vc2.size(), vc2.capacity());
    vc2.resize(6);
    println("{}, {}", vc2.size(), vc2.capacity());

    vc2.reserve(70);
    println("{}, {}", vc2.size(), vc2.capacity());
    vc2.reserve(7);
    println("{}, {}", vc2.size(), vc2.capacity());
#endif

#if 0
    char* block8 = scast<char*>(malloc(sizeof(char)*16 + sizeof(size_t)));
    char* a = block8;
    char* b = block8+8;

    for_range(i, 0, 16) { printf("%i ", a[i]); } printf("\n");
    for_range(i, 0, 16) { printf("%c ", a[i]); } printf("\n");
    for_range(i, 0, 16) { printf("%.2X ", a[i]); } printf("\n");

    strcpy(a, "hello1");
    strcpy(b, "hello2");

    println("{}", a);
    println("{}", b);

    for_range(i, 0, 16) { printf("%i ", a[i]); } printf("\n");
    for_range(i, 0, 16) { printf("%c ", a[i]); } printf("\n");
    for_range(i, 0, 16) { printf("%.2X ", a[i]); } printf("\n");

    free(block8);
    block8 = nullptr;
#endif


    printfln("---------------------");

    //-----------
    //do {} while(GetAsyncKeyState(VK_ESCAPE)==0);
    constexpr int ESCAPE = 27; int k = 0; do { k = _getch(); } while (k != ESCAPE);
    //_getch();
    //getch();
    return 0;
}

