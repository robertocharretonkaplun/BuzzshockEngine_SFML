#include "SceneGraph.h"
#include "Transform.h"
namespace buEngineSDK {
  void 
  SceneGraph::init() {
  }

  void 
  SceneGraph::update() {
  }

  void 
  SceneGraph::render() {
  }

  void 
  SceneGraph::destroy() {
  }
  
  void 
  SceneGraph::ui() {
    basicsUI();
    worldOutlinerUI();
    propertiesUI();
    ImGui::Begin("Scene Graph");

    ImGui::End();
  }

  void 
  SceneGraph::basicsUI() {
    ImGui::Begin("Basics");
    ImVec2 btnSize = { 250, 50 };
    if (ImGui::Button("Custom Actor", btnSize)) {
    }
    if (ImGui::Button("Empty Actor", btnSize)) {
      Node * pNode;
      pNode = new Node;
      Node newNode;
      newNode.setChild(pNode);
      string nodeName = newNode.getName();
      newNode.setName(nodeName);

      // Set the actor
      Actor pActor;
      string actorName = pActor.getName();
      pActor.setName(actorName);
      pActor.init();
      newNode.setActor(pActor);

      // Add transform component
      Transform* pTransform =  new Transform;
      pTransform->init();
      newNode.getActor().addComponent(pTransform);

      m_nodes.push_back(newNode);
    }
    if (ImGui::Button("Circle Actor", btnSize)) {
    }
    if (ImGui::Button("Rectangle Actor", btnSize)) {
    }
    ImGui::End();
  }
  
  void 
  SceneGraph::worldOutlinerUI() {
    ImGui::Begin("World Outliner");
    ImGui::End();
  }
  
  void 
  SceneGraph::propertiesUI() {
    ImGui::Begin("Properties");
    //auto& actor;
    
    if (m_nodes.size() > 0) {
      auto& node = m_nodes[m_currnode];
      //actor = node.getActor();

      bool canrender;
      ImGui::Checkbox("|", &canrender);
      ImGui::SameLine();
      static char str1[128] = "";
      ImGui::SameLine();
      ImGui::InputText(" ", str1, IM_ARRAYSIZE(str1));
      ImGui::Separator();
      node.getActor().ui();
      ImGui::Separator();
      const char* items[] = { "Transform", "Material", "Rigidbody", "Model", "Light" };
      static const char* current_item = NULL;

      if (ImGui::BeginCombo("##combo", current_item)) {
        for (int n = 0; n < IM_ARRAYSIZE(items); n++) {

          bool is_selected = (current_item == items[n]); // You can store your selection however you want, outside or inside your objects
          if (ImGui::Selectable(items[n], is_selected)) {
            current_item = items[n];

            if (n == 0) {
              m_tempComponentType = n;
            }
            if (n == 1) {
              m_tempComponentType = n;
            }
            if (n == 2) {
              m_tempComponentType = n;
            }
            if (n == 3) {
              m_tempComponentType = n;
            }
            if (n == 4) {
              m_tempComponentType = n;
            }
          }
          if (is_selected)
            ImGui::SetItemDefaultFocus();   // You may set the initial focus when opening the combo (scrolling + for keyboard navigation support)
        }
        ImGui::EndCombo();
      }
      if (ImGui::Button("Add Component", ImVec2(330, 20))) {
          node.getActor().addComponent((buEngineSDK::ComponentType::E) m_tempComponentType);
      }
    }


    ImGui::End();
  }
}