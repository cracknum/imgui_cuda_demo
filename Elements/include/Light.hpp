#ifndef LIGHT_H
#define LIGHT_H
#include "Element.hpp"
#include "ElementsExport.h"
#include "Shader.hpp"

class ELEMENTS_API Light : public Element {
public:
  Light();
  glm::vec3 mPosition{};
  glm::vec3 mColor{};

  float mStrength;

  void update(Shader *shader) override;
};
#endif