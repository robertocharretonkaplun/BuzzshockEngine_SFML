#include "SceneGraph.h"
#include "Transform.h"
#include "CircleShape.h"
#include "RectangleShape.h"
#include "Animator.h"

namespace buEngineSDK {
  void 
  SceneGraph::init(float _w, float _h) {
    if (!m_scene.create(_w, _h))
    {
      // error...
    }
  }

  void 
  SceneGraph::update() {

    for (auto& node : m_nodes) {
      node.getActor().update();
    }
  }

  void 
  SceneGraph::render(sf::RenderWindow& _window) {
    m_scene.clear();
    for (auto& node : m_nodes) {
      node.getActor().render(m_scene);
    }
    m_scene.display();
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
    sf::Sprite sprite(m_scene.getTexture());
    ImGui::Image(sprite, sf::Vector2f(ImGui::GetWindowWidth(), ImGui::GetWindowHeight() ));

    ImGui::End();
  }

  void 
  SceneGraph::basicsUI() {
    ImGui::Begin("Basics");
    ImVec2 btnSize = { 250, 50 };
    // Button for debuggin purposes
    if (ImGui::Button("Custom Actor", btnSize)) {
    }
    if (ImGui::Button("Empty Actor", btnSize)) {
      createEmptyActor();
    }
    if (ImGui::Button("Circle Actor", btnSize)) {
      createCircleShapeActor();
    }
    if (ImGui::Button("Rectangle Actor", btnSize)) {
      createRectangleShapeActor();
    }
    ImGui::End();
  }
  
  void 
  SceneGraph::worldOutlinerUI() {
    ImGui::Begin("World Outliner");
    ImGui::SliderInt("Node", &m_currnode, 0, m_nodes.size() - 1);
    for (auto& node : m_nodes) {
      if (ImGui::TreeNode(node.getName().c_str())) {
        if (ImGui::TreeNode(node.getActor().getName().c_str())) {
          for (auto &components : node.getActor().getComponents()) {
            if (ImGui::TreeNode(components->getName().c_str())) {

              ImGui::TreePop();
            }
          }
          ImGui::TreePop();
        }
        ImGui::TreePop();
      }
    }
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
      ImGui::InputText(" ", node.getActor().getName().data(), IM_ARRAYSIZE(str1));
      ImGui::Separator();
      node.getActor().ui();
      ImGui::Separator();
      const char* items[] = { "Transform", "Texture", "Circle shape", "Rectanlge shape", "Line", "Animator" };
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
            if (n == 5) {
              m_tempComponentType = n;
            }
          }
          if (is_selected)
            ImGui::SetItemDefaultFocus();   // You may set the initial focus when opening the combo (scrolling + for keyboard navigation support)
        }
        ImGui::EndCombo();
      }
      if (ImGui::Button("Add Component", ImVec2(330, 20))) {

        // Add transform component
        if (m_tempComponentType == buEngineSDK::ComponentType::TRANSFORM) {
          Transform* pTransform = new Transform;
          pTransform->init();
          node.getActor().addComponent(pTransform);
        }

        // Add circle shape component
        if (m_tempComponentType == buEngineSDK::ComponentType::CIRCLE_SHAPE) {
          CircleShape* pCircleShape = new CircleShape;
          pCircleShape->init();
          node.getActor().addComponent(pCircleShape);
        }
        
        // Add rectangle shape component
        if (m_tempComponentType == buEngineSDK::ComponentType::RECTANGLE_SHAPE) {
          RectangleShape* pRectangleShape = new RectangleShape;
          pRectangleShape->init();
          node.getActor().addComponent(pRectangleShape);
        }
        
        // Add Animator component
        if (m_tempComponentType == buEngineSDK::ComponentType::ANIMATOR) {
          Animator* pAnimator = new Animator;
          pAnimator->init();
          node.getActor().addComponent(pAnimator);
        }
      }
    }


    ImGui::End();
  }
  
  vector<Node>& 
  SceneGraph::getNodes() {
    return m_nodes;
  }

  void 
  SceneGraph::createEmptyActor() {
    // Create node
    Node* pNode;
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
    Transform* pTransform = new Transform;
    pTransform->init();
    newNode.getActor().addComponent(pTransform);

    m_nodes.push_back(newNode);
  }
  
  void 
  SceneGraph::createCircleShapeActor() {
    Node* pNode;
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
    Transform* pTransform = new Transform;
    pTransform->init();
    newNode.getActor().addComponent(pTransform);

    // Add circle shape component
    CircleShape* pCircleShape = new CircleShape;
    pCircleShape->init();
    newNode.getActor().addComponent(pCircleShape);

    m_nodes.push_back(newNode);
  }
  
  void 
  SceneGraph::createRectangleShapeActor() {
    Node* pNode;
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
    Transform* pTransform = new Transform;
    pTransform->init();
    newNode.getActor().addComponent(pTransform);

    // Add circle shape component
    RectangleShape* pRectangleShape = new RectangleShape;
    pRectangleShape->init();
    newNode.getActor().addComponent(pRectangleShape);

    m_nodes.push_back(newNode);
  }
}