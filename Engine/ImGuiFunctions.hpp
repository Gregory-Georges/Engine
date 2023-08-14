#ifndef IMGUIFUNCTIONS_HPP
#define IMGUIFUNCTIONS_HPP



namespace Engine
{
    class ImGuiFunctions
    {
    public:

        //Singleton get
        static ImGuiFunctions& Get();

        void ImGuiInit();
        void ImGuiTerminate();

        void ImGuiNewFrame();
        void ImGuiDraw();

        void ImGuiBegin(std::string window_name);
        void ImGuiEnd();


    private:

        ImGuiFunctions() = default;
    };
}

#endif // IMGUIFUNCTIONS_HPP
