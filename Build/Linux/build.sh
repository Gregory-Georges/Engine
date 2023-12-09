cp ./premake5.lua ../../
cd ../../

cd ./Dependencies/fmt
cmake .
make

cd ../glad
gcc -c src/glad.c -Iinclude/
ar rvs libglad.a glad.o

cd ../glfw
cmake .
make

cd ../glm
cmake .
make

cd ../imgui
cp backends/imgui_impl_opengl3_loader.h ./
cp backends/imgui_impl_opengl3.h ./
cp backends/imgui_impl_opengl3.cpp ./
cp backends/imgui_impl_glfw.h ./
cp backends/imgui_impl_glfw.cpp ./
gcc -c *.cpp -Iinclude/
ar rvs libimgui.a **.o

cd ../spdlog
cmake .
make

cd ../stb
gcc -c stb_image.cpp -Iinclude/
ar rvs libstb.a stb_image.o

cd ../../
premake5 codeblocks
