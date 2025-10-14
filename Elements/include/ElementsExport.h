//
// Created by 87068 on 25-10-13.
//

#ifndef ELEMENTS_EXPORT_H
#define ELEMENTS_EXPORT_H

#ifdef _WIN32
    #ifdef ELEMENTS_EXPORTS
        #define ELEMENTS_API __declspec(dllexport)
    #else
        #define ELEMENTS_API __declspec(dllimport)
    #endif
#else
    #define MYLIB_API __attribute__((visibility("default")))
#endif

#endif // ELEMENTS_EXPORT_H
