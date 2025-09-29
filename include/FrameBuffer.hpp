#ifndef FRAME_BUFFER_H
#define FRAME_BUFFER_H
#include <stdint.h>
class FrameBuffer
{
public:
    virtual void createBuffers(int32_t width, int32_t height) = 0;
    virtual void deleteBuffers() = 0;
    virtual void bind() = 0;
    virtual void unbind() = 0;
    virtual uint32_t getTexture() = 0;

protected:
    uint32_t mFBO = 0;
    uint32_t mTexId = 0;
    uint32_t mDepthId = 0;
    int32_t mWidth = 0;
    int32_t mHeight = 0;
};

#endif