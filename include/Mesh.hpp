#ifndef MESH_H
#define MESH_H
#include "Element.hpp"
#include <string>
#include <memory>
#include "VertexIndexBuffer.hpp"

class VertexHolder;


class Mesh : public Element
{
public:
    Mesh();
    virtual ~Mesh();
    bool load(const std::string& filepath);
    void addVertex(const VertexHolder& vertex);

    void addVertexIndex(unsigned int vertexIndex);
    std::vector<unsigned int> getVertexIndices();
    virtual void update(Shader* shader) override;
    void init();
    void createBuffers();
    void deleteBuffers();
    void render();
    void bind();
    void unbind();

    public:
    glm::vec3 mColor;
    float mRoughness;
    float mMetallic;
    private:
    std::unique_ptr<VertexIndexBuffer> mRenderBufferMgr;
    std::vector<VertexHolder> mVertices;
    std::vector<unsigned int> mVertexIndices;
}
#endif