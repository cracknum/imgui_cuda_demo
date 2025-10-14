#ifndef VERTEX_HOLDER_H
#define VERTEX_HOLDER_H
#include "RenderExport.h"
#include <glm/glm.hpp>
#include <string>
#include <vector>
class RENDER_API VertexHolder
{
public:
    VertexHolder() : mPos(), mNormal() {}
    VertexHolder(const std::vector<std::string> tokens)
    {
    }

    VertexHolder(const glm::vec3 &pos, const glm::vec3 &normal)
        : mPos(pos), mNormal(normal)
    {
    }

    ~VertexHolder() = default;

    glm::vec3 mPos;
    glm::vec3 mNormal;
};

#endif
