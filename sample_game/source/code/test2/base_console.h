#pragma once

#include "base_types.h"

class std_console {
private:
	//HANDLE hconsole = nullptr;
	void* hconsole = nullptr;	

public:
	std_console() {}
	~std_console();

	bool create_window(const char* window_title, int xpos, int ypos, int width, int height);	
};

