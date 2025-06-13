@echo off
setlocal enabledelayedexpansion

REM Change to the script's directory so relative paths work
cd /d %~dp0

REM Move one folder up from .vscode to project root
cd /d "%~dp0.."

REM Path to g++
set GPP=g++

REM Output executable name
set OUT=main.exe

REM Absolute paths to Raylib
set RAYLIB_INC=C:\raylib\raylib\src
set RAYLIB_LIB=C:\raylib\raylib\src

REM Gather all .cpp files recursively (relative paths)
set FILES=
for /R %%f in (*.cpp) do (
    REM Make each file path relative to current directory
    set "REL=%%f"
    set "REL=!REL:%CD%\=!"
    set FILES=!FILES! "!REL!"
)

REM Construct the command
set CMD=%GPP%%FILES% -o %OUT% -std=c++20 -I %RAYLIB_INC% -L %RAYLIB_LIB% -lraylib -lopengl32 -lgdi32 -lwinmm -Wall -O1 -g -fdiagnostics-color=always

%CMD%