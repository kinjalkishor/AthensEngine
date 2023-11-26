REM "D:/osl/dxc/bin/x64/dxc.exe"

@echo off
"C:/Program Files (x86)/Windows Kits/10/bin/10.0.22621.0/x64/fxc.exe" /E VS /T vs_5_0 /Fo shaders_cso/d3d11_vertex_pc_vs.cso ../d3d11_vertex_pc.fx
"C:/Program Files (x86)/Windows Kits/10/bin/10.0.22621.0/x64/fxc.exe" /E PS /T ps_5_0 /Fo shaders_cso/d3d11_vertex_pc_ps.cso ../d3d11_vertex_pc.fx
"C:/Program Files (x86)/Windows Kits/10/bin/10.0.22621.0/x64/fxc.exe" /E VS /T vs_5_0 /Fo shaders_cso/d3d11_vertex_pct_vs.cso ../d3d11_vertex_pct.fx
"C:/Program Files (x86)/Windows Kits/10/bin/10.0.22621.0/x64/fxc.exe" /E PS /T ps_5_0 /Fo shaders_cso/d3d11_vertex_pct_ps.cso ../d3d11_vertex_pct.fx
pause