//
// Created by 87068 on 25-9-29.
//

#ifndef CAMERA_H
#define CAMERA_H
#include "Element.hpp"
#include <glm/detail/type_quat.hpp>
#include <glm/glm.hpp>
#include "ElementsExport.h"

class ELEMENTS_API Camera : public Element{

public:
  Camera(const glm::vec3& position, float fov, float aspect, float near, float far);
  void update(Shader* shader) override;

  void setAspect(float aspect);
  void setDistance(float offset);
  [[nodiscard]] const glm::mat4& getProjection() const;
  [[nodiscard]] glm::mat4 getViewProjection() const;
  [[nodiscard]] glm::vec3 getUp() const;
  [[nodiscard]] glm::vec3 getRight() const;
  [[nodiscard]] glm::vec3 getForward() const;
  [[nodiscard]] glm::quat getDirection() const;
  [[nodiscard]] glm::mat4 getViewMatrix() const;

  void reset();
  void updateViewMatrix();

private:
  glm::mat4 mViewMatrix{};
  glm::mat4 mProjection = glm::mat4{1.0f};
  glm::vec3 mPosition{0.0f, 0.0f, 0.0f};
  glm::vec3 mFocus{0.0f, 0.0f, 0.0f};
  float mDistance{5.0f};
  float mAspect{};
  float mFOV{};
  float mNear{};
  float mFar{};
  float mPitch{0.0f};
  float mYaw{0.0f};
  glm::vec2 mCurrentPos2d{0.0f, 0.0f};
  glm::vec3 mRight{1.0f, 0.0f, 0.0f};
  glm::vec3 mUp{0.0f, 1.0f, 0.0f};
  glm::vec3 mForward{0.0f, 0.0f, -1.0f};
  float mRotationSpeed{2.0f};
};



#endif //CAMERA_H
