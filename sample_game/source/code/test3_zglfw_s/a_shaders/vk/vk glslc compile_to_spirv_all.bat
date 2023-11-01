@echo off
REM for %%i in (*.vert *.frag) do %VULKAN_SDK%/Bin/glslangValidator.exe -V "%%~i" -o "shaders_spirv/%%~i.spv"
for %%i in (*.vert) do %VULKAN_SDK%/Bin/glslangValidator.exe -V "%%~i" -o "shaders_spirv/%%~ni_vert.spv"
for %%i in ( *.frag) do %VULKAN_SDK%/Bin/glslangValidator.exe -V "%%~i" -o "shaders_spirv/%%~ni_frag.spv"
pause