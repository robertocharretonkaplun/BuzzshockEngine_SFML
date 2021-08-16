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
		void
		vector2UI(string label,
								float* values, 
                string _id0,
                string _id1,
								float resetValues = 0.0f, 
								float columnWidth = 100.0f);

		void
		circleColorUI();

		void
		textureUI();
	private:
		// Object name
		string m_name = "Circle Shape";


		sf::CircleShape m_shape;

		sf::Color m_color;

		float* m_origin;

		float m_outlineThickness = 0.0f;

		sf::Texture m_texture;

		sf::Sprite m_sprite;


		// componentType: This object store the type of component that is the class.
		buEngineSDK::ComponentType::E m_componentType = buEngineSDK::ComponentType::E::CIRCLE_SHAPE;
	};
}