#include "SceneView.hpp"

inline SceneView::SceneView() {}
inline SceneView::~SceneView() {}
inline Light *SceneView::getLight() {}
inline void SceneView::resize(uint32_t width, uint32_t height) {}
inline void SceneView::render() {}
inline void SceneView::loadMesh(const std::string &filepath) {}
inline void SceneView::setMesh(std::shared_ptr<Mesh> mesh) {}
inline std::shared_ptr<Mesh> SceneView::getMesh() {}
inline void SceneView::resetView() {}