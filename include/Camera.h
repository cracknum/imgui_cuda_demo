//
// Created by 87068 on 25-9-29.
//

#ifndef CAMERA_H
#define CAMERA_H
#include "Element.hpp"
#include <glm/glm.hpp>

class Camera : public Element{

public:
  Camera(const glm::vec3& position, float fov, float aspect, float near, float far)
  virtual void update(Shader* shader) override;

  void setAspect(float aspect);
  void setDistance(float offset);
  [[nodiscard]] const glm::mat4& getProjection() const;
  [[nodiscard]] glm::mat4 getViewProjection() const;
  [[nodiscard]] glm::vec3 getUp() const;
  glm::vec3 getRight() const;
  glm::vec3 getForward() const;
  glm::vec3 getDirection() const;
  glm::vec3 getViewMatrix() const;

  void reset();
  void updateViewMatrix();

private:
  glm::mat4 mViewMatrix;
  glm::mat4 mProjection;
  glm::vec3 mPosition;
  glm::vec3 mFocus;
  float mDistance;
  float mAspect;
  float mFOV;
  float mNear;
  float mFar;
  float mPitch;
  float mYaw;
  glm::vec2 mCurrentPos2d;
  glm::vec3 mRight;
  glm::vec3 mUp;
  glm::vec3 mForward;
  float mRotationSpeed;
};



#endif //CAMERA_H
