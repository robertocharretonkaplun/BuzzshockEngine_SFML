#pragma once
#include <Prerequisites.h>
#include <Component.h>

namespace buEngineSDK {
	class Transform : public Component {
	public:
		Transform() = default;
		~Transform() = default;

		void
		init() override;

		void
		update() override;

		void
		render() override;
		
		void
		ui() override;

		buEngineSDK::ComponentType::E
		getType() override;

	  string
		getName() override;


	private:
		void
		vector2UI(string label,
								float* values, 
                string _id0,
                string _id1,
								float resetValues = 0.0f, 
								float columnWidth = 100.0f);

	public:
		// Object name
		string m_name = "Transform";
		
		// Position for UI
		float* m_pos;
		// Rotation for UI
		float* m_rot;
		// Scale for UI
		float* m_scal;
		// Angle for UI
		float* m_ang;
		
	private:
		// componentType: This object store the type of component that is the class.
		buEngineSDK::ComponentType::E m_componentType = buEngineSDK::ComponentType::E::TRANSFORM;
	};
}
