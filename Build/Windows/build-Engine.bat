:: Get premake5 path
set /p PremakePath=What is the path for the premake5.exe file? : 



:: Build main project
cd ..\..\
PremakePath vs2022
start devenv Engine.sln