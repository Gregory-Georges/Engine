#ifndef ORTHOGRAPHICCAMERA_HPP
#define ORTHOGRAPHICCAMERA_HPP

#include "glm/glm.hpp"



namespace Engine
{
    class OrthographicCamera
    {
    public:

        OrthographicCamera(float x, float y);

        inline void SetPosition(const glm::vec3& pos) { m_pos = pos; }
        inline void SetRotation(float rot) { m_rotation = rot; }
        inline const glm::vec3& GetPosition() { return m_pos; }
        inline float GetRotation() { return m_rotation; }

        inline const glm::mat4& GetViewMatrix() { return m_view_mat; }
        inline const glm::mat4& GetProjMatrix() { return m_proj_mat; }
        inline const glm::mat4& GetViewProjMatrix() { return m_viewproj_mat; }

        void RecalculateViewMatrix();
        void RecalculateProjMatrix(float x, float y);
        void RecalculateViewProjMatrix();

    private:

        glm::mat4 m_view_mat;
        glm::mat4 m_proj_mat;
        glm::mat4 m_viewproj_mat;

        glm::vec3 m_pos;
        float m_rotation;
    };
}



#endif // ORTHOGRAPHICCAMERA_HPP
