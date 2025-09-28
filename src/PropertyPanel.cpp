#include "PropertyPanel.hpp"
#include <imgui.h>
#include <imfilebrowser.h>
#include <functional>

struct PropertyPanel::Impl final
{
    // create a file browser instance
    ImGui::FileBrowser mFileDialog;
    std::function<void(const std::string&)> mMeshLoadCallback;
    std::string mCurrentFile;
};

PropertyPanel::PropertyPanel()
{
    mImpl = std::make_unique<Impl>();
}

PropertyPanel::~PropertyPanel()
{
}

void PropertyPanel::render(SceneView *mScene)
{
    //auto mesh = scene_view->get_mesh();

    ImGui::Begin("Properties");
    if (ImGui::CollapsingHeader("Mesh", ImGuiTreeNodeFlags_DefaultOpen))
    {
      
      if (ImGui::Button("Open..."))
      {
        mImpl->mFileDialog.Open();
      }
      ImGui::SameLine(0, 5.0f);
      ImGui::Text(mImpl->mCurrentFile.c_str());
    }

    /*if (ImGui::CollapsingHeader("Material") && mesh)
    {
      ImGui::ColorPicker3("Color", (float*)&mesh->mColor, ImGuiColorEditFlags_PickerHueWheel | ImGuiColorEditFlags_DisplayRGB);
      ImGui::SliderFloat("Roughness", &mesh->mRoughness, 0.0f, 1.0f);
      ImGui::SliderFloat("Metallic", &mesh->mMetallic, 0.0f, 1.0f);
    }*/

    if (ImGui::CollapsingHeader("Light"))
    {

      ImGui::Separator();
      ImGui::Text("Position");
      ImGui::Separator();
      // nimgui::draw_vec3_widget("Position", scene_view->get_light()->mPosition, 80.0f);
    }

    ImGui::End();

    mImpl->mFileDialog.Display();
    if (mImpl->mFileDialog.HasSelected())
    {
      auto file_path = mImpl->mFileDialog.GetSelected().string();
      mImpl->mCurrentFile = file_path.substr(file_path.find_last_of("/\\") + 1);

      // mImpl->mMeshLoadCallback(file_path);

      mImpl->mFileDialog.ClearSelected();
    }
}

void PropertyPanel::setMeshLoadCallback(const std::function<void(const std::string &)> &callback)
{
      mImpl->mMeshLoadCallback = callback;
}

PropertyPanel::PropertyPanel(PropertyPanel &&) = default;

PropertyPanel &PropertyPanel::operator=(PropertyPanel &&) = default;
