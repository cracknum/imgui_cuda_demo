#ifndef ELEMENT_H
#define ELEMENT_H
class Shader;

class Element
{
public:
virtual void update(Shader* shader) = 0;
virtual ~Element() = default;
};

#endif