REM "D:/osl/dxc/bin/x64/dxc.exe"

@echo off
for %%i in (*.fx *.hlsl) do "C:/Program Files (x86)/Windows Kits/10/bin/10.0.22621.0/x64/fxc.exe" /E VS /T vs_5_0 /Fo shaders_cso/%%~ni_vs.cso %%~i
for %%i in (*.fx *.hlsl) do "C:/Program Files (x86)/Windows Kits/10/bin/10.0.22621.0/x64/fxc.exe" /E PS /T ps_5_0 /Fo shaders_cso/%%~ni_ps.cso %%~i
pause