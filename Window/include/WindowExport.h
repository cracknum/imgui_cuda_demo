//
// Created by 87068 on 25-10-13.
//

#ifndef WINDOW_EXPORT_H
#define WINDOW_EXPORT_H

#ifdef _WIN32
    #ifdef WINDOW_EXPORTS
        #define WINDOW_API __declspec(dllexport)
    #else
        #define WINDOW_API __declspec(dllimport)
    #endif
#else
    #define MYLIB_API __attribute__((visibility("default")))
#endif

#endif // ELEMENTS_EXPORT_H
