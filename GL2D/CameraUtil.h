#pragma once
#include "GLHeader.h"

enum class ZOOM{ In, Out };

class CameraUtil {
private:
	glm::vec3 CamPos{}, CamDirection{}, CamUp{};
	unsigned int ProjectionLocation{}, ViewLocation{}, ViewPosLocation{};
	
public:
	glm::mat4 ViewMatrix{}, Projection{};
	GLfloat Rotation{};
	GLfloat x{}, y{};
	GLfloat Zoom{ 1.0f };
	GLfloat ShakeValueX = 0.0;
	GLfloat ShakeValueY = 0.0;

	void CalculateASPECT();
	void UpdateCamera();
	void SetCamera();
	void ProcessTransform(bool UseTextShader);
};
extern CameraUtil cam;


class CameraControlUtil {
public:
	void Translate(GLfloat MoveX, GLfloat MoveY);
	void Rotate(GLfloat Radians);
	void SetZoom(ZOOM ZoomOpt, GLfloat Value);
	void UpdateZoom(float FT);
};
extern CameraControlUtil camUtil;