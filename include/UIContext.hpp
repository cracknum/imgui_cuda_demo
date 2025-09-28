#ifndef UI_CONTEXT_H
#define UI_CONTEXT_H
#include "RenderContext.hpp"

class UIContext : public RenderContext
{
public:
    using superclass = RenderContext;
    virtual bool init(IWindow *window) override;

    virtual void preRender() override;
    virtual void postRender() override;
    virtual void end() override;
};
#endif // UI_CONTEXT_H