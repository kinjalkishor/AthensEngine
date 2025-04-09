#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <stdint.h>

//-------------------
#include <thread>
#include <chrono>
void sys_sleep(uint32_t dwMilliseconds) {
	//Sleep(dwMilliseconds);
	std::this_thread::sleep_for(std::chrono::milliseconds(dwMilliseconds));	
}
