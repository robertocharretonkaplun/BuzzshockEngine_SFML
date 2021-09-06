#pragma once
#include <Prerequisites.h>
#include <Component.h>

namespace buEngineSDK {
	class CircleShape;
	class RectangleShape;
	class Transform;
	class Actor	{
	public:
		Actor()  = default;
		~Actor() = default;

		void 
		init();

		void
		update();
		
		void
		render(sf::RenderTexture & _scene);

		void
		addComponent(Component * _component);

		void
		addComponent(ComponentType::E _type);

		void
		removeComponent();

		void
		setParent();

		Actor *
		getParent();

		void
		setChild();

		Actor *
		getChild();
		
		void
		setName(string _name);

		string
		getName();

		void
		setActive(bool _val);

		void
		ui();

		vector<Component*> &
		getComponents();

	private:
		// name: This variable store the name of the actor.
		string m_name = "Empty Actor";

		// canRender: This variable checks if the actor can be draw or not
		bool m_canRender = true;

		// Components: This vector store the different tipe of components in the class 
		// (Example: Transform, Material, Rigidbody, etc...)
		vector<Component*> m_components;

		// Parent: This object works as a parent reference for the class.
		Actor * m_parent;

		// Child: This object works as a child reference for the class.
		Actor * m_child;

		Transform* t;
	};
}
