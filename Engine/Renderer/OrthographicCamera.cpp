#include "OrthographicCamera.hpp"

#include "glm/gtc/matrix_transform.hpp"



namespace Engine
{
    OrthographicCamera::OrthographicCamera(float left, float right, float bottom, float top) :
        m_pos(0.0f), m_rotation(0.0f), m_proj_mat(glm::ortho(left, right, bottom, top, -1.0f, 1.0f))
    {
        RecalculateViewMatrix();
    }

    void OrthographicCamera::RecalculateViewMatrix()
    {
        glm::mat4 transformed = glm::translate(glm::mat4(1.0f), -m_pos);
        transformed = glm::rotate(transformed, -m_rotation, glm::vec3(0.0f, 0.0f, 1.0f));
        m_view_mat = transformed;

        m_viewproj_mat = m_proj_mat * m_view_mat;
    }
}
