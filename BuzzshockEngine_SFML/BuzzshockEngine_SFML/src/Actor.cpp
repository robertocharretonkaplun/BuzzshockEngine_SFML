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
  }

  vector<Component*>& 
  Actor::getComponents() {
    return m_components;
  }
}