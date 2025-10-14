#ifndef UI_CONTEXT_H
#define UI_CONTEXT_H
#include "WindowExport.h"
#include "RenderContext.hpp"

struct ImGuiContext;

class WINDOW_API UIContext : public RenderContext
{
public:
    using superclass = RenderContext;
    virtual bool init(IWindow *window) override;
    ImGuiContext *UIContext::GetContext();
    virtual void preRender() override;
    virtual void postRender() override;
    virtual void end() override;
};
#endif // UI_CONTEXT_H