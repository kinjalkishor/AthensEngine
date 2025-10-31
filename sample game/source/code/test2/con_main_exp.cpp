#if _MSC_VER
#pragma comment(linker, "/subsystem:console")
#endif

#if defined(_MSC_VER)
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")
#endif

#include <conio.h>
#include <stdio.h>

class vec2 {
public:
    // float x, y;
    union {
        struct {
            float x, y;
        };
        float e[2];
    };

    vec2(float x, float y)
        : x(x)
        , y(y) { }
};

int main() {
    printf("Hello, World!\n");
    // printfln("---------------------");
    vec2 a = { 1, 2 };
    vec2 b = { 3, 4 };
    vec2 c = { a.x + b.x, a.y + b.y };
    printf("%f, %f\n", c.x, c.y);

    // printfln("---------------------");

    //-------------------------------------------------
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
