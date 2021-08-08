#pragma once
#include <Prerequisites.h>
#include <Component.h>
namespace buEngineSDK {
	class Transform;
	class CircleShape : public Component {
	public:
		CircleShape()  = default;
		~CircleShape() = default;

		void
		init() override;

		void
		update() override;

		void
		update(Transform * _transform);

		void
		render() override;

		void
		render(sf::RenderWindow & _window);
		
		void
		ui() override;

		buEngineSDK::ComponentType::E
		getType() override;

	  string
		getName() override;

		sf::CircleShape & 
		getShape();
	private:
		// Object name
		string m_name = "Circle Shape";


		sf::CircleShape m_shape;

		sf::Color m_color;

		// componentType: This object store the type of component that is the class.
		buEngineSDK::ComponentType::E m_componentType = buEngineSDK::ComponentType::E::CIRCLE_SHAPE;
	};
}