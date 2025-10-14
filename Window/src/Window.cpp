#include "Window.hpp"
#include "../include/OpenGLContext.hpp"
#include "PropertyPanel.hpp"
#include "UIContext.hpp"
#include <GLFW/glfw3.h>
#include <iostream>

struct WindowPrivate {
  bool mIsRunning;
  GLFWwindow *mWindow;
  std::unique_ptr<UIContext> mUIContext;
  std::unique_ptr<OpenGLContext> mOpenGLContext;
  std::unique_ptr<PropertyPanel> mPropertyPanel;
};

Window::Window() {
  mPrivate = std::make_unique<WindowPrivate>();
  mPrivate->mIsRunning = true;
  mPrivate->mWindow = nullptr;
  mPrivate->mUIContext = std::make_unique<UIContext>();
  mPrivate->mOpenGLContext = std::make_unique<OpenGLContext>();
}

Window::~Window() {
  mPrivate->mUIContext->end();
  mPrivate->mOpenGLContext->end();
}

bool Window::init(int width, int height, const std::string &title) {
  mWidth = width;
  mHeight = height;
  mTitle = title;

  mPrivate->mOpenGLContext->init(this);
  mPrivate->mUIContext->init(this);
  mPrivate->mPropertyPanel = std::make_unique<PropertyPanel>(mPrivate->mUIContext->GetContext());

  return mPrivate->mIsRunning;
}

void Window::render() {
  mPrivate->mOpenGLContext->preRender();
  mPrivate->mUIContext->preRender();
  void* ptr = mPrivate->mUIContext->GetContext();
  mPrivate->mPropertyPanel->render();

  mPrivate->mUIContext->postRender();
  mPrivate->mOpenGLContext->postRender();

  handleInput();
}

void Window::handleInput() {
  double x, y;
  glfwGetCursorPos(mPrivate->mWindow, &x, &y);
}

bool Window::isRunning() { return mPrivate->mIsRunning; }

void *Window::getNativeWindow() { return mPrivate->mWindow; }

void Window::setNativeWindow(void *window) {
  mPrivate->mWindow = reinterpret_cast<GLFWwindow *>(window);
}

void Window::onResize(int width, int height) {
  mWidth = width;
  mHeight = height;

  render();
}

void Window::close() { mPrivate->mIsRunning = false; }
