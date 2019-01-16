#pragma once
#include<glm.hpp>
#include<gtc/matrix_access.hpp>
namespace Math
{
	namespace Matrix
	{
		//This function creates a 2D orthographic projection matrix
		static glm::mat4 calcOrtho(float left, float right, float top, float bottom, float near, float far)
		{
			glm::vec4 col0, col1, col2, col3;
			glm::mat4 returnMat = glm::mat4();

			col0 = glm::column(returnMat, 0);
			col1 = glm::column(returnMat, 1);
			col2 = glm::column(returnMat, 2);
			col3 = glm::column(returnMat, 3);

			//Do calculations
			col0[0] = 2.f / (right - left);
			col0[1] = 0.f;
			col0[2] = 0.f;
			col0[3] = 0.f;

			col1[0] = 0.f;
			col1[1] = 2.f / (top - bottom);
			col1[2] = 0.f;
			col1[3] = 0.f;

			col2[0] = 0.f;
			col2[1] = 0.f;
			col2[2] = -2.f / (far - near);
			col2[3] = 0.f;

			col3[0] = -(right + left) / (right - left);
			col3[1] = -(top + bottom) / (top - bottom);
			col3[2] = -(far + near) / (far - near);
			col3[3] = 1.f;

			//Reassemble the return matrix
			returnMat = glm::mat4(col0, col1, col2, col3);

			//Leave function
			return returnMat;
		}
	}
}