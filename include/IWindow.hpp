#ifndef INTERFACE_WINDOW_H
#define INTERFACE_WINDOW_H
#include <string>

class IWindow
{
    public:
    virtual void* getNativeWindow() = 0;
    virtual void setNativeWindow(void* window) = 0;
    virtual void onResize(int width, int height) = 0;
    virtual void close() = 0;

    unsigned int mWidth;
    unsigned int mHeight;
    std::string mTitle;
};
#endif // INTERFACE_WINDOW_H