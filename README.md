# Engine

Following the tutorials on Youtube made by the Cherno at https://www.youtube.com/playlist?list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT.

# Build

Read the platform section before building.

First, make sure all the dependencies submodules are downloaded using the <b>git submodule update --init</b> command. They can mostly be compiled using the cmake build system; First, open a terminal in the dependencies directory and run <b>cmake .</b>. Then, run <b>make</b> to compile and link the individual library. This should produce a '.a' file in the dependency repository. Then, run the main premake file in the project root with the <b>premake5 *IDE*</b> command and compile using your favorite environment.

# Platform

Knowledge of using the premake build system is required. Currently, the premake file is written as to support a linux environement only. To support other platforms, the premake file may have to be modified. Here is what needs to be <b>modified</b> :

- The require flag at the start of the premake script
- The referenced backends file in the premake file under the imgui project in the premake script

Some files are platform dependant and their contents must be <b>changed</b> depending on the platform. If you are compiling on a different platform, please use the correct premake file of run a supported environment.

<b>Supported environments (premake files)</b>:
- Linux, glfw3 for window processing and glad for opengl interpretation
- (More to come, I promise...)
