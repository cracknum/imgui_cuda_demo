#ifndef SHADER_H
#define SHADER_H
#include <string>
#include <glm/glm.hpp>
#include <glad/glad.h>

class Shader
{
public:
    Shader() = default;

    bool load(const std::string &vertexShaderFile, const std::string &fragmentShaderFile);

    void use();
    void unload();

    unsigned int getProgramId() const;

    void setMat4(const glm::mat4 &mat4, const std::string &name);
    void setInteger1(int v, const std::string &name);
    void setFloat1(float v, const std::string &name);
    void setFloat3(float a, float b, float c, const std::string &name);
    void setVector3(const glm::vec3 &vec3, const std::string &name);
    void setVector4(const glm::vec4 &vec4, const std::string &name);

private:
    unsigned int getCompiledShader(unsigned int shaderType, const std::string &shaderSource);

private:
    GLuint mProgramId;
};
#endif