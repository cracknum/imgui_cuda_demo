#include "Shader.hpp"
#include <fstream>
#include <iosfwd>

#include <glm/gtc/type_ptr.hpp>

bool Shader::load(const std::string &vertexShaderFile, const std::string &fragmentShaderFile)
{
    std::ifstream instreamVertex(vertexShaderFile);
    const std::string vertexShader((std::istream_iterator<char>(instreamVertex)), std::istream_iterator<char>());
    std::ifstream instreamFragment(fragmentShaderFile);
    const std::string fragmentShader((std::istream_iterator<char>(instreamFragment)), std::istream_iterator<char>());

    mProgramId = glCreateProgram();

    unsigned int vertexShaderId = getCompiledShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fragmentShaderId = getCompiledShader(GL_FRAGMENT_SHADER, fragmentShader);

    glAttachShader(mProgramId, vertexShaderId);
    glAttachShader(mProgramId, fragmentShaderId);
    glLinkProgram(mProgramId);
    glValidateProgram(mProgramId);

    glDeleteShader(vertexShaderId);
    glDeleteShader(fragmentShaderId);

    return true;
}

void Shader::use() const
{
    glUseProgram(mProgramId);
}

void Shader::unload() const
{
    glDeleteProgram(mProgramId);
}

unsigned int Shader::getProgramId() const
{
    return mProgramId;
}

void Shader::setMat4(const glm::mat4 &mat4, const std::string &name) const
{
    GLuint location = glGetUniformLocation(getProgramId(), name.c_str());
    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(mat4));
}

void Shader::setInteger1(int v, const std::string &name) const
{
    GLuint location = glGetUniformLocation(getProgramId(), name.c_str());
    glUniform1i(location, v);
}

void Shader::setFloat1(float v, const std::string &name) const
{
    GLuint location = glGetUniformLocation(getProgramId(), name.c_str());
    glUniform1f(location, v);
}

void Shader::setFloat3(float a, float b, float c, const std::string &name) const
{
    GLuint location = glGetUniformLocation(getProgramId(), name.c_str());
    glUniform3f(location, a, b, c);
}

void Shader::setVector3(const glm::vec3 &vec3, const std::string &name) const
{
    GLuint location = glGetUniformLocation(getProgramId(), name.c_str());
    glUniform3fv(location, 1, glm::value_ptr(vec3));
}

void Shader::setVector4(const glm::vec4 &vec4, const std::string &name) const
{
    GLuint location = glGetUniformLocation(getProgramId(), name.c_str());
    glUniform4fv(location, 1, glm::value_ptr(vec4));
}

unsigned int Shader::getCompiledShader(unsigned int shaderType, const std::string &shaderSource)
{
    unsigned int shaderId = glCreateShader(shaderType);
    const char *shaderSourceStr = shaderSource.c_str();
    glShaderSource(shaderId, 1, &shaderSourceStr, nullptr);
    glCompileShader(shaderId);

    GLint result;
    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &result);

    if (result == GL_FALSE)
    {
        int length;
        glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &length);

        GLchar *strInfoLog = new GLchar[length + 1];
        glGetShaderInfoLog(shaderId, length, &length, strInfoLog);

        fprintf(stderr, "Compile error in shader: %s\n", strInfoLog);
        delete[] strInfoLog;
    }

    return shaderId;
}
