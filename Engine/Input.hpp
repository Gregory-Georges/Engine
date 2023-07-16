#ifndef INPUT_HPP_INCLUDED
#define INPUT_HPP_INCLUDED



namespace Engine
{
    class Input
    {
    public:

        static std::pair<float, float> GetMousePos();
        static bool GetKey(int keycode);
        static bool GetMouseButton(int mousecode);

    private:

        Input() {}
    };
}



#endif // INPUT_HPP_INCLUDED
