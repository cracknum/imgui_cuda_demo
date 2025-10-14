#ifndef PROPERTY_PANEL_H
#define PROPERTY_PANEL_H
#include <memory>
#include <string>
#include "WidgetsExport.h"

namespace std
{
    template <class _Fty>
    class function;
}

class SceneView;

struct ImGuiContext;

class WIDGETS_API PropertyPanel
{
public:
    PropertyPanel(ImGuiContext* context);
    ~PropertyPanel();

    void render(SceneView *mScene = nullptr);
    void setMeshLoadCallback(const std::function<void(const std::string &)> &callback);

    PropertyPanel(const PropertyPanel &) = delete;
    PropertyPanel &operator=(const PropertyPanel &) = delete;

    PropertyPanel(PropertyPanel &&);
    PropertyPanel &operator=(PropertyPanel &&);

private:
    struct Impl;
    std::unique_ptr<Impl> mImpl;
};

#endif