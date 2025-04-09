#pragma once


//==========================================
inline constexpr float k_aspect_16_9 = 1.77777777777777777778;
inline float get_aspect_ratio(float width, float height) { 
    // return 1:1 if height is zero.
    //1:1-1.0, 4:3-1.33, 16:9-1.77, 21:9-2.33
    return (height < 0.0001f) ? 1.0f : (width/height); 
}
