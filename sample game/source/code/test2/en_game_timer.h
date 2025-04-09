#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <stdint.h>

class game_timer_qpc {
public:

	float period() {
		int64_t cnts_per_sec = 0;
		QueryPerformanceFrequency((LARGE_INTEGER*)&cnts_per_sec);
		// secs_per_cnt_qpc is 0.0000001f, 1e-07;
		float secs_per_cnt_qpc = 1.0f / static_cast<float>(cnts_per_sec);
		//println("{}", secs_per_cnt_qpc);
		return secs_per_cnt_qpc;
	}

	int64_t get_time() {
		// Retrieves the current value of the performance counter, 
		// which is a high resolution (<1 micro second) time stamp.
		int64_t prev_time_qpc = 0;
		QueryPerformanceCounter((LARGE_INTEGER*)&prev_time_qpc);
		return prev_time_qpc;
	}
};
