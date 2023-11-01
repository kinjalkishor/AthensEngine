#include <thread>
#include <chrono>

#include "base_win_util.h"

void sys_sleep(uint dwMilliseconds) {
	//Sleep(dwMilliseconds);
	std::this_thread::sleep_for(std::chrono::milliseconds(dwMilliseconds));	
}