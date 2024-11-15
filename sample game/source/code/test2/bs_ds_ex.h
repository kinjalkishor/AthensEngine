#pragma once

#if 0
//sdf::span(vertices_vec.data(), vertices_vec.size())
//make_span(vertices_vec)
template<class T>
inline sdf::span<T> make_span(std::pmr::vector<T>& v) {
	return sdf::span<T>(v.data(), v.size());
}
template<class T>
inline sdf::basic_string_view<T> make_sv(std::pmr::basic_string<T>& v) {
	return sdf::basic_string_view<T>(v.data(), v.size());
}
#endif