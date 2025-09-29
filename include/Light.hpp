#ifndef LIGHT_H
#define LIGHT_H
#include <glm/glm.hpp>

class Light
{
    public:
    Light()
    {
        mColor = glm::vec3(1.0f, 1.0f, 1.0f);
        mPosition = {1.5f, 3.5f, 3.0f};
        mStrength = 100.0f;
    }
    glm::vec3 mPosition;
    glm::vec3 mColor;

    float mStrength;
};
#endif