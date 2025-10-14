#include "Camera.h"

#include "Shader.hpp"

#include <glm/ext/matrix_clip_space.hpp>
#include <glm/gtx/quaternion.hpp>

Camera::Camera(const glm::vec3 &position, float fov, float aspect, float near,
               float far)
    : mPosition(position), mAspect(aspect), mFOV(fov), mNear(near), mFar(far) {
  setAspect(aspect);
  updateViewMatrix();
}
void Camera::update(Shader *shader) {
  constexpr glm::mat4 model{1.0f};
  shader->setMat4(model, "model");
  shader->setMat4(mViewMatrix, "view");
  shader->setMat4(getProjection(), "projection");
  shader->setVector3(mPosition, "camera");
}
void Camera::setAspect(float aspect) {
  mProjection = glm::perspective(mFOV, mAspect, mNear, mFar);
}
void Camera::setDistance(float offset) {
  mDistance += offset;
  updateViewMatrix();
}
const glm::mat4 &Camera::getProjection() const { return mProjection; }
glm::mat4 Camera::getViewProjection() const {
  return mProjection * getViewMatrix();
}
glm::vec3 Camera::getUp() const {
  return glm::rotate(getDirection(), mUp);
}
glm::vec3 Camera::getRight() const {
  return glm::rotate(getDirection(), mRight);
}
glm::vec3 Camera::getForward() const {
  return glm::rotate(getDirection(), mForward);
}
glm::quat Camera::getDirection() const {
  return glm::quat(glm::vec3(-mPitch, -mYaw, 0));
}
glm::mat4 Camera::getViewMatrix() const {

  return mViewMatrix;

}
void Camera::reset() {
  mFocus = {0.0f, 0.0f, 0.0f};
  updateViewMatrix();
}
void Camera::updateViewMatrix() {
  mPosition = mFocus - getForward() * mDistance;
  const glm::quat orientation = getDirection();
  mViewMatrix = glm::translate(glm::mat4(1.0f), mPosition) * glm::toMat4(orientation);
  mViewMatrix = glm::inverse(mViewMatrix);
}