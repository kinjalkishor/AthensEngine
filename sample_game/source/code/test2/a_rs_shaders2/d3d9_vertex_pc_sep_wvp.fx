
//uniform extern float4x4 g_mat_wvp;
uniform extern float4x4 g_mat_world_tri;
uniform extern float4x4 g_mat_view;
uniform extern float4x4 g_mat_proj;
		

struct VS_INPUT {
	float4 pos_l : POSITION0; 
	float4 vcolor : COLOR0;
};


struct VS_OUTPUT {
    float4 pos_h : POSITION0;
    float4 vcolor : COLOR0;
};


VS_OUTPUT VS(VS_INPUT vs_in) {
	// Zero out our output.
	VS_OUTPUT vs_out = (VS_OUTPUT)0;
	
	// Transform to homogeneous clip space.
	//vs_out.pos_h = mul(vs_in.pos_l, g_mat_wvp);
	//vs_out.pos_h = mul(g_mat_wvp, vs_in.pos_l); //smaller triangle
	
	// Normal forward multiply in shader for row major matrices.
	//vs_out.pos_h = mul(vs_in.pos_l, g_mat_world_tri); vs_out.pos_h = mul(vs_out.pos_h, g_mat_view); vs_out.pos_h = mul(vs_out.pos_h, g_mat_proj);
	vs_out.pos_h = mul(mul(mul(vs_in.pos_l, g_mat_world_tri), g_mat_view), g_mat_proj);
	
	// Reverse multiply in shader if column major matrices are sent.
	//vs_out.pos_h = mul(g_mat_world_tri, vs_in.pos_l); vs_out.pos_h = mul(g_mat_view, vs_out.pos_h); vs_out.pos_h = mul(g_mat_proj, vs_out.pos_h);
	//vs_out.pos_h = mul(g_mat_proj, mul(g_mat_view, mul(g_mat_world_tri, vs_in.pos_l)));
	
	// matrix wvp = world * view * proj; vs_out.pos_h = mul(vs_in.pos_l, wvp); // wrong * does per-component hadamard product
	
	// Just pass the vertex color into the pixel shader.
	vs_out.vcolor = vs_in.vcolor;
	 
    return vs_out;
}


float4 PS(VS_OUTPUT ps_in) : COLOR {
    return ps_in.vcolor;
	//return float4(1.0f, 1.0f, 0.0f, 1.0f);
}

technique shader_tech {
    pass P0 {
        // Specify the vertex and pixel shader associated with this pass.
        vertexShader = compile vs_2_0 VS();
        pixelShader  = compile ps_2_0 PS();
		
		// Specify the render/device states associated with this pass.
		//FillMode = Wireframe;
    }
}
