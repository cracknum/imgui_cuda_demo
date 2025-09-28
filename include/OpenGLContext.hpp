#ifndef OPENGL_CONTEXT_H
#define OPENGL_CONTEXT_H
#include "RenderContext.hpp"

class IWindow;

class OpenGLContext : public RenderContext
{
public:
    using superclass = RenderContext;
    bool init(IWindow *window) override;

    void preRender() override;

    void postRender() override;

    void end() override;
};
#endif // OPENGL_CONTEXT_H