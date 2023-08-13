#ifndef TRANSFORM_HPP_INCLUDED
#define TRANSFORM_HPP_INCLUDED

#include "glm/glm.hpp"



namespace Engine
{
    class Transform
    {
    public:

        Transform();

        inline const glm::vec3& GetPosition() { return m_position; }
        inline const glm::vec3& GetRotation() { return m_rotation; }
        inline const glm::vec3& GetScale() { return m_scale; }

        inline void SetPosition(const glm::vec3& pos) { m_position = pos; }
        inline void SetRotation(const glm::vec3& rot) { m_rotation = rot; }
        inline void SetScale(const glm::vec3& sca) { m_scale = sca; }

        void RecalculateModelMatrix();
        inline const glm::mat4& GetModelMatrix() { return m_modelmatrix; }

    private:

        glm::vec3 m_position;
        glm::vec3 m_rotation;
        glm::vec3 m_scale;

        glm::mat4 m_modelmatrix;
    };
}



#endif // TRANSFORM_HPP_INCLUDED
