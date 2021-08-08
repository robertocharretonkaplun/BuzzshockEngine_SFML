#include "Node.h"

namespace buEngineSDK {
  void
  Node::setChild(Node * _node) {
    m_child = _node;
  }

  Node* 
  Node::getChild() {
    return m_child;
  }

  void 
  Node::setActor(Actor _actor) {
    m_actor = _actor;
  }

  Actor& 
  Node::getActor() {
    return m_actor;
  }

  Node*
  Node::getParent() {
    return m_parent;
  }

  void 
  Node::setParent(Node * _node) {
    m_parent = _node;
  }

  void 
  Node::setName(string _name) {
    m_name = _name;
  }

  string 
  Node::getName() {
    return m_name;
  }
}