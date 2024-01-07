@echo OFF
cd /d %~dp0
cd listes_chainees
echo compilation des listes chainees ...
gcc *.c -c -Wall -Wextra
if %ERRORLEVEL% gtr 0 (
    echo compilation failed
    pause
    exit /b 1
)
cd ..\logiciel
echo compilation des fichiers sources du logiciel ...
gcc *.c -c -Wall -Wextra
if %ERRORLEVEL% gtr 0 (
    echo compilation failed
    pause
    exit /b 1
)
cd ..
echo compilation de wallpainter.exe ...
gcc .\listes_chainees\*.o .\logiciel\*.o -o .\wallpainter.exe -Wall -Wextra
if %ERRORLEVEL% gtr 0 (
    echo compilation failed
    pause
    exit /b 1
)
echo compilation successful
pause
exit /b 0
