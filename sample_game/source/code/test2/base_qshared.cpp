#include "base_qshared.h"


char* k_empty_strz[1] = {'\0'};

char *CopyString( const char *in ) {
	char *out = nullptr;

	if (!in) {
		out = scast<char*>(S_Malloc(1));
		out[0] = '\0';
		return out;	
	}

	const isz src_len = strlen(in);
	out = scast<char*>(S_Malloc(src_len+1));
	strcpy(out, in);
	out[src_len] = '\0';
	return out;	
}
