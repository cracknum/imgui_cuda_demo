#ifndef WINDOW_H
#define WINDOW_H
#include "WindowExport.h"
#include <string>
#include "IWindow.hpp"
#include <memory>

struct WindowPrivate;

class WINDOW_API Window : public IWindow
{
public:
    Window();
    ~Window();

    bool init(int width, int height, const std::string& title);
    void render();
    void handleInput();
    bool isRunning();


    virtual void *getNativeWindow() override;
    virtual void setNativeWindow(void *window) override;
    virtual void onResize(int width, int height) override;
    virtual void close() override;

private:
    std::unique_ptr<WindowPrivate> mPrivate;
};
#endif // WINDOW_H