#include "Actor.h"
#include "CircleShape.h"
#include "RectangleShape.h"
#include "Transform.h"
#include "Animator.h"
namespace buEngineSDK {
  void 
  Actor::init() {
    t = new Transform;
  }

  void 
  Actor::update() {
      
    for (auto& component : m_components) {
      if (component->getType() == buEngineSDK::ComponentType::E::TRANSFORM) {
        auto transform = reinterpret_cast<Transform*>(component);
        t = transform;
        //circleShape->update(transform);
      }
      if (component->getType() == buEngineSDK::ComponentType::E::CIRCLE_SHAPE) {
        auto circleShape = reinterpret_cast<CircleShape*>(component);
        circleShape->update(t);

        // Render animation
        for (auto& subComponent :m_components) {
          if (subComponent->getType() == buEngineSDK::ComponentType::E::ANIMATOR) {
            auto animator = reinterpret_cast<Animator*>(subComponent);
            circleShape->getShape().setTextureRect(animator->getuvRect());
          }
        }
      }
      if (component->getType() == buEngineSDK::ComponentType::E::RECTANGLE_SHAPE) {
        auto rectangleShape = reinterpret_cast<RectangleShape*>(component);
        rectangleShape->update(t);

        // Render animation
        for (auto& subComponent : m_components) {
          if (subComponent->getType() == buEngineSDK::ComponentType::E::ANIMATOR) {
            auto animator = reinterpret_cast<Animator*>(subComponent);
            rectangleShape->getShape().setTextureRect(animator->getuvRect());
          }
        }
      }
      if (component->getType() == buEngineSDK::ComponentType::E::ANIMATOR) {
        auto animator = reinterpret_cast<Animator*>(component);
        animator->update();
      }
      component->update();
    }
  }

  void 
  Actor::render( sf::RenderTexture& _scene) {
    for (auto& component : m_components) {
      if (component->getType() == buEngineSDK::ComponentType::E::CIRCLE_SHAPE) {
        auto circleShape = reinterpret_cast<CircleShape*>(component);
        circleShape->render(_scene);
      }
      if (component->getType() == buEngineSDK::ComponentType::E::RECTANGLE_SHAPE) {
        auto rectangleShape = reinterpret_cast<RectangleShape*>(component);
        rectangleShape->render(_scene);
      }
    }
  }

  void 
  Actor::addComponent(Component* _component) {
    m_components.push_back(_component);
  }

  void 
  Actor::addComponent(ComponentType::E _type) {
    
  }

  void 
  Actor::removeComponent() {
  }

  void 
  Actor::setParent() {
  }

  Actor* 
  Actor::getParent() {
    return nullptr;
  }

  void 
  Actor::setChild() {
  }

  Actor* 
  Actor::getChild() {
    return nullptr;
  }

  void 
  Actor::setName(string _name) {
    m_name = _name;
  }

  string 
  Actor::getName() {
    return m_name;
  }

  void 
  Actor::setActive(bool _val) {
  }

  void 
  Actor::ui() {
    for (auto& component : m_components) {
      component->ui();
    }
  }

  vector<Component*>& 
  Actor::getComponents() {
    return m_components;
  }
}