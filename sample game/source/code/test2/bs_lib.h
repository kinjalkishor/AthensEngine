#pragma once


template<class T> inline void com_release(T*& t) { if(t) { t->Release(); t = nullptr; } }	

template<class T> inline void safe_delete(T*& t) { if(t) { delete t; t = nullptr; } }
template<class T> inline void safe_delete_arr(T*& t) { if(t) { delete[] t; t = nullptr; } }

namespace sdf
{

template<class T> inline T tmin(const T a, const T b) { return (a < b) ? a : b; }
template<class T> inline T tmax(const T a, const T b) { return (a > b) ? a : b; }

//returns x in [low, high]
template<class T>
inline T clamp(const T& x, const T& low, const T& high) {
    //return tmin(tmax(x, low), high); //irr
	//return tmax(tmin(x, high), low); //dx
    //return tmin(high, tmax(x, low));

    if (x < low) { return low; }
    if (x > high) { return high; }
    return x;       
}

}
