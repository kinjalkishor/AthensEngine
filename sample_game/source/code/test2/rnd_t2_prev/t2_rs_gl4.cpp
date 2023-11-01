#include "t2_rs_gl4.h"

//============================================
// Utility functions for loading texures
//============================================
//E:/nex/AthensEngine/AscentWars/source/dep
//#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"


void tex_load_data_stb(uint8** out_data, const char* texture_path, int& width, int& height, int& nrChannels, bool flip_vertically) {
	// tell stb_image.h to flip loaded texture's on the y-axis.
	// texture is flipped upside-down. This happens because OpenGL expects the 0.0 coordinate on the y-axis to be on 
	// the bottom side of the image, but images usually have 0.0 at the top of the y-axis. 
	// stb_image.h can flip the y-axis during image loading. Or it can be done in shader also, but better do it once on image loading
	stbi_set_flip_vertically_on_load(flip_vertically); 
	*out_data = stbi_load(texture_path, &width, &height, &nrChannels, 0);
}
void tex_free_data_stb(uint8* data) { stbi_image_free(data); }


//==============================================================================


void gl_load_texture(const char* tex_file_name, bool gamma_correction) {
	bool flip_vertically = false;
	// load image, create texture and generate mipmaps
	uint8* data;
	int width = 0, height = 0;
	int nrChannels = 0; //nrComponents;
	//data = stbi_load(texture_path, &width, &height, &nrChannels, 0);
	tex_load_data_stb(&data, tex_file_name, width, height, nrChannels, flip_vertically);

	if (data) {
		// Without Gamma Correction
		//GLenum format = 0;	//src_rgb, dest_rgb
		//if (nrChannels == 1) { format = GL_RED; }
		//else if (nrChannels == 3) { format = GL_RGB; }
		//else if (nrChannels == 4) { format = GL_RGBA; }
		// all upcoming GL_TEXTURE_2D operations now have effect on this texture object
		//glBindTexture(GL_TEXTURE_2D, texture); 
		//glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);

		// With Gamma Correction
		GLenum internalFormat = 0;
        GLenum dataFormat = 0;
        if (nrChannels == 1) {
            internalFormat  = GL_RED;
			dataFormat = GL_RED;
        } else if (nrChannels == 3) {
            internalFormat = gamma_correction ? GL_SRGB : GL_RGB;
            dataFormat = GL_RGB;
        } else if (nrChannels == 4) {
            internalFormat = gamma_correction ? GL_SRGB_ALPHA : GL_RGBA;
            dataFormat = GL_RGBA;
        }
		
        glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, dataFormat, GL_UNSIGNED_BYTE, data);

		// Generate mipmaps
		glGenerateMipmap(GL_TEXTURE_2D);
		//gl_set_sampler_state(tex_wrapping, min_filter, mag_filter);

		tex_free_data_stb(data);
	} else {
		eprintfln("Failed to load texture: %s", tex_file_name);
    }	
}
