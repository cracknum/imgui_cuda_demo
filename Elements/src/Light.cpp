#include "Light.hpp"

Light::Light() {
  mColor = glm::vec3(1.0f, 1.0f, 1.0f);
  mPosition = {1.5f, 3.5f, 3.0f};
  mStrength = 100.0f;
}
void Light::update(Shader *shader)  {
  shader->setVector3(mPosition, "lightPosition");
  shader->setVector3(mColor * mStrength, "lightColor");
}
