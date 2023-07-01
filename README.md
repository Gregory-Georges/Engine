# Engine

Following the tutorials on Youtube made by the Cherno at https://www.youtube.com/playlist?list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT.

# Build

In order to build this library, one must first compile and install the libraries glew, spdlog and glfw in the dependency folder. They can all be compiled and installed using the cmake build system. First, open a terminal in the dependencie's directory and run <b>cmake</b>. Then, run <b>sudo cmake --build . --target install</b> to install the designated libraries. Links are already made in the Engine project. Next, make sure all the dependencies submodules are downloaded using the <b>git submodule update --init</b>. Then, run the main premake file with the <b>premake5</b> command and compile using your favorite emvironment.
