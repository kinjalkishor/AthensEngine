#pragma once

using GLFWbool = bool;
//typedef int GLFWbool;

// Library global data
//
struct _GLFWlibrary {
    bool initialized = false;

#if 0
    struct {
        _GLFWinitconfig init;
        _GLFWfbconfig   framebuffer;
        _GLFWwndconfig  window;
        _GLFWctxconfig  context;
        int             refreshRate;
    } hints;

    _GLFWerror*         errorListHead;
    _GLFWcursor*        cursorListHead;
    _GLFWwindow*        windowListHead;

    _GLFWmonitor**      monitors;
    int                 monitorCount;

    _GLFWjoystick       joysticks[GLFW_JOYSTICK_LAST + 1];
    _GLFWmapping*       mappings;
    int                 mappingCount;

    _GLFWtls            errorSlot;
    _GLFWtls            contextSlot;
    _GLFWmutex          errorLock;

    struct {
        uint64_t        offset;
        // This is defined in the platform's time.h
        _GLFW_PLATFORM_LIBRARY_TIMER_STATE;
    } timer;

    struct {
        GLFWbool        available;
        void*           handle;
        char*           extensions[2];
#if !defined(_GLFW_VULKAN_STATIC)
        PFN_vkEnumerateInstanceExtensionProperties EnumerateInstanceExtensionProperties;
        PFN_vkGetInstanceProcAddr GetInstanceProcAddr;
#endif
        GLFWbool        KHR_surface;
#if defined(_GLFW_WIN32)
        GLFWbool        KHR_win32_surface;
#elif defined(_GLFW_COCOA)
        GLFWbool        MVK_macos_surface;
        GLFWbool        EXT_metal_surface;
#elif defined(_GLFW_X11)
        GLFWbool        KHR_xlib_surface;
        GLFWbool        KHR_xcb_surface;
#elif defined(_GLFW_WAYLAND)
        GLFWbool        KHR_wayland_surface;
#endif
    } vk;

    struct {
        GLFWmonitorfun  monitor;
        GLFWjoystickfun joystick;
    } callbacks;

    // This is defined in the window API's platform.h
    _GLFW_PLATFORM_LIBRARY_WINDOW_STATE;
    // This is defined in the context API's context.h
    _GLFW_PLATFORM_LIBRARY_CONTEXT_STATE;
    // This is defined in the platform's joystick.h
    _GLFW_PLATFORM_LIBRARY_JOYSTICK_STATE;
    // This is defined in egl_context.h
    _GLFW_EGL_LIBRARY_CONTEXT_STATE;
    // This is defined in osmesa_context.h
    _GLFW_OSMESA_LIBRARY_CONTEXT_STATE;
#endif
};

// Global state shared between compilation units of GLFW
//
extern _GLFWlibrary _glfw;




//typedef struct _GLFWerror       _GLFWerror;
//typedef struct _GLFWinitconfig  _GLFWinitconfig;
//typedef struct _GLFWwndconfig   _GLFWwndconfig;
//typedef struct _GLFWctxconfig   _GLFWctxconfig;
//typedef struct _GLFWfbconfig    _GLFWfbconfig;
//typedef struct _GLFWcontext     _GLFWcontext;
//typedef struct _GLFWwindow      _GLFWwindow;
//typedef struct _GLFWlibrary     _GLFWlibrary;
//typedef struct _GLFWmonitor     _GLFWmonitor;
//typedef struct _GLFWcursor      _GLFWcursor;
//typedef struct _GLFWmapelement  _GLFWmapelement;
//typedef struct _GLFWmapping     _GLFWmapping;
//typedef struct _GLFWjoystick    _GLFWjoystick;
//typedef struct _GLFWtls         _GLFWtls;
//typedef struct _GLFWmutex       _GLFWmutex;

#if 0


// Window and context structure
//
struct _GLFWwindow
{
    struct _GLFWwindow* next;

    // Window settings and state
    GLFWbool            resizable;
    GLFWbool            decorated;
    GLFWbool            autoIconify;
    GLFWbool            floating;
    GLFWbool            focusOnShow;
    GLFWbool            shouldClose;
    void*               userPointer;
    GLFWbool            doublebuffer;
    GLFWvidmode         videoMode;
    _GLFWmonitor*       monitor;
    _GLFWcursor*        cursor;

    int                 minwidth, minheight;
    int                 maxwidth, maxheight;
    int                 numer, denom;

    GLFWbool            stickyKeys;
    GLFWbool            stickyMouseButtons;
    GLFWbool            lockKeyMods;
    int                 cursorMode;
    char                mouseButtons[GLFW_MOUSE_BUTTON_LAST + 1];
    char                keys[GLFW_KEY_LAST + 1];
    // Virtual cursor position when cursor is disabled
    double              virtualCursorPosX, virtualCursorPosY;
    GLFWbool            rawMouseMotion;

    _GLFWcontext        context;

    struct {
        GLFWwindowposfun          pos;
        GLFWwindowsizefun         size;
        GLFWwindowclosefun        close;
        GLFWwindowrefreshfun      refresh;
        GLFWwindowfocusfun        focus;
        GLFWwindowiconifyfun      iconify;
        GLFWwindowmaximizefun     maximize;
        GLFWframebuffersizefun    fbsize;
        GLFWwindowcontentscalefun scale;
        GLFWmousebuttonfun        mouseButton;
        GLFWcursorposfun          cursorPos;
        GLFWcursorenterfun        cursorEnter;
        GLFWscrollfun             scroll;
        GLFWkeyfun                key;
        GLFWcharfun               character;
        GLFWcharmodsfun           charmods;
        GLFWdropfun               drop;
    } callbacks;

    // This is defined in the window API's platform.h
    _GLFW_PLATFORM_WINDOW_STATE;
};









#endif