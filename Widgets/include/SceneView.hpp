#ifndef SCENE_VIEW_H
#define SCENE_VIEW_H
#include <cstdint>
#include <glm/vec2.hpp>
#include <memory>
#include <string>
#include "WidgetsExport.h"

class Light;
class Shader;
class OpenGLFrameBuffer;
class Mesh;
class Camera;
class WIDGETS_API SceneView {
public:
  SceneView();
  ~SceneView();

  Light *getLight() const;

  void resize(uint32_t width, uint32_t height);
  void render();
  void loadMesh(const std::string &filepath);
  void setMesh(std::shared_ptr<Mesh> mesh);
  std::shared_ptr<Mesh> getMesh();
  void resetView();

private:
  std::unique_ptr<Camera> mCamera;
  std::unique_ptr<OpenGLFrameBuffer> mFrameBuffer;
  std::unique_ptr<Shader> mShader;
  std::unique_ptr<Light> mLight;
  std::shared_ptr<Mesh> mMesh;
  glm::vec2 mSize;
};
#endif