# Engine

Following the tutorials on Youtube made by the Cherno at https://www.youtube.com/playlist?list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT.

# Build

In order to build this library, one must first compile and install the libreries glew, spdlog, glfw and glad in the dependency folder. fmt, spdlog and glfw can all be compiled and installed using the cmake build system. First, open a terminal in the root directory with the file and run <b>cmake</b>. Then, run <b>sudo cmake --build . --target install</b> to install the library. For glad, which isn't built with cmake, you must compile the library yourself using the premake script. Links are already made in the Engine project. Then, run the main premake file with the premake comand and compile using your favorite emvironment.
