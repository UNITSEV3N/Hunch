@echo off
setlocal

rem This script lives in the "Scripts/" folder, it needs to stop up one level to the project root
pushd "%~dp0.."

rem Set Premake5 location
set PREMAKE_EXE=Vendor\Premake\premake5.exe

if not exist "%PREMAKE_EXE%" (
	echo [ERROR] premake5.exe not found!
	echo [ERROR] Expected to be at "%PREMAKE_EXE%"
	pause
	popd
	exit /b 1
)

echo Running Premake from project root...
"%PREMAKE_EXE%" vs2026

if %ERRORLEVEL% neq 0 (
	echo [ERROR] Premake failed.
	pause
	popd
	exit /b 1
)

echo Done!
pause
popd

endlocal