#pragma once

#include "../base_gmath.h"
#include "irr_math.h"

namespace gm
{

//As of Irrlicht 1.6, this class supercedes position2d, which should be considered deprecated.
//template <class T>
//class vector2d {
//public:
//	//! Default constructor (null vector)
//	vector2d() : X(0), Y(0) {}
//	explicit vector2d(T n) : X(n), Y(n) {}
//	vector2d(const vector2d<T>& other) : X(other.X), Y(other.Y) {}
//	vector2d(const dimension2d<T>& other) : X(other.Width), Y(other.Height) {}
//};

//vector2d<T>& operator=(const vector2d<T>& other) { X = other.X; Y = other.Y; return *this; }
//vector2d<T>& operator=(const dimension2d<T>& other) { X = other.Width; Y = other.Height; return *this; }

////! sort in order x, y. Equality with rounding tolerance.
//bool operator<=(const vec2& a, const vec2& other) {
//	return 	(a.x<other.x || mf::equals_irr(a.x, other.x)) ||
//			(mf::equals_irr(a.x, other.x) && (a.y<other.y || mf::equals_irr(a.y, other.y)));
//}
////! sort in order x, y. Equality with rounding tolerance.
//bool operator>=(const vec2& a, const vec2& other) {
//	return 	(a.x>other.x || mf::equals_irr(a.x, other.x)) ||
//			(mf::equals_irr(a.x, other.x) && (a.y>other.y || mf::equals_irr(a.y, other.y)));
//}
////! sort in order x, y. Difference must be above rounding tolerance.
//bool operator<(const vec2& a, const vec2& other) {
//	return 	(a.x<other.x && !mf::equals_irr(a.x, other.x)) ||
//			(mf::equals_irr(a.x, other.x) && a.y<other.y && !mf::equals_irr(a.y, other.y));
//}
////! sort in order x, y. Difference must be above rounding tolerance.
//bool operator>(const vec2& a, const vec2& other) {
//	return 	(a.x>other.x && !mf::equals_irr(a.x, other.x)) ||
//			(mf::equals_irr(a.x, other.x) && a.y>other.y && !mf::equals_irr(a.y, other.y));
//}

//vector2d<T>& set(T nx, T ny) {X=nx; Y=ny; return *this; }
//vector2d<T>& set(const vector2d<T>& p) { X=p.X; Y=p.Y; return *this; }







}