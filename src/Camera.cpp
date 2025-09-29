#include "Camera.h"

Camera::Camera(const glm::vec3 &position, float fov, float aspect, float near,
               float far) {}
void Camera::update(Shader *shader) {}
void Camera::setAspect(float aspect) {}
void Camera::setDistance(float offset) {}
const glm::mat4 &Camera::getProjection() const {}
glm::mat4 Camera::getViewProjection() const {}
glm::vec3 Camera::getUp() const {}
glm::vec3 Camera::getRight() const {}
glm::vec3 Camera::getForward() const {}
glm::vec3 Camera::getDirection() const {}
glm::vec3 Camera::getViewMatrix() const {}
void Camera::reset() {}
void Camera::updateViewMatrix() {}