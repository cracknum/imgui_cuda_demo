#ifndef OPENGL_FRAME_BUFFER_H
#define OPENGL_FRAME_BUFFER_H
#include "FrameBuffer.hpp"
#include "RenderExport.h"

class RENDER_API OpenGLFrameBuffer: public FrameBuffer
{
    public:
    virtual void createBuffers(int32_t width, int32_t height) override;
    virtual void deleteBuffers() override;
    virtual void bind() override;
    virtual void unbind() override;
    virtual uint32_t getTexture() override;
};
#endif