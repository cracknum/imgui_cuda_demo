#ifndef OPENGL_VERTEX_INDEX_BUFFER_H
#define OPENGL_VERTEX_INDEX_BUFFER_H
#include "VertexIndexBuffer.hpp"
class OpenGLVertexIndexBuffer: public VertexIndexBuffer
{
    public:
    OpenGLVertexIndexBuffer() = default;
    virtual void createBuffers(const std::vector<VertexHolder>& vertices, const std::vector<unsigned int>& indices) override;
    virtual void deleteBuffers() override;
    virtual void bind() override;
    virtual void unbind() override;
    virtual void draw(int indexCount) override;

};
#endif