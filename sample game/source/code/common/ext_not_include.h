#pragma once

// Windows supports all the same escape codes as linux, you have to activate them tho:
//-https://learn.microsoft.com/en-us/windows/console/clearing-the-screen
stdout := win32.GetStdHandle(win32.STD_OUTPUT_HANDLE)
if stdout != win32.INVALID_HANDLE && stdout != nil {
    old_console_mode: u32
    if win32.GetConsoleMode(stdout, &old_console_mode) {
        win32.SetConsoleMode(stdout, old_console_mode | win32.ENABLE_VIRTUAL_TERMINAL_PROCESSING)
    }
}

// Sebastian Aaltonen Handle
// TODO: copy Span, Array and Array_static_vector also
template<typename T> class Handle {
public:
	Handle() : m_index(0), m_generation(0) {}
	bool isValid() const { return m_generation != 0; }
	
private:
	Handle(uint32 index, uint32 generation) : m_index(index), m_generation(generation) {}
	
	uint32 m_index;
	uint32 m_generation;
	
	template<typename U> friend class Pool;
}

