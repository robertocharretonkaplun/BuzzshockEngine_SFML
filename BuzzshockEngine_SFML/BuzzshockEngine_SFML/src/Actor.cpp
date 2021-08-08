#include "Actor.h"

namespace buEngineSDK {
  void 
  Actor::init() {
  }

  void 
  Actor::update() {
  }

  void 
  Actor::render() {
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