/**
 * @brief This class is in charge of storing a node structure for the scene graph,
 * this class has an actor by default that is able to set up multiple components,
 * at the same time, the class has the possibility of having multiple nodes with
 * more actors and a parent in which the node can be refered.
 *
 * Example:
 * SceneGraph
 * |---> Nodes (Root) - [Parent = Null, Actor = Null, Nodes = 1]
 * |     |---> Node (Empty) - [Parent = Root, Actor = true, Nodes = 3 ]
 * |			     |---> Actor
 * |					 |     |---> components
 * |           |---> Parent = null
 * |           |---> Nodes = 3 more nodes (example)
 */
#pragma once
#include <Prerequisites.h>
#include <Actor.h>

namespace buEngineSDK {
	class Node {
	public:
		Node()  = default;
		~Node() = default;

	/**
		 * @brief This method is in charge of setting a child from the same class
		 * (buSceneNode), this child can store the same information of the curr obj.
		 */ 
		void
		setChild(Node * _node);

		/**
		 * @brief This method return the current node child of the class.
		 */
		Node * 
		getChild();

		/**
		 * @brief This method is in charge of setting a new actor for the current class.
		 */
		void
		setActor(Actor _actor);

		/**
		 * @brief This method is in charge of returning the current actor of the class.
		 */
		Actor &
		getActor();

		/**
		 * @brief This method is in charge getting the parent node of the class.
		 */
		Node *
		getParent();

		/**
		 * @brief This method is in charge of setting a node that is the parent of 
		 * the current object.
		 */
		void
		setParent(Node * _node);

		/**
		 * @brief This method is in charge of set the name of the class.
		 */
		void
		setName(string _name);

		/**
		 * @brief This method is in charge of provide the name of the class.
		 */
		string
		getName();
	private:
		// Name: This variable store the name of the object.
		string m_name = "Empty Node";

		// Actor: This variable store a actor that can use mulitple components.
		Actor m_actor;

		// Child: This variable store a 'Node' reference to be a child.
		Node * m_child;

		// Parent: This variable store a 'Node' reference to be a parent.
		Node* m_parent;
	};
}
