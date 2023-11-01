#pragma once

#include "t2_rs_d3d11.h"

class rd3d11_tri_color_ex : public rd3d11  {
public:		

	ID3D11InputLayout* m_input_layout;

	ID3D11Buffer* triangle_m_vb = nullptr;
	ID3D11Buffer* triangle_m_ib = nullptr;		
	int64 tri_num_vertices = 0;
	int64 tri_num_indices = 0;

	gm::mat4 mat_world_tri = gm::mat4::k_identity();

	ID3D11VertexShader* vs_shader = nullptr;
    ID3DBlob* vs_blob = nullptr;
	ID3D11PixelShader* ps_shader = nullptr;
    ID3DBlob* ps_blob = nullptr;

	ID3D11Buffer* cbuffer_wvp = nullptr;

	void cleanup() {
		com_release(cbuffer_wvp);
		com_release(vs_blob);
		com_release(ps_blob);
		com_release(vs_shader);
		com_release(ps_shader);

		com_release(triangle_m_vb);
		com_release(triangle_m_ib);
		com_release(m_input_layout);	
	}
	

	void setup() {	
		set_rs_culling(rs_cull_mode_e::cull_ccw);
		// Set Render Pipeline state.
		//m_device->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW); // default in d3d
		//m_device->SetRenderState(D3DRS_CULLMODE, D3DCULL_CW); // default in OpenGL
		//m_device->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);


		// Load shaders before CreateVertexDeclaration or CreateInputLayout
		//load_shaders_file(RS_SHADER_PATH2("d3d11_vertex_pc.fx"), shader_vs, shader_ps);

		const char* shader_filename = RS_SHADER_PATH2("d3d11_vertex_pc_ex.fx");

		HRESULT hr = 0;
		bool success = false;

		success = d3d11_compile_shader_from_file(shader_filename, "VS", "vs_5_0", vs_blob);
		hr = m_device->CreateVertexShader(vs_blob->GetBufferPointer(), vs_blob->GetBufferSize(), nullptr, &vs_shader);
		if (FAILED(hr)) { 
			eprintfln("CreateVertexShader failed"); 
			vs_blob->Release(); 
		}

		// Create vertex declaration for expressing the data layout. Conceptually, the vertex declaration is a way of 
		// programming the vertex direct memory access (DMA) and the tessellator engine of the graphics pipe.
		D3D11_INPUT_ELEMENT_DESC vertex_elements_pc[] = {
			{"POSITION",	0, DXGI_FORMAT_R32G32B32_FLOAT,		0, 0,  D3D11_INPUT_PER_VERTEX_DATA, 0},
			{"COLOR",		0, DXGI_FORMAT_R32G32B32A32_FLOAT,	0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0},
		};
		UINT num_vertex_elements_pc = sdf::arr_cap(vertex_elements_pc);
		// After shader init.
		// Create the input layout.
		m_device->CreateInputLayout(vertex_elements_pc, num_vertex_elements_pc, vs_blob->GetBufferPointer(), vs_blob->GetBufferSize(), &m_input_layout);		



		success = d3d11_compile_shader_from_file(shader_filename, "PS", "ps_5_0", ps_blob);
		hr = m_device->CreatePixelShader(ps_blob->GetBufferPointer(), ps_blob->GetBufferSize(), nullptr, &ps_shader);		
		if (FAILED(hr)) { 
			eprintfln("CreatePixelShader failed"); 
			ps_blob->Release(); 
		}


		
		// Define data to load. Can be loaded from file also.
		vertex_pc triangle_arr_vert_c_d3d[] = {
			{-1.0, 0.0, 0.9,	1.0, 0.0, 0.0, 1.0}, // bottom-left red
			{ 0.0, 1.0, 0.9,	0.0, 1.0, 0.0, 1.0}, // top green
			{ 1.0, 0.0, 0.9,	0.0, 0.0, 1.0, 1.0}, // bottom-right blue
		};
		uint triangle_arr_ind_d3d[] = {
			0, 1, 2,
		};
		tri_num_vertices = sdf::arr_cap(triangle_arr_vert_c_d3d);
		tri_num_indices = sdf::arr_cap(triangle_arr_ind_d3d);		

		// Load data to vector.
		sdr::vector<vertex_pc> vertices_vec;
		sdr::vector<uint> indices_vec;
		vertices_vec.resize(tri_num_vertices);
		sdf::mem_copy(vertices_vec.data(), triangle_arr_vert_c_d3d, tri_num_vertices);
		indices_vec.resize(tri_num_indices);
		sdf::mem_copy(indices_vec.data(), triangle_arr_ind_d3d, tri_num_indices);


		// Create the vertex buffer. 
		UINT vb_size_bytes = vertices_vec.size() * sizeof(vertex_pc);	
		CD3D11_BUFFER_DESC vbd(vb_size_bytes, D3D11_BIND_VERTEX_BUFFER);
		D3D11_SUBRESOURCE_DATA vInitData = {};
		vInitData.pSysMem = vertices_vec.data();
		m_device->CreateBuffer(&vbd, &vInitData, &triangle_m_vb);

		// Enable if using index buffers.
		// Create the index buffer. 
		UINT ib_size_bytes = indices_vec.size() * sizeof(uint);
		CD3D11_BUFFER_DESC ibd(ib_size_bytes, D3D11_BIND_INDEX_BUFFER);
		D3D11_SUBRESOURCE_DATA iInitData = {};
		iInitData.pSysMem = indices_vec.data();
		m_device->CreateBuffer(&ibd, &iInitData, &triangle_m_ib);	

		vec_clear_memory(vertices_vec);
		vec_clear_memory(indices_vec);

		// Set primitive topology
        m_device_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
		

		// Create the constant buffer
		// Assert that the constant buffer remains 16-byte aligned.
		static_assert((sizeof(cb_struct_mat4_ex_s) % 16) == 0, "Constant Buffer size must be 16-byte aligned");
		UINT cb_size_bytes = sizeof(cb_struct_mat4_ex_s);
		D3D11_BUFFER_DESC cbd = {};
		cbd.ByteWidth = cb_size_bytes;
	    cbd.Usage = D3D11_USAGE_DEFAULT;	    
	    cbd.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	    cbd.CPUAccessFlags = 0;
		cbd.MiscFlags = 0;
		cbd.StructureByteStride = 0;
        m_device->CreateBuffer(&cbd, nullptr, &cbuffer_wvp);        

		//// Create the constant buffer
		//// Assert that the constant buffer remains 16-byte aligned.
		//static_assert((sizeof(cb_struct_mat4_ex) % 16) == 0, "Constant Buffer size must be 16-byte aligned");
		//UINT cb_size_bytes = sizeof(cb_struct_mat4_ex);
		//CD3D11_BUFFER_DESC cbd(cb_size_bytes, D3D11_BIND_CONSTANT_BUFFER);
		//m_device->CreateBuffer(&cbd, nullptr, &cb_wvp.data);
		
		//----------------------------------------
		// World Matrix
		mat_world_tri = gm::mat4_translation(gm::vec3(1.25f, 0.0f, 0.0f));
		//mat_world_tri = gm::mat4_scaling(gm::vec3(2.0, 1.0, 1.0));
		// Rotating on x axis, since x axis is same while y or z can be up.
		//mat_world_tri = gm::mat4_rotation_x(mf::deg_to_rad<float>(30));

		// View Matrix
		// Position and aim the camera.
		gm::vec3 position(0.0f, 0.0f, -2.0f);
		gm::vec3 target(0.0f, 0.0f, 0.0f);
		gm::vec3 up(0.0f, 1.0f, 0.0f);
		mat_view = gm::mat4_look_at_lh(position, target, up);		

		// Projection Matrix
		mat_proj = gm::mat4_perspective_fov_lh(
								mf::deg_to_rad<float>(100), //yfov
								1.777777,	//(16/9) //(float)800 / (float)600,
								0.9f,		//1.0f,
								1000.0f);		
	}

	int mode = 2;

	void render(float dt) {
		clear_render_target(gm::color4(0.2, 0.2, 0.2, 1.0));
		clear_depth_stencil(true, true, 1.0f, 0);
		m_device_context->OMSetRenderTargets(1, &m_render_target, m_depth_stencil);
		// mFont->DrawText changes default states, input layout and primitive topology. Restore them.
		//reset_default_states();

		m_device_context->IASetInputLayout(m_input_layout);

		// Set vertex buffer
		UINT stride = sizeof(vertex_pc);
		UINT offset = 0;
		m_device_context->IASetVertexBuffers(0, 1, &triangle_m_vb, &stride, &offset);
        // Enable if using index buffers.
		// Set index buffer
        m_device_context->IASetIndexBuffer(triangle_m_ib, DXGI_FORMAT_R32_UINT, 0);

		// You can transpose all matrices and vectors involved and multiply them in reverse order for column matrices (reversing 
		// the order is a result of the identity (A*B)^T = B^T * A^T). This gives transposed but otherwise identical results.
		//m_wvp = mat_world_tri * mat_view * mat_proj;
		//gl_shader_set_mat4_by_name(shaderProgram, "g_wvp", 1, GL_FALSE, m_wvp.data());		
		//output.pos = mul(pos, wvp); in shader column major
		//m_wvp_t = gm::mat4_transpose(m_world * m_view * m_proj); 
		//output.pos = mul(wvp, pos); in shader row major //no transpose needed
		// The D3D9/D3D10/D3D11 HLSL mul call interprets matrix arguments as column-major in all cases. 
		// The ID3DXBaseEffect::SetMatrix() call interprets its matrix argument as row-major, 
		// and transposes behind the scenes to HLSL mul's expected column-major order.
		// If column major matrices are used then transpose is not needed for mul(pos, wvp) in shader.
		gm::mat4 mat_wvp_temp = mat_world_tri * mat_view * mat_proj;
		gm::mat4 mat_wvp_temp_t;

		if (mode == 3) {
			mat_wvp_temp_t = mat_wvp_temp;
		} else if (mode == 4) {
			mat_wvp_temp_t = gm::mat4_transpose(mat_wvp_temp);
		}

		// Upload mat_wvp_temp_t to shader by constant buffer cb_wvp by putting it in struct cbs_mat4_wvp.
		cb_struct_mat4_ex_s cbs_mat4_wvp = {};
		cbs_mat4_wvp.wvp = mat_wvp_temp_t;

		if (mode == 1) {
			cbs_mat4_wvp.W = mat_world_tri;
			cbs_mat4_wvp.V = mat_view;
			cbs_mat4_wvp.P = mat_proj;
		} else if (mode == 2) {
			cbs_mat4_wvp.W = gm::mat4_transpose(mat_world_tri);
			cbs_mat4_wvp.V = gm::mat4_transpose(mat_view);
			cbs_mat4_wvp.P = gm::mat4_transpose(mat_proj);
			// In shader:
			// Transposed first before sending to shader because HLSL expects data in column major order.
			// HLSL mul always expects matrices to be stored in column-major order. 
			// You can use a compiler directive to tell it to use row-major order in D3D11.
			// After that row major matrix math is done in shader by below line.
			// vp*w*v*p				
			//vs_out.pos_h = mul(mul(mul(vs_in.pos_l, W), V), P);
			// or vs_out.pos_h = mul(g_wvp, vs_in.pos_l); // vp*wvp
			// If not transposed shader will have matrices in column major order
			// and col major matrix math is done in shader.
			// p*v*w*vp
			// vs_out.pos_h = mul(mul(mul(P, V), W), vs_in.pos_l);
			// or vs_out.pos_h = mul(vs_in.pos_l, g_wvp); // wvp*vp
		}

		cbs_mat4_wvp.mode = mode;

		m_device_context->UpdateSubresource(cbuffer_wvp, 0, nullptr, &cbs_mat4_wvp, 0, 0);

		// Set shaders and constant buffers
		m_device_context->VSSetShader(vs_shader, nullptr, 0);				
		m_device_context->PSSetShader(ps_shader, nullptr, 0);
		m_device_context->VSSetConstantBuffers(0, 1, &cbuffer_wvp);

		// If only vertex buffer then, tri_num_indices is equal to num_vertices.
		//m_device_context->Draw(tri_num_indices, 0);
		m_device_context->DrawIndexed(tri_num_indices, 0, 0);	
	}	
};

