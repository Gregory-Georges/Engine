#include "Transform.hpp"
#include "glm/gtc/matrix_transform.hpp"



namespace Engine
{
    Transform::Transform() :
        m_position(1.0f), m_rotation(1.0f), m_scale(1.0f), m_modelmatrix(1.0f)
    {
    }

    void Transform::RecalculateModelMatrix()
    {
        m_modelmatrix = glm::mat4(1.0f);
        m_modelmatrix = glm::scale(m_modelmatrix, m_scale);
        m_modelmatrix = glm::rotate(m_modelmatrix, glm::radians(360.0f), m_rotation);
        m_modelmatrix = glm::translate(m_modelmatrix, m_position);
    }
}
