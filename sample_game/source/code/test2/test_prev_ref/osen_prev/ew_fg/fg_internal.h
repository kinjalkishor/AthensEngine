#pragma once

using GLboolean = bool;
using GLint = int;
using GLuint = unsigned int;

#if 0
/* A helper structure holding two ints and a boolean */
struct SFG_XYUse {
    GLint           X, Y;               /* The two integers...               */
    GLboolean       Use;                /* ...and a single boolean.          */
};

/* This structure holds different freeglut settings */
struct SFG_State {
    SFG_XYUse        Position;             /* The default windows' position  */
    SFG_XYUse        Size;                 /* The default windows' size      */
    unsigned int     DisplayMode;          /* Display mode for new windows   */

    GLboolean        Initialised;          /* freeglut has been initialised  */

    int              DirectContext;        /* Direct rendering state         */

    GLboolean        ForceIconic;          /* New top windows are iconified  */
    GLboolean        UseCurrentContext;    /* New windows share with current */

    GLboolean        GLDebugSwitch;        /* OpenGL state debugging switch  */
    GLboolean        XSyncSwitch;          /* X11 sync protocol switch       */

    int              KeyRepeat;            /* Global key repeat mode.        */
    int              Modifiers;            /* Current ALT/SHIFT/CTRL state   */

    GLuint           FPSInterval;          /* Interval between FPS printfs   */
    GLuint           SwapCount;            /* Count of glutSwapBuffer calls  */
    GLuint           SwapTime;             /* Time of last SwapBuffers       */

    fg_time_t        Time;                 /* Time that glutInit was called  */
    SFG_List         Timers;               /* The freeglut timer hooks       */
    SFG_List         FreeTimers;           /* The unused timer hooks         */

    FGCBIdleUC       IdleCallback;         /* The global idle callback       */
    FGCBUserData     IdleCallbackData;     /* The global idle callback data  */

    int              ActiveMenus;          /* Num. of currently active menus */
    FGCBMenuState    MenuStateCallback;    /* Menu callbacks are global      */
    FGCBMenuStatusUC MenuStatusCallback;
    FGCBUserData     MenuStatusCallbackData;
    void*            MenuFont;             /* Font to be used for newly created menus */

    SFG_XYUse        GameModeSize;         /* Game mode screen's dimensions  */
    int              GameModeDepth;        /* The pixel depth for game mode  */
    int              GameModeRefresh;      /* The refresh rate for game mode */

    int              ActionOnWindowClose;  /* Action when user closes window  */

    fgExecutionState ExecState;            /* Used for GLUT termination       */
    char            *ProgramName;          /* Name of the invoking program    */
    GLboolean        JoysticksInitialised; /* Only initialize if application calls for them */
    int              NumActiveJoysticks;   /* Number of active joysticks (callback defined and positive pollrate) -- if zero, don't poll joysticks */
    GLboolean        InputDevsInitialised; /* Only initialize if application calls for them */

    int              MouseWheelTicks;      /* Number of ticks the mouse wheel has turned */

    int              AuxiliaryBufferNumber;/* Number of auxiliary buffers */
    int              SampleNumber;         /*  Number of samples per pixel  */

    GLboolean        SkipStaleMotion;      /* skip stale motion events */

    GLboolean        StrokeFontDrawJoinDots;/* Draw dots between line segments of stroke fonts? */
    GLboolean        AllowNegativeWindowPosition; /* GLUT, by default, doesn't allow negative window positions. Enable it? */

    int              MajorVersion;         /* Major OpenGL context version  */
    int              MinorVersion;         /* Minor OpenGL context version  */
    int              ContextFlags;         /* OpenGL context flags          */
    int              ContextProfile;       /* OpenGL context profile        */
    int              HasOpenGL20;          /* fgInitGL2 could find all OpenGL 2.0 functions */
    FGErrorUC        ErrorFunc;            /* User defined error handler    */
    FGCBUserData     ErrorFuncData;        /* User defined error handler user data */
    FGWarningUC      WarningFunc;          /* User defined warning handler  */
    FGCBUserData     WarningFuncData;      /* User defined warning handler user data */
};

#endif