#include "OpenGLVertexIndexBuffer.hpp"
#include <glad/glad.h>
void OpenGLVertexIndexBuffer::createBuffers(const std::vector<VertexHolder> &vertices, const std::vector<unsigned int> &indices)
{
    glGenVertexArrays(1, &mVAO);
    glBindVertexArray(mVAO);
    glGenBuffers(1, &mVBO);
    glGenBuffers(1, &mIBO);

    glBindBuffer(GL_ARRAY_BUFFER, mVBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIBO);

    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(VertexHolder), vertices.data(), GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexHolder), static_cast<void*>(0));
    
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(VertexHolder), (void*)offsetof(VertexHolder, mNormal));

    glBindVertexArray(0);
}

void OpenGLVertexIndexBuffer::deleteBuffers()
{
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glDeleteBuffers(1, &mVBO);
    glDeleteBuffers(1, &mIBO);
    glDeleteVertexArrays(1, &mVAO);
}

void OpenGLVertexIndexBuffer::bind()
{
    glBindVertexArray(mVAO);
}

void OpenGLVertexIndexBuffer::unbind()
{
    glBindVertexArray(0);
}

void OpenGLVertexIndexBuffer::draw(int indexCount)
{
    bind();
    glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, nullptr);
    unbind();
}
