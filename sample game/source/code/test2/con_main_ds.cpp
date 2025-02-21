#if _MSC_VER
	#pragma comment( linker, "/subsystem:console" )
#endif

#if defined(_MSC_VER)		
	#pragma comment(lib, "user32.lib")
	#pragma comment(lib, "gdi32.lib")
#endif

#include "bs_format.h"

#include <stdio.h>
#include <conio.h>

#include <string>
#include <vector>

#include "bs_ds_vector.h"
#include "bs_ds_string.h"


template<class T>
void vec_print_sc(sdf::vector<T> v) {
    print("size: {}, capacity: {}\n", v.size(), v.capacity());
}
template<class T>
void vec_print_data(sdf::vector<T> v) {
    for (ptrdiff_t i=0; i < v.size(); ++i) { 
        print("{}", v[i]);
    }
    print("\n");
}

int main() {
    printf("Hello, World!\n");
    //printfln("---------------------");
    sdf::vector<int> a = {0, 1, 2, 3, 4, 5, 6, 7};
    vec_print_sc(a);
    vec_print_data(a);
    int arr[2] = {1, 1};
    a.insert_range(3, &arr[0], 2);
    vec_print_sc(a);
    vec_print_data(a);
    a.remove_range(3, 2);
    vec_print_sc(a);
    vec_print_data(a);

    a.insert_pos(3, 1);
    vec_print_sc(a);
    vec_print_data(a);
    a.remove_pos(3);
    vec_print_sc(a);
    vec_print_data(a);

    //printfln("---------------------");

    //-----------
    //do {} while(GetAsyncKeyState(VK_ESCAPE)==0);
    constexpr int ESCAPE = 27; int k = 0; do { k = _getch(); } while (k != ESCAPE);
    //_getch();
    //getch();
    return 0;
}

