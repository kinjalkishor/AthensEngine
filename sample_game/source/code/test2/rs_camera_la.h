#pragma once

#include "base_gmath.h"

enum class camera_type_e { 
	LANDOBJECT, 
	AIRCRAFT,
};

class camera_la {
private:
	camera_type_e m_camera_type = camera_type_e::LANDOBJECT;		

	gm::vec3 m_pos   = gm::vec3(0.0f, 0.0f, 0.0f);
	gm::vec3 m_right = gm::vec3(1.0f, 0.0f, 0.0f);
	gm::vec3 m_up    = gm::vec3(0.0f, 1.0f, 0.0f);
	gm::vec3 m_look  = gm::vec3(0.0f, 0.0f, 1.0f);

public:
	

	camera_la() {}
	camera_la(camera_type_e camera_type) { m_camera_type = camera_type; }
	~camera_la() {}

	void set_camera_type(camera_type_e camera_type) { m_camera_type = camera_type; }

	gm::vec3 get_position() const { return m_pos; }
	void set_position(const gm::vec3& pos) { m_pos = pos; }

	gm::vec3 get_right() const { return m_right; }
	gm::vec3 get_up() const { return m_up; }
	gm::vec3 get_look() const { return m_look; }


	// left/right
	void strafe(float units) {
		// move only on xz plane for land object
		if (m_camera_type == camera_type_e::LANDOBJECT) {
			m_pos += gm::vec3(m_right.x, 0.0f, m_right.z) * units;
		}

		if (m_camera_type == camera_type_e::AIRCRAFT) {
			m_pos += m_right * units;
		}
	}

	// up/down
	void fly(float units) {
		// move only on y-axis for land object
		//if (m_camera_type == camera_type_e::LANDOBJECT) {
		//	m_pos.y += units;
		//}

		//if (m_camera_type == camera_type_e::AIRCRAFT) {
		//	m_pos += m_up * units;
		//}

		//or
		m_pos += m_up * units;
	}

	// forward/backward
	void walk(float units) {
		// move only on xz plane for land object
		if (m_camera_type == camera_type_e::LANDOBJECT) {
			m_pos += gm::vec3(m_look.x, 0.0f, m_look.z) * units;
		}

		if (m_camera_type == camera_type_e::AIRCRAFT) {
			m_pos += m_look * units;
		}
	}
	
	// rotate on right vector
	void pitch(float angle) {
		gm::mat4 T;
		T = gm::mat4_rotation_axis(m_right, angle);

		// rotate m_up and m_look around m_right vector
		m_up = gm::vec3_transform_coord(m_up, T);
		m_look = gm::vec3_transform_coord(m_look, T);
	}

	// rotate on up vector
	void yaw(float angle) {
		gm::mat4 T;

		// rotate around world y (0, 1, 0) always for land object
		if (m_camera_type == camera_type_e::LANDOBJECT) {
			T = gm::mat4_rotation_y(angle);
		}
		// rotate around own up vector for aircraft
		if (m_camera_type == camera_type_e::AIRCRAFT) {
			T = gm::mat4_rotation_axis(m_up, angle);
		}

		// rotate m_right and m_look around m_up or y-axis
		m_right = gm::vec3_transform_coord(m_right, T);
		m_look = gm::vec3_transform_coord(m_look, T);
	}

	// rotate on look vector
	void roll(float angle) {
		// only roll for aircraft type
		if (m_camera_type == camera_type_e::AIRCRAFT) {
			gm::mat4 T;
			T = gm::mat4_rotation_axis(m_look, angle);

			// rotate m_up and m_right around m_look vector
			m_right = gm::vec3_transform_coord(m_right, T);
			m_up = gm::vec3_transform_coord(m_up, T);
		}
	}

	gm::mat4 get_view_matrix() {
		// Keep camera's axes orthogonal to eachother
		m_look = gm::vec3_normalize(m_look);

		m_up = gm::vec3_cross(m_look, m_right);
		m_up = gm::vec3_normalize(m_up);

		m_right = gm::vec3_cross(m_up, m_look);
		m_right = gm::vec3_normalize(m_right);

		// Build the view matrix:
		float x = -gm::vec3_dot(m_right, m_pos);
		float y = -gm::vec3_dot(m_up, m_pos);
		float z = -gm::vec3_dot(m_look, m_pos);

		return gm::mat4(
			m_right.x, m_up.x, m_look.x, scast<float>(0),
			m_right.y, m_up.y, m_look.y, scast<float>(0),
			m_right.z, m_up.z, m_look.z, scast<float>(0),
			x,         y,      z,        scast<float>(1)
		);
	}	

};
