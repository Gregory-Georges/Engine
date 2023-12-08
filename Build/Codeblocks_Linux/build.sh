cp ./* ../../
cd ../../

cd ./Dependencies/fmt
cmake .
make

cd ../glad
premake5 codeblocks

cd ../glfw
cmake .
make

cd ../glm
cmake .
make

cd ../imgui
premake5 codeblocks

cd ../spdlog
cmake .
make

cd ../stb
premake5 codeblocks


