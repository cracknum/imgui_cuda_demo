#ifndef VERTEX_INDEX_BUFFER_H
#define VERTEX_INDEX_BUFFER_H

#include "RenderExport.h"
#include "VertexHolder.hpp"
#include <glad/glad.h>
#include <vector>

class RENDER_API VertexIndexBuffer
{
    public:
    VertexIndexBuffer():
    mVAO(0), mVBO(0), mIBO(0){}
    virtual ~VertexIndexBuffer() = default;

    virtual void createBuffers(const std::vector<VertexHolder>& vertices, const std::vector<unsigned int>& indices) = 0;
    virtual void deleteBuffers() = 0;
    virtual void bind() = 0;
    virtual void unbind() = 0;
    virtual void draw(int indexCount) = 0;
    protected:
    GLuint mVBO;
    GLuint mVAO;
    GLuint mIBO;
};

#endif