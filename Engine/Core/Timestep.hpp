#ifndef TIMESTEP_HPP_INCLUDED
#define TIMESTEP_HPP_INCLUDED



namespace Engine
{
    class Timestep
    {
    public:
        Timestep(float time = 0.0f) : m_time(time) {}

        inline float GetSeconds() { return m_time; }
        inline float GetMiliseconds() { return m_time * 1000.0f; }

        inline operator float() const { return m_time; }

    private:
        float m_time;
    };
}



#endif // TIMESTEP_HPP_INCLUDED
