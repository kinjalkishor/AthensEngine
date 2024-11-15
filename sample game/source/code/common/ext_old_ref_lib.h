#pragma once


//=============================================
//format
//=============================================
//template <typename... Args>
//void logWarn(fmt::format_string<Args...>&& fmt_str, Args&&... args)
//{
//    fmt::print(stderr, "warning: {}\n", fmt::format(
//        std::forward<fmt::format_string<Args...>>(fmt_str), std::forward<Args>(args)...));
//}
//
//template <typename... Args>
//void logInfo(fmt::format_string<Args...>&& fmt_str, Args&&... args)
//{
//    fmt::print("info: {}\n", fmt::format(
//        std::forward<fmt::format_string<Args...>>(fmt_str), std::forward<Args>(args)...));
//}