#pragma once
#include <Prerequisites.h>

namespace buEngineSDK {

	namespace ComponentType {
		enum E {
			TRANSFORM = 0,
			SPRITE = 1,
			TEXTURE = 2,
			SHAPE = 3,
		};
	}

	class Component {
	public:
		Component ()  = default;
		~Component () = default;

		virtual void
		init() = 0;

		virtual void
		update() = 0;

		virtual void
		render() = 0;
		
		virtual	void
		ui() = 0;

		virtual buEngineSDK::ComponentType::E
		getType() = 0;

		virtual string
		getName() { return ""; };
	};
}
