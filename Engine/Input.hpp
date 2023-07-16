#ifndef INPUT_HPP_INCLUDED
#define INPUT_HPP_INCLUDED



namespace Engine
{
    class Input
    {
    public:

        Input() { s_instance = this; }
        virtual ~Input() {}

        //Get dsts from instance
        std::pair<float, float> GetMousePos(){ return s_instance.GetMousePosImpl(); }
        bool GetKey(int keycode){ return s_instance->GetKeyImpl(keycode); }
        bool GetMouseButton(int mousecode){ return s_instance->GetMouseButtonImpl(MouseCode); }

    protected:

        //Virtual implementation
        virtual std::pair<float, float> GetMousePosImpl() = 0;
        virtual bool GetKeyImpl(int keycode) = 0;
        virtual bool GetMouseButtonImpl(int mousecode) = 0;



    private:

        static Input* s_instance;
    };
}



#endif // INPUT_HPP_INCLUDED
