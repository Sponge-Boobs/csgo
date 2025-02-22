#pragma once
#include "math/Vector.hpp"

enum
{
	DLIGHT_NO_WORLD_ILLUMINATION = 0x1,
	DLIGHT_NO_MODEL_ILLUMINATION = 0x2,

	// NOTE: These two features are used to dynamically tweak the alpha on displacements
	// which is a special effect for selecting which texture to use. If 
	// we ever change how alpha is stored for displacements, we'll have to kill this feature
	DLIGHT_ADD_DISPLACEMENT_ALPHA = 0x4,
	DLIGHT_SUBTRACT_DISPLACEMENT_ALPHA = 0x8,
	DLIGHT_DISPLACEMENT_MASK = (DLIGHT_ADD_DISPLACEMENT_ALPHA | DLIGHT_SUBTRACT_DISPLACEMENT_ALPHA),
};

class DLight_t
{
private:
	struct DColor
	{
		uint8_t r, g, b;
	};
public:
	int	m_flags;
	Vector m_origin;
	float m_radius;
	DColor m_color;
	char m_exponent;
	float m_die;
	float m_decay;
	float m_minlight;
	int	m_key;
	int	m_style;
	Vector m_direction;
	float m_innerAngle;
	float m_outerAngle;
};

class IVEfx
{
public:
	VFUNC(DLight_t*, clAllocDlight, 4, (int key), (this, key));
	VFUNC(DLight_t*, clAllocElight, 5, (int key), (this, key));
	VFUNC(DLight_t*, getElightbyKey, 8, (int key), (this, key));
};