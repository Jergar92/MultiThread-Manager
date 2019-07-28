#ifndef _ORBITAL_CAMERA
#define _ORBITAL_CAMERA

#include "Math/float3.h"

#define CAMERA_MOVE_SPEED_DEFAULT 5.0f;
#define CAMERA_ROTATION_SPEED_DEFAULT 5.0f;
#define CAMERA_SCROLL_SPEED_DEFAULT 5.0f;


class OrbitalCamera
{
public:
	OrbitalCamera();
	~OrbitalCamera();

	void Update();
private:


	void LookAt(const float3& target);
	void Zoom(const float3& target);

private:

	float3 cameraPos = float3::zero;
	float3 cameraRef = float3::zero;
	float cameraMoveSpeed = CAMERA_MOVE_SPEED_DEFAULT;
	float cameraRotationSpeed = CAMERA_MOVE_SPEED_DEFAULT;
	float cameraScrollSpeed = CAMERA_MOVE_SPEED_DEFAULT;

};
#endif


