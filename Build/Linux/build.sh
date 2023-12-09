# Copy build file and go to root
cp ./premake5.lua ../../
cd ../../

# Build fmt
cd ./Dependencies/fmt
cmake .
make

# Build glad
cd ../glad
gcc -c src/glad.c -Iinclude/
ar rvs libglad.a glad.o

# Build glfw
cd ../glfw
cmake .
make

# Build glm
cd ../glm
cmake .
make

# Build dear imgui
cd ../imgui
cp backends/imgui_impl_opengl3_loader.h ./
cp backends/imgui_impl_opengl3.h ./
cp backends/imgui_impl_opengl3.cpp ./
cp backends/imgui_impl_glfw.h ./
cp backends/imgui_impl_glfw.cpp ./
gcc -c *.cpp -Iinclude/
ar rvs libimgui.a **.o

# Build spdlog
cd ../spdlog
cmake .
make

# Build stb_image
cd ../stb
gcc -c stb_image.cpp -Iinclude/
ar rvs libstb.a stb_image.o

# Create main project file
cd ../../
premake5 codeblocks
