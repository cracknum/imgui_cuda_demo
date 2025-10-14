//
// Created by 87068 on 25-10-13.
//

#ifndef RENDER_EXPORT_H
#define RENDER_EXPORT_H

#ifdef _WIN32
    #ifdef RENDER_EXPORTS
        #define RENDER_API __declspec(dllexport)
    #else
        #define RENDER_API __declspec(dllimport)
    #endif
#else
    #define MYLIB_API __attribute__((visibility("default")))
#endif

#endif // ELEMENTS_EXPORT_H
