#pragma once

#include "base_gmath.h"


// Standard colors (Red/Green/Blue/Alpha)
// RGB Color Codes (rapidtables.com/web/color/RGB_Color.html)
// en.wikipedia.org/wiki/X11_color_names
// github.com/floooh/sokol/blob/master/util/sokol_color.h


namespace gm
{

namespace cc2
{
inline const color4 lt_grey = { 0.2f, 0.2f, 0.2f, 1.0f };
}


namespace cc
{

// Alice Blue { R:240, G:248, B:255, A:255 }, { 0xF0F8FFFF } 
inline const color4 alice_blue = { 0.941176471f, 0.972549020f, 1.000000000f, 1.000000000f };
// Antique White { R:250, G:235, B:215, A:255 }, { 0xFAEBD7FF } 
inline const color4 antique_white = { 0.980392157f, 0.921568627f, 0.843137255f, 1.000000000f };
// Aqua { R:0, G:255, B:255, A:255 }, { 0x00FFFFFF } 
inline const color4 aqua = { 0.000000000f, 1.000000000f, 1.000000000f, 1.000000000f };
// Aquamarine { R:127, G:255, B:212, A:255 }, { 0x7FFFD4FF } 
inline const color4 aquamarine = { 0.498039216f, 1.000000000f, 0.831372549f, 1.000000000f };
// Azure { R:240, G:255, B:255, A:255 }, { 0xF0FFFFFF } 
inline const color4 azure = { 0.941176471f, 1.000000000f, 1.000000000f, 1.000000000f };
// Beige { R:245, G:245, B:220, A:255 }, { 0xF5F5DCFF } 
inline const color4 beige = { 0.960784314f, 0.960784314f, 0.862745098f, 1.000000000f };
// Bisque { R:255, G:228, B:196, A:255 }, { 0xFFE4C4FF } 
inline const color4 bisque = { 1.000000000f, 0.894117647f, 0.768627451f, 1.000000000f };
// Black { R:0, G:0, B:0, A:255 }, { 0x000000FF } 
inline const color4 black = { 0.000000000f, 0.000000000f, 0.000000000f, 1.000000000f };
// Blanched Almond { R:255, G:235, B:205, A:255 }, { 0xFFEBCDFF } 
inline const color4 blanched_almond = { 1.000000000f, 0.921568627f, 0.803921569f, 1.000000000f };
// Blue { R:0, G:0, B:255, A:255 }, { 0x0000FFFF } 
inline const color4 blue = { 0.000000000f, 0.000000000f, 1.000000000f, 1.000000000f };
// Blue Violet { R:138, G:43, B:226, A:255 }, { 0x8A2BE2FF } 
inline const color4 blue_violet = { 0.541176471f, 0.168627451f, 0.886274510f, 1.000000000f };
// Brown { R:165, G:42, B:42, A:255 }, { 0xA52A2AFF } 
inline const color4 brown = { 0.647058824f, 0.164705882f, 0.164705882f, 1.000000000f };
// Burlywood { R:222, G:184, B:135, A:255 }, { 0xDEB887FF } 
inline const color4 burlywood = { 0.870588235f, 0.721568627f, 0.529411765f, 1.000000000f };
// Cadet Blue { R:95, G:158, B:160, A:255 }, { 0x5F9EA0FF } 
inline const color4 cadet_blue = { 0.372549020f, 0.619607843f, 0.627450980f, 1.000000000f };
// Chartreuse { R:127, G:255, B:0, A:255 }, { 0x7FFF00FF } 
inline const color4 chartreuse = { 0.498039216f, 1.000000000f, 0.000000000f, 1.000000000f };
// Chocolate { R:210, G:105, B:30, A:255 }, { 0xD2691EFF } 
inline const color4 chocolate = { 0.823529412f, 0.411764706f, 0.117647059f, 1.000000000f };
// Coral { R:255, G:127, B:80, A:255 }, { 0xFF7F50FF } 
inline const color4 coral = { 1.000000000f, 0.498039216f, 0.313725490f, 1.000000000f };
// Cornflower Blue { R:100, G:149, B:237, A:255 }, { 0x6495EDFF } 
inline const color4 cornflower_blue = { 0.392156863f, 0.584313725f, 0.929411765f, 1.000000000f };
// Cornsilk { R:255, G:248, B:220, A:255 }, { 0xFFF8DCFF } 
inline const color4 cornsilk = { 1.000000000f, 0.972549020f, 0.862745098f, 1.000000000f };
// Crimson { R:220, G:20, B:60, A:255 }, { 0xDC143CFF } 
inline const color4 crimson = { 0.862745098f, 0.078431373f, 0.235294118f, 1.000000000f };
// Cyan { R:0, G:255, B:255, A:255 }, { 0x00FFFFFF } 
inline const color4 cyan = { 0.000000000f, 1.000000000f, 1.000000000f, 1.000000000f };
// Dark Blue { R:0, G:0, B:139, A:255 }, { 0x00008BFF } 
inline const color4 dark_blue = { 0.000000000f, 0.000000000f, 0.545098039f, 1.000000000f };
// Dark Cyan { R:0, G:139, B:139, A:255 }, { 0x008B8BFF } 
inline const color4 dark_cyan = { 0.000000000f, 0.545098039f, 0.545098039f, 1.000000000f };
// Dark Goldenrod { R:184, G:134, B:11, A:255 }, { 0xB8860BFF } 
inline const color4 dark_goldenrod = { 0.721568627f, 0.525490196f, 0.043137255f, 1.000000000f };
// Dark Gray { R:169, G:169, B:169, A:255 }, { 0xA9A9A9FF } 
inline const color4 dark_gray = { 0.662745098f, 0.662745098f, 0.662745098f, 1.000000000f };
// Dark Green { R:0, G:100, B:0, A:255 }, { 0x006400FF } 
inline const color4 dark_green = { 0.000000000f, 0.392156863f, 0.000000000f, 1.000000000f };
// Dark Khaki { R:189, G:183, B:107, A:255 }, { 0xBDB76BFF } 
inline const color4 dark_khaki = { 0.741176471f, 0.717647059f, 0.419607843f, 1.000000000f };
// Dark Magenta { R:139, G:0, B:139, A:255 }, { 0x8B008BFF } 
inline const color4 dark_magenta = { 0.545098039f, 0.000000000f, 0.545098039f, 1.000000000f };
// Dark Olive Green { R:85, G:107, B:47, A:255 }, { 0x556B2FFF } 
inline const color4 dark_olive_green = { 0.333333333f, 0.419607843f, 0.184313725f, 1.000000000f };
// Dark Orange { R:255, G:140, B:0, A:255 }, { 0xFF8C00FF } 
inline const color4 dark_orange = { 1.000000000f, 0.549019608f, 0.000000000f, 1.000000000f };
// Dark Orchid { R:153, G:50, B:204, A:255 }, { 0x9932CCFF } 
inline const color4 dark_orchid = { 0.600000000f, 0.196078431f, 0.800000000f, 1.000000000f };
// Dark Red { R:139, G:0, B:0, A:255 }, { 0x8B0000FF } 
inline const color4 dark_red = { 0.545098039f, 0.000000000f, 0.000000000f, 1.000000000f };
// Dark Salmon { R:233, G:150, B:122, A:255 }, { 0xE9967AFF } 
inline const color4 dark_salmon = { 0.913725490f, 0.588235294f, 0.478431373f, 1.000000000f };
// Dark Sea Green { R:143, G:188, B:143, A:255 }, { 0x8FBC8FFF } 
inline const color4 dark_sea_green = { 0.560784314f, 0.737254902f, 0.560784314f, 1.000000000f };
// Dark Slate Blue { R:72, G:61, B:139, A:255 }, { 0x483D8BFF } 
inline const color4 dark_slate_blue = { 0.282352941f, 0.239215686f, 0.545098039f, 1.000000000f };
// Dark Slate Gray { R:47, G:79, B:79, A:255 }, { 0x2F4F4FFF } 
inline const color4 dark_slate_gray = { 0.184313725f, 0.309803922f, 0.309803922f, 1.000000000f };
// Dark Turquoise { R:0, G:206, B:209, A:255 }, { 0x00CED1FF } 
inline const color4 dark_turquoise = { 0.000000000f, 0.807843137f, 0.819607843f, 1.000000000f };
// Dark Violet { R:148, G:0, B:211, A:255 }, { 0x9400D3FF } 
inline const color4 dark_violet = { 0.580392157f, 0.000000000f, 0.827450980f, 1.000000000f };
// Deep Pink { R:255, G:20, B:147, A:255 }, { 0xFF1493FF } 
inline const color4 deep_pink = { 1.000000000f, 0.078431373f, 0.576470588f, 1.000000000f };
// Deep Sky Blue { R:0, G:191, B:255, A:255 }, { 0x00BFFFFF } 
inline const color4 deep_sky_blue = { 0.000000000f, 0.749019608f, 1.000000000f, 1.000000000f };
// Dim Gray { R:105, G:105, B:105, A:255 }, { 0x696969FF } 
inline const color4 dim_gray = { 0.411764706f, 0.411764706f, 0.411764706f, 1.000000000f };
// Dodger Blue { R:30, G:144, B:255, A:255 }, { 0x1E90FFFF } 
inline const color4 dodger_blue = { 0.117647059f, 0.564705882f, 1.000000000f, 1.000000000f };
// Firebrick { R:178, G:34, B:34, A:255 }, { 0xB22222FF } 
inline const color4 firebrick = { 0.698039216f, 0.133333333f, 0.133333333f, 1.000000000f };
// Floral White { R:255, G:250, B:240, A:255 }, { 0xFFFAF0FF } 
inline const color4 floral_white = { 1.000000000f, 0.980392157f, 0.941176471f, 1.000000000f };
// Forest Green { R:34, G:139, B:34, A:255 }, { 0x228B22FF } 
inline const color4 forest_green = { 0.133333333f, 0.545098039f, 0.133333333f, 1.000000000f };
// Fuchsia { R:255, G:0, B:255, A:255 }, { 0xFF00FFFF } 
inline const color4 fuchsia = { 1.000000000f, 0.000000000f, 1.000000000f, 1.000000000f };
// Gainsboro { R:220, G:220, B:220, A:255 }, { 0xDCDCDCFF } 
inline const color4 gainsboro = { 0.862745098f, 0.862745098f, 0.862745098f, 1.000000000f };
// Ghost White { R:248, G:248, B:255, A:255 }, { 0xF8F8FFFF } 
inline const color4 ghost_white = { 0.972549020f, 0.972549020f, 1.000000000f, 1.000000000f };
// Gold { R:255, G:215, B:0, A:255 }, { 0xFFD700FF } 
inline const color4 gold = { 1.000000000f, 0.843137255f, 0.000000000f, 1.000000000f };
// Goldenrod { R:218, G:165, B:32, A:255 }, { 0xDAA520FF } 
inline const color4 goldenrod = { 0.854901961f, 0.647058824f, 0.125490196f, 1.000000000f };
// Gray { R:190, G:190, B:190, A:255 }, { 0xBEBEBEFF } 
inline const color4 gray = { 0.745098039f, 0.745098039f, 0.745098039f, 1.000000000f };
// Web Gray { R:128, G:128, B:128, A:255 }, { 0x808080FF } 
inline const color4 web_gray = { 0.501960784f, 0.501960784f, 0.501960784f, 1.000000000f };
// Green { R:0, G:255, B:0, A:255 }, { 0x00FF00FF } 
inline const color4 green = { 0.000000000f, 1.000000000f, 0.000000000f, 1.000000000f };
// Web Green { R:0, G:128, B:0, A:255 }, { 0x008000FF } 
inline const color4 web_green = { 0.000000000f, 0.501960784f, 0.000000000f, 1.000000000f };
// Green Yellow { R:173, G:255, B:47, A:255 }, { 0xADFF2FFF } 
inline const color4 green_yellow = { 0.678431373f, 1.000000000f, 0.184313725f, 1.000000000f };
// Honeydew { R:240, G:255, B:240, A:255 }, { 0xF0FFF0FF } 
inline const color4 honeydew = { 0.941176471f, 1.000000000f, 0.941176471f, 1.000000000f };
// Hot Pink { R:255, G:105, B:180, A:255 }, { 0xFF69B4FF } 
inline const color4 hot_pink = { 1.000000000f, 0.411764706f, 0.705882353f, 1.000000000f };
// Indian Red { R:205, G:92, B:92, A:255 }, { 0xCD5C5CFF } 
inline const color4 indian_red = { 0.803921569f, 0.360784314f, 0.360784314f, 1.000000000f };
// Indigo { R:75, G:0, B:130, A:255 }, { 0x4B0082FF } 
inline const color4 indigo = { 0.294117647f, 0.000000000f, 0.509803922f, 1.000000000f };
// Ivory { R:255, G:255, B:240, A:255 }, { 0xFFFFF0FF } 
inline const color4 ivory = { 1.000000000f, 1.000000000f, 0.941176471f, 1.000000000f };
// Khaki { R:240, G:230, B:140, A:255 }, { 0xF0E68CFF } 
inline const color4 khaki = { 0.941176471f, 0.901960784f, 0.549019608f, 1.000000000f };
// Lavender { R:230, G:230, B:250, A:255 }, { 0xE6E6FAFF } 
inline const color4 lavender = { 0.901960784f, 0.901960784f, 0.980392157f, 1.000000000f };
// Lavender Blush { R:255, G:240, B:245, A:255 }, { 0xFFF0F5FF } 
inline const color4 lavender_blush = { 1.000000000f, 0.941176471f, 0.960784314f, 1.000000000f };
// Lawn Green { R:124, G:252, B:0, A:255 }, { 0x7CFC00FF } 
inline const color4 lawn_green = { 0.486274510f, 0.988235294f, 0.000000000f, 1.000000000f };
// Lemon Chiffon { R:255, G:250, B:205, A:255 }, { 0xFFFACDFF } 
inline const color4 lemon_chiffon = { 1.000000000f, 0.980392157f, 0.803921569f, 1.000000000f };
// Light Blue { R:173, G:216, B:230, A:255 }, { 0xADD8E6FF } 
inline const color4 light_blue = { 0.678431373f, 0.847058824f, 0.901960784f, 1.000000000f };
// Light Coral { R:240, G:128, B:128, A:255 }, { 0xF08080FF } 
inline const color4 light_coral = { 0.941176471f, 0.501960784f, 0.501960784f, 1.000000000f };
// Light Cyan { R:224, G:255, B:255, A:255 }, { 0xE0FFFFFF } 
inline const color4 light_cyan = { 0.878431373f, 1.000000000f, 1.000000000f, 1.000000000f };
// Light Goldenrod { R:250, G:250, B:210, A:255 }, { 0xFAFAD2FF } 
inline const color4 light_goldenrod = { 0.980392157f, 0.980392157f, 0.823529412f, 1.000000000f };
// Light Gray { R:211, G:211, B:211, A:255 }, { 0xD3D3D3FF } 
inline const color4 light_gray = { 0.827450980f, 0.827450980f, 0.827450980f, 1.000000000f };
// Light Green { R:144, G:238, B:144, A:255 }, { 0x90EE90FF } 
inline const color4 light_green = { 0.564705882f, 0.933333333f, 0.564705882f, 1.000000000f };
// Light Pink { R:255, G:182, B:193, A:255 }, { 0xFFB6C1FF } 
inline const color4 light_pink = { 1.000000000f, 0.713725490f, 0.756862745f, 1.000000000f };
// Light Salmon { R:255, G:160, B:122, A:255 }, { 0xFFA07AFF } 
inline const color4 light_salmon = { 1.000000000f, 0.627450980f, 0.478431373f, 1.000000000f };
// Light Sea Green { R:32, G:178, B:170, A:255 }, { 0x20B2AAFF } 
inline const color4 light_sea_green = { 0.125490196f, 0.698039216f, 0.666666667f, 1.000000000f };
// Light Sky Blue { R:135, G:206, B:250, A:255 }, { 0x87CEFAFF } 
inline const color4 light_sky_blue = { 0.529411765f, 0.807843137f, 0.980392157f, 1.000000000f };
// Light Slate Gray { R:119, G:136, B:153, A:255 }, { 0x778899FF } 
inline const color4 light_slate_gray = { 0.466666667f, 0.533333333f, 0.600000000f, 1.000000000f };
// Light Steel Blue { R:176, G:196, B:222, A:255 }, { 0xB0C4DEFF } 
inline const color4 light_steel_blue = { 0.690196078f, 0.768627451f, 0.870588235f, 1.000000000f };
// Light Yellow { R:255, G:255, B:224, A:255 }, { 0xFFFFE0FF } 
inline const color4 light_yellow = { 1.000000000f, 1.000000000f, 0.878431373f, 1.000000000f };
// Lime { R:0, G:255, B:0, A:255 }, { 0x00FF00FF } 
inline const color4 lime = { 0.000000000f, 1.000000000f, 0.000000000f, 1.000000000f };
// Lime Green { R:50, G:205, B:50, A:255 }, { 0x32CD32FF } 
inline const color4 lime_green = { 0.196078431f, 0.803921569f, 0.196078431f, 1.000000000f };
// Linen { R:250, G:240, B:230, A:255 }, { 0xFAF0E6FF } 
inline const color4 linen = { 0.980392157f, 0.941176471f, 0.901960784f, 1.000000000f };
// Magenta { R:255, G:0, B:255, A:255 }, { 0xFF00FFFF } 
inline const color4 magenta = { 1.000000000f, 0.000000000f, 1.000000000f, 1.000000000f };
// Maroon { R:176, G:48, B:96, A:255 }, { 0xB03060FF } 
inline const color4 maroon = { 0.690196078f, 0.188235294f, 0.376470588f, 1.000000000f };
// Web Maroon { R:128, G:0, B:0, A:255 }, { 0x800000FF } 
inline const color4 web_maroon = { 0.501960784f, 0.000000000f, 0.000000000f, 1.000000000f };
// Medium Aquamarine { R:102, G:205, B:170, A:255 }, { 0x66CDAAFF } 
inline const color4 medium_aquamarine = { 0.400000000f, 0.803921569f, 0.666666667f, 1.000000000f };
// Medium Blue { R:0, G:0, B:205, A:255 }, { 0x0000CDFF } 
inline const color4 medium_blue = { 0.000000000f, 0.000000000f, 0.803921569f, 1.000000000f };
// Medium Orchid { R:186, G:85, B:211, A:255 }, { 0xBA55D3FF } 
inline const color4 medium_orchid = { 0.729411765f, 0.333333333f, 0.827450980f, 1.000000000f };
// Medium Purple { R:147, G:112, B:219, A:255 }, { 0x9370DBFF } 
inline const color4 medium_purple = { 0.576470588f, 0.439215686f, 0.858823529f, 1.000000000f };
// Medium Sea Green { R:60, G:179, B:113, A:255 }, { 0x3CB371FF } 
inline const color4 medium_sea_green = { 0.235294118f, 0.701960784f, 0.443137255f, 1.000000000f };
// Medium Slate Blue { R:123, G:104, B:238, A:255 }, { 0x7B68EEFF } 
inline const color4 medium_slate_blue = { 0.482352941f, 0.407843137f, 0.933333333f, 1.000000000f };
// Medium Spring Green { R:0, G:250, B:154, A:255 }, { 0x00FA9AFF } 
inline const color4 medium_spring_green = { 0.000000000f, 0.980392157f, 0.603921569f, 1.000000000f };
// Medium Turquoise { R:72, G:209, B:204, A:255 }, { 0x48D1CCFF } 
inline const color4 medium_turquoise = { 0.282352941f, 0.819607843f, 0.800000000f, 1.000000000f };
// Medium Violet Red { R:199, G:21, B:133, A:255 }, { 0xC71585FF } 
inline const color4 medium_violet_red = { 0.780392157f, 0.082352941f, 0.521568627f, 1.000000000f };
// Midnight Blue { R:25, G:25, B:112, A:255 }, { 0x191970FF } 
inline const color4 midnight_blue = { 0.098039216f, 0.098039216f, 0.439215686f, 1.000000000f };
// Mint Cream { R:245, G:255, B:250, A:255 }, { 0xF5FFFAFF } 
inline const color4 mint_cream = { 0.960784314f, 1.000000000f, 0.980392157f, 1.000000000f };
// Misty Rose { R:255, G:228, B:225, A:255 }, { 0xFFE4E1FF } 
inline const color4 misty_rose = { 1.000000000f, 0.894117647f, 0.882352941f, 1.000000000f };
// Moccasin { R:255, G:228, B:181, A:255 }, { 0xFFE4B5FF } 
inline const color4 moccasin = { 1.000000000f, 0.894117647f, 0.709803922f, 1.000000000f };
// Navajo White { R:255, G:222, B:173, A:255 }, { 0xFFDEADFF } 
inline const color4 navajo_white = { 1.000000000f, 0.870588235f, 0.678431373f, 1.000000000f };
// Navy Blue { R:0, G:0, B:128, A:255 }, { 0x000080FF } 
inline const color4 navy_blue = { 0.000000000f, 0.000000000f, 0.501960784f, 1.000000000f };
// Old Lace { R:253, G:245, B:230, A:255 }, { 0xFDF5E6FF } 
inline const color4 old_lace = { 0.992156863f, 0.960784314f, 0.901960784f, 1.000000000f };
// Olive { R:128, G:128, B:0, A:255 }, { 0x808000FF } 
inline const color4 olive = { 0.501960784f, 0.501960784f, 0.000000000f, 1.000000000f };
// Olive Drab { R:107, G:142, B:35, A:255 }, { 0x6B8E23FF } 
inline const color4 olive_drab = { 0.419607843f, 0.556862745f, 0.137254902f, 1.000000000f };
// Orange { R:255, G:165, B:0, A:255 }, { 0xFFA500FF } 
inline const color4 orange = { 1.000000000f, 0.647058824f, 0.000000000f, 1.000000000f };
// Orange Red { R:255, G:69, B:0, A:255 }, { 0xFF4500FF } 
inline const color4 orange_red = { 1.000000000f, 0.270588235f, 0.000000000f, 1.000000000f };
// Orchid { R:218, G:112, B:214, A:255 }, { 0xDA70D6FF } 
inline const color4 orchid = { 0.854901961f, 0.439215686f, 0.839215686f, 1.000000000f };
// Pale Goldenrod { R:238, G:232, B:170, A:255 }, { 0xEEE8AAFF } 
inline const color4 pale_goldenrod = { 0.933333333f, 0.909803922f, 0.666666667f, 1.000000000f };
// Pale Green { R:152, G:251, B:152, A:255 }, { 0x98FB98FF } 
inline const color4 pale_green = { 0.596078431f, 0.984313725f, 0.596078431f, 1.000000000f };
// Pale Turquoise { R:175, G:238, B:238, A:255 }, { 0xAFEEEEFF } 
inline const color4 pale_turquoise = { 0.686274510f, 0.933333333f, 0.933333333f, 1.000000000f };
// Pale Violet Red { R:219, G:112, B:147, A:255 }, { 0xDB7093FF } 
inline const color4 pale_violet_red = { 0.858823529f, 0.439215686f, 0.576470588f, 1.000000000f };
// Papaya Whip { R:255, G:239, B:213, A:255 }, { 0xFFEFD5FF } 
inline const color4 papaya_whip = { 1.000000000f, 0.937254902f, 0.835294118f, 1.000000000f };
// Peach Puff { R:255, G:218, B:185, A:255 }, { 0xFFDAB9FF } 
inline const color4 peach_puff = { 1.000000000f, 0.854901961f, 0.725490196f, 1.000000000f };
// Peru { R:205, G:133, B:63, A:255 }, { 0xCD853FFF } 
inline const color4 peru = { 0.803921569f, 0.521568627f, 0.247058824f, 1.000000000f };
// Pink { R:255, G:192, B:203, A:255 }, { 0xFFC0CBFF } 
inline const color4 pink = { 1.000000000f, 0.752941176f, 0.796078431f, 1.000000000f };
// Plum { R:221, G:160, B:221, A:255 }, { 0xDDA0DDFF } 
inline const color4 plum = { 0.866666667f, 0.627450980f, 0.866666667f, 1.000000000f };
// Powder Blue { R:176, G:224, B:230, A:255 }, { 0xB0E0E6FF } 
inline const color4 powder_blue = { 0.690196078f, 0.878431373f, 0.901960784f, 1.000000000f };
// Purple { R:160, G:32, B:240, A:255 }, { 0xA020F0FF } 
inline const color4 purple = { 0.627450980f, 0.125490196f, 0.941176471f, 1.000000000f };
// Web Purple { R:128, G:0, B:128, A:255 }, { 0x800080FF } 
inline const color4 web_purple = { 0.501960784f, 0.000000000f, 0.501960784f, 1.000000000f };
// Rebecca Purple { R:102, G:51, B:153, A:255 }, { 0x663399FF } 
inline const color4 rebecca_purple = { 0.400000000f, 0.200000000f, 0.600000000f, 1.000000000f };
// Red { R:255, G:0, B:0, A:255 }, { 0xFF0000FF } 
inline const color4 red = { 1.000000000f, 0.000000000f, 0.000000000f, 1.000000000f };
// Rosy Brown { R:188, G:143, B:143, A:255 }, { 0xBC8F8FFF } 
inline const color4 rosy_brown = { 0.737254902f, 0.560784314f, 0.560784314f, 1.000000000f };
// Royal Blue { R:65, G:105, B:225, A:255 }, { 0x4169E1FF } 
inline const color4 royal_blue = { 0.254901961f, 0.411764706f, 0.882352941f, 1.000000000f };
// Saddle Brown { R:139, G:69, B:19, A:255 }, { 0x8B4513FF } 
inline const color4 saddle_brown = { 0.545098039f, 0.270588235f, 0.074509804f, 1.000000000f };
// Salmon { R:250, G:128, B:114, A:255 }, { 0xFA8072FF } 
inline const color4 salmon = { 0.980392157f, 0.501960784f, 0.447058824f, 1.000000000f };
// Sandy Brown { R:244, G:164, B:96, A:255 }, { 0xF4A460FF } 
inline const color4 sandy_brown = { 0.956862745f, 0.643137255f, 0.376470588f, 1.000000000f };
// Sea Green { R:46, G:139, B:87, A:255 }, { 0x2E8B57FF } 
inline const color4 sea_green = { 0.180392157f, 0.545098039f, 0.341176471f, 1.000000000f };
// Seashell { R:255, G:245, B:238, A:255 }, { 0xFFF5EEFF } 
inline const color4 seashell = { 1.000000000f, 0.960784314f, 0.933333333f, 1.000000000f };
// Sienna { R:160, G:82, B:45, A:255 }, { 0xA0522DFF } 
inline const color4 sienna = { 0.627450980f, 0.321568627f, 0.176470588f, 1.000000000f };
// Silver { R:192, G:192, B:192, A:255 }, { 0xC0C0C0FF } 
inline const color4 silver = { 0.752941176f, 0.752941176f, 0.752941176f, 1.000000000f };
// Sky Blue { R:135, G:206, B:235, A:255 }, { 0x87CEEBFF } 
inline const color4 sky_blue = { 0.529411765f, 0.807843137f, 0.921568627f, 1.000000000f };
// Slate Blue { R:106, G:90, B:205, A:255 }, { 0x6A5ACDFF } 
inline const color4 slate_blue = { 0.415686275f, 0.352941176f, 0.803921569f, 1.000000000f };
// Slate Gray { R:112, G:128, B:144, A:255 }, { 0x708090FF } 
inline const color4 slate_gray = { 0.439215686f, 0.501960784f, 0.564705882f, 1.000000000f };
// Snow { R:255, G:250, B:250, A:255 }, { 0xFFFAFAFF } 
inline const color4 snow = { 1.000000000f, 0.980392157f, 0.980392157f, 1.000000000f };
// Spring Green { R:0, G:255, B:127, A:255 }, { 0x00FF7FFF } 
inline const color4 spring_green = { 0.000000000f, 1.000000000f, 0.498039216f, 1.000000000f };
// Steel Blue { R:70, G:130, B:180, A:255 }, { 0x4682B4FF } 
inline const color4 steel_blue = { 0.274509804f, 0.509803922f, 0.705882353f, 1.000000000f };
// Tan { R:210, G:180, B:140, A:255 }, { 0xD2B48CFF } 
inline const color4 tan = { 0.823529412f, 0.705882353f, 0.549019608f, 1.000000000f };
// Teal { R:0, G:128, B:128, A:255 }, { 0x008080FF } 
inline const color4 teal = { 0.000000000f, 0.501960784f, 0.501960784f, 1.000000000f };
// Thistle { R:216, G:191, B:216, A:255 }, { 0xD8BFD8FF } 
inline const color4 thistle = { 0.847058824f, 0.749019608f, 0.847058824f, 1.000000000f };
// Tomato { R:255, G:99, B:71, A:255 }, { 0xFF6347FF } 
inline const color4 tomato = { 1.000000000f, 0.388235294f, 0.278431373f, 1.000000000f };
// Transparent { R:0, G:0, B:0, A:0 }, { 0x00000000 } 
inline const color4 transparent = { 0.000000000f, 0.000000000f, 0.000000000f, 0.000000000f };
// Turquoise { R:64, G:224, B:208, A:255 }, { 0x40E0D0FF } 
inline const color4 turquoise = { 0.250980392f, 0.878431373f, 0.815686275f, 1.000000000f };
// Violet { R:238, G:130, B:238, A:255 }, { 0xEE82EEFF } 
inline const color4 violet = { 0.933333333f, 0.509803922f, 0.933333333f, 1.000000000f };
// Wheat { R:245, G:222, B:179, A:255 }, { 0xF5DEB3FF } 
inline const color4 wheat = { 0.960784314f, 0.870588235f, 0.701960784f, 1.000000000f };
// White { R:255, G:255, B:255, A:255 }, { 0xFFFFFFFF } 
inline const color4 white = { 1.000000000f, 1.000000000f, 1.000000000f, 1.000000000f };
// White Smoke { R:245, G:245, B:245, A:255 }, { 0xF5F5F5FF } 
inline const color4 white_smoke = { 0.960784314f, 0.960784314f, 0.960784314f, 1.000000000f };
// Yellow { R:255, G:255, B:0, A:255 }, { 0xFFFF00FF } 
inline const color4 yellow = { 1.000000000f, 1.000000000f, 0.000000000f, 1.000000000f };
// Yellow Green { R:154, G:205, B:50, A:255 }, { 0x9ACD32FF } 
inline const color4 yellow_green = { 0.603921569f, 0.803921569f, 0.196078431f, 1.000000000f };


} //cc


} //gm
