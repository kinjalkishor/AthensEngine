cd "E:/nex/NexEngine/NexWars/source/code/test2/a_rs_shaders"
glslc.exe "09_shader_base.vert" -o "shaders_spirv/09_shader_base_vert.spv"
glslc.exe "09_shader_base.frag" -o "shaders_spirv/09_shader_base_frag.spv"
glslc.exe "17_shader_vertexbuffer.vert" -o "../shaders_spirv/17_shader_vertexbuffer_vert.spv"
glslc.exe "17_shader_vertexbuffer.frag" -o "../shaders_spirv/17_shader_vertexbuffer_frag.spv"
glslc.exe "21_shader_ubo.vert" -o "../shaders_spirv/21_shader_ubo_vert.spv"
glslc.exe "21_shader_ubo.frag" -o "../shaders_spirv/21_shader_ubo_frag.spv"
glslc.exe "25_shader_textures.vert" -o "../shaders_spirv/25_shader_textures_vert.spv"
glslc.exe "25_shader_textures.frag" -o "../shaders_spirv/25_shader_textures_frag.spv"
glslc.exe "26_shader_depth.vert" -o "../shaders_spirv/26_shader_depth_vert.spv"
glslc.exe "26_shader_depth.frag" -o "../shaders_spirv/26_shader_depth_frag.spv"
pause


