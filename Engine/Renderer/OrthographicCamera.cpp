#include "OrthographicCamera.hpp"

#include "glm/gtc/matrix_transform.hpp"



namespace Engine
{
    OrthographicCamera::OrthographicCamera(float x, float y) :
        m_pos(0.0f), m_rotation(0.0f)
    {
        RecalculateViewMatrix();
        RecalculateProjMatrix(x, y);
        RecalculateViewProjMatrix();
    }

    void OrthographicCamera::RecalculateViewMatrix()
    {
        glm::mat4 transformed = glm::translate(glm::mat4(1.0f), -m_pos);
        transformed = glm::rotate(transformed, -m_rotation, glm::vec3(0.0f, 0.0f, 1.0f));
        m_view_mat = transformed;
    }

    void OrthographicCamera::RecalculateProjMatrix(float x, float y)
    {
        float XonYPlusOne = x/y + 1;
        float YonXPlusOne = y/x + 1;
        m_proj_mat = glm::ortho(-XonYPlusOne, XonYPlusOne, -YonXPlusOne, YonXPlusOne);
    }

    void OrthographicCamera::RecalculateViewProjMatrix()
    {
        m_viewproj_mat = m_proj_mat * m_view_mat;
    }
}
