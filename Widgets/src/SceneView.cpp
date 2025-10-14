#include "SceneView.hpp"

#include "Camera.h"
#include "Light.hpp"
#include "Mesh.hpp"
#include "OpenGLFrameBuffer.hpp"
#include "Shader.hpp"

#include <imgui.h>

#include <utility>
SceneView::SceneView():   mCamera(nullptr), mFrameBuffer(nullptr), mShader(nullptr),
  mLight(nullptr), mSize(800, 600)
{
  mFrameBuffer = std::make_unique<OpenGLFrameBuffer>();
  mFrameBuffer->createBuffers(800, 600);
  mShader = std::make_unique<Shader>();
  mShader->load("shaders/vs.shader", "shaders/fs_pbr.shader");
  mLight = std::make_unique<Light>();

  mCamera = std::make_unique<Camera>(glm::vec3(0, 0, 3), 45.0f, 1.3f, 0.1f, 100.0f);

}
SceneView::~SceneView() {
mShader->unload();
}
Light *SceneView::getLight() const {
  return mLight.get();
}
void SceneView::resize(uint32_t width, uint32_t height) {
  mSize.x = width;
  mSize.y = height;
}
void SceneView::render() {
  mShader->use();
  mLight->update(mShader.get());
  mFrameBuffer->bind();

  if (mMesh) {
    mMesh->update(mShader.get());
    mMesh->render();
  }

  mFrameBuffer->unbind();
  ImGui::Begin("Scene");
  ImVec2 viewportPanelSize = ImGui::GetContentRegionAvail();
  mSize = {viewportPanelSize.x, viewportPanelSize.y};
  mCamera->setAspect(mSize.x / mSize.y);
  mCamera->update(mShader.get());

  uint64_t textureID = mFrameBuffer->getTexture();
  ImGui::Image(static_cast<ImTextureID>(textureID), ImVec2(mSize.x, mSize.y), ImVec2{ 0, 1 }, ImVec2{ 1, 0 });
  ImGui::End();
}
void SceneView::loadMesh(const std::string &filepath) {
  if (!mMesh) {
    mMesh = std::make_shared<Mesh>();
  }
  mMesh->load(filepath);
}
void SceneView::setMesh(std::shared_ptr<Mesh> mesh) {
  mMesh = std::move(mesh);
}
std::shared_ptr<Mesh> SceneView::getMesh() {
  return mMesh;
}
void SceneView::resetView() {
  mCamera->reset();
}