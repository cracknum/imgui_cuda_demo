#ifndef OPENGL_IMGUI_APPLICATION
#define OPENGL_IMGUI_APPLICATION
#include <memory>
#include "CoreExport.h"

struct ApplicationPrivate;

class CORE_API Application
{
public:
    Application(int argc, char **argv);
    ~Application();

    void loop();

private:
    std::unique_ptr<ApplicationPrivate> mPrivate;
};

#endif // OPENGL_IMGUI_APPLICATION