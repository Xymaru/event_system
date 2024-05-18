cd ..
call vendor\premake\premake5.exe vs2019
cd Editor
cd game
call ..\..\vendor\premake\premake5.exe vs2019
cd..
cd game_assembly
call ..\..\vendor\premake\premake5.exe vs2019
cd..
cd..
PAUSE