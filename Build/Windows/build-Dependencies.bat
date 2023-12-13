:: Get premake5 path
set /p PremakePath=What is the path for the premake5.exe file? : 





:: Go to root
cd ..\

:: Build fmt
cd ..\Dependencies\fmt
cmake .
make
start devenv FMT.sln

:: Build glad
cd ..\glad
PremakePath vs2022
start devenv glad.sln

:: Build glfw
cd ..\glfw
cmake .
make
start devenv GLFW.sln

:: Build glm
cd ..\glm
cmake .
make
start devenv glm.sln

:: Build dear imgui
cd ..\imgui
cp backends\imgui_impl_opengl3_loader.h .\
cp backends\imgui_impl_opengl3.h .\
cp backends\imgui_impl_opengl3.cpp .\
cp backends\imgui_impl_glfw.h .\
cp backends\imgui_impl_glfw.cpp .\
PremakePath vs2022
start devenv imgui.sln

:: Build spdlog
cd ../spdlog
cmake .
make
start devenv spdlog.sln

:: Build stb_image
cd ../stb
PremakePath vs2022
start devenv stb.sln