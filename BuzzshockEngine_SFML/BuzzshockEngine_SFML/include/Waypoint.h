#pragma once
#include "Prerequisites.h"

namespace buEngineSDK {

	
	class Waypoint
	{
	public:
		Waypoint() = default;
		~Waypoint() = default;

		void
		addPoint(float _x, float _y) {
			Vector2F tmpVec;
			tmpVec.x = _x;
			tmpVec.y = _y;
			m_points.push_back(tmpVec);
		};
	private:
		vector<Vector2F> m_points;
	};
}