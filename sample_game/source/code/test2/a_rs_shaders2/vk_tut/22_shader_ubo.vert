#version 450

layout(binding = 0) uniform UniformBufferObject {
    //mat4 world;
    //mat4 view;
    //mat4 proj;
	
	mat4 wvp;
} ubo;

//layout(location = 0) in vec2 inPosition;
layout(location = 0) in vec3 inPosition;
layout(location = 1) in vec4 inColor;

layout(location = 0) out vec4 fragColor;

void main() {
    //gl_Position = ubo.proj * ubo.view * ubo.world * vec4(inPosition, 0.0, 1.0);
	
	//gl_Position = ubo.proj * ubo.view * ubo.world * vec4(inPosition, 1.0);
	
	
	//gl_Position = ubo.wvp * vec4(inPosition, 1.0);
	gl_Position = vec4(inPosition, 1.0) * ubo.wvp;
	
    fragColor = inColor;
}
