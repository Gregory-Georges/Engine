# Engine

Following the tutorials on Youtube made by the Cherno at https://www.youtube.com/playlist?list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT.

# Build

Read the platform section before building.

In order to build this library, one must first compile and install the libraries glew, spdlog and glfw in the dependency folder. They can all be compiled and installed using the cmake build system. First, open a terminal in the dependencie's directory and run <b>cmake</b>. Then, run <b>sudo cmake --build . --target install</b> to install the designated libraries. Links are already made in the Engine project. Next, make sure all the dependencies submodules are downloaded using the <b>git submodule update --init</b>. Then, run the main premake file with the <b>premake5</b> command and compile using your favorite environment.

# Platform

Currently, the premake file is written as to support a linux environement. To support other platforms, the premake file has to be modified. Here is what needs to be <b>modified</b> :

- The require flag at the start of the premake script
- The referenced backends file in the premake file under the imgui project in the premake script

Also, somme files are platform dependant and their contents must be <b>changed</b> :

- Everything in the Engine/Platform folder is platform dependant and must be changed according to the environment.
- The platform flag has to bee changed inn the platform.h file

<b>Supported environments (premake files)</b>:
- Linux, glfw3 for window processing and glad for opengl access
