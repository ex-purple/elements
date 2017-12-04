/*=============================================================================
   Copyright (c) 2016-2017 Joel de Guzman

   Distributed under the MIT License [ https://opensource.org/licenses/MIT ]
=============================================================================*/
#if !defined(PHOTON_GUI_LIB_POINT_APRIL_11_2016)
#define PHOTON_GUI_LIB_POINT_APRIL_11_2016

#include <type_traits>

namespace photon
{
   ////////////////////////////////////////////////////////////////////////////
   // Colors
   ////////////////////////////////////////////////////////////////////////////
   struct color
   {
      constexpr color() = default;

      template <typename T>
      constexpr color(T red, T green, T blue, T alpha
                    , typename std::enable_if<std::is_floating_point<T>::value>::type* = 0)
       : red(red), green(green), blue(blue), alpha(alpha)
      {}

      template <typename T>
      constexpr color(T red, T green, T blue, T alpha
                    , typename std::enable_if<std::is_integral<T>::value>::type* = 0)
       : red(red/255.0f), green(green/255.0f), blue(blue/255.0f), alpha(alpha/255.0f)
      {}

      color opacity(float alpha_) const;
      color level(float amount) const;

      float red   = 0.0f;
      float green = 0.0f;
      float blue  = 0.0f;
      float alpha = 0.0f;
   };

   bool operator==(color a, color b);
   bool operator!=(color a, color b);

   ////////////////////////////////////////////////////////////////////////////
   // Inlines
   ////////////////////////////////////////////////////////////////////////////
   inline bool operator==(color a, color b)
   {
      return
         (a.alpha == b.alpha) &&
         (a.red == b.red) &&
         (a.green == b.green) &&
         (a.blue == b.blue)
         ;
   }

   inline bool operator!=(color a, color b)
   {
      return !(a == b);
   }

   inline color color::opacity(float alpha_) const
   {
      return { red, green, blue, alpha_ };
   }

   inline color color::level(float amount) const
   {
      color r = *this;
      r.red    *= amount;
      r.green  *= amount;
      r.blue   *= amount;
      return r;
   }

   ////////////////////////////////////////////////////////////////////////////
   // Common colors
   ////////////////////////////////////////////////////////////////////////////
   namespace colors
   {
      constexpr color alice_blue             { 240, 248, 255, 255 };
      constexpr color antique_white          { 250, 235, 215, 255 };
      constexpr color aquamarine             { 50, 191, 193, 255 };
      constexpr color azure                  { 240, 255, 255, 255 };
      constexpr color beige                  { 245, 245, 220, 255 };
      constexpr color bisque                 { 255, 228, 196, 255 };
      constexpr color black                  { 0, 0, 0, 255 };
      constexpr color blanched_almond        { 255, 235, 205, 255 };
      constexpr color blue                   { 0, 0, 255, 255 };
      constexpr color blue_violet            { 138, 43, 226, 255 };
      constexpr color brown                  { 165, 42, 42, 255 };
      constexpr color burly_wood             { 222, 184, 135, 255 };
      constexpr color cadet_blue             { 95, 146, 158, 255 };
      constexpr color kchartreuse            { 127, 255, 0, 255 };
      constexpr color chocolate              { 210, 105, 30, 255 };
      constexpr color coral                  { 255, 114, 86, 255 };
      constexpr color cornflower_blue        { 34, 34, 152, 255 };
      constexpr color corn_silk              { 255, 248, 220, 255 };
      constexpr color cyan                   { 0, 255, 255, 255 };
      constexpr color dark_goldenrod         { 184, 134, 11, 255 };
      constexpr color dark_green             { 0, 86, 45, 255 };
      constexpr color dark_khaki             { 189, 183, 107, 255 };
      constexpr color dark_olive_green       { 85, 86, 47, 255 };
      constexpr color dark_orange            { 255, 140, 0, 255 };
      constexpr color dark_orchid            { 139, 32, 139, 255 };
      constexpr color dark_salmon            { 233, 150, 122, 255 };
      constexpr color dark_sea_green         { 143, 188, 143, 255 };
      constexpr color dark_slate_blue        { 56, 75, 102, 255 };
      constexpr color dark_slate_gray        { 47, 79, 79, 255 };
      constexpr color dark_turquoise         { 0, 166, 166, 255 };
      constexpr color dark_violet            { 148, 0, 211, 255 };
      constexpr color deep_pink              { 255, 20, 147, 255 };
      constexpr color deep_sky_blue          { 0, 191, 255, 255 };
      constexpr color dim_gray               { 84, 84, 84, 255 };
      constexpr color dodger_blue            { 30, 144, 255, 255 };
      constexpr color firebrick              { 142, 35, 35, 255 };
      constexpr color floral_white           { 255, 250, 240, 255 };
      constexpr color forest_green           { 80, 159, 105, 255 };
      constexpr color gains_boro             { 220, 220, 220, 255 };
      constexpr color ghost_white            { 248, 248, 255, 255 };
      constexpr color gold                   { 218, 170, 0, 255 };
      constexpr color goldenrod              { 239, 223, 132, 255 };
      constexpr color green                  { 0, 255, 0, 255 };
      constexpr color green_yellow           { 173, 255, 47, 255 };
      constexpr color honeydew               { 240, 255, 240, 255 };
      constexpr color hot_pink               { 255, 105, 180, 255 };
      constexpr color indian_red             { 107, 57, 57, 255 };
      constexpr color ivory                  { 255, 255, 240, 255 };
      constexpr color khaki                  { 179, 179, 126, 255 };
      constexpr color lavender               { 230, 230, 250, 255 };
      constexpr color lavender_blush         { 255, 240, 245, 255 };
      constexpr color lawn_green             { 124, 252, 0, 255 };
      constexpr color lemon_chiffon          { 255, 250, 205, 255 };
      constexpr color light_blue             { 176, 226, 255, 255 };
      constexpr color light_coral            { 240, 128, 128, 255 };
      constexpr color light_cyan             { 224, 255, 255, 255 };
      constexpr color light_goldenrod        { 238, 221, 130, 255 };
      constexpr color light_goldenrod_yellow { 250, 250, 210, 255 };
      constexpr color light_gray             { 168, 168, 168, 255 };
      constexpr color light_pink             { 255, 182, 193, 255 };
      constexpr color light_salmon           { 255, 160, 122, 255 };
      constexpr color light_sea_green        { 32, 178, 170, 255 };
      constexpr color light_sky_blue         { 135, 206, 250, 255 };
      constexpr color light_slate_blue       { 132, 112, 255, 255 };
      constexpr color light_slate_gray       { 119, 136, 153, 255 };
      constexpr color light_steel_blue       { 124, 152, 211, 255 };
      constexpr color light_yellow           { 255, 255, 224, 255 };
      constexpr color lime_green             { 0, 175, 20, 255 };
      constexpr color linen                  { 250, 240, 230, 255 };
      constexpr color magenta                { 255, 0, 255, 255 };
      constexpr color maroon                 { 143, 0, 82, 255 };
      constexpr color medium_aquamarine      { 0, 147, 143, 255 };
      constexpr color medium_blue            { 50, 50, 204, 255 };
      constexpr color medium_forest_green    { 50, 129, 75, 255 };
      constexpr color medium_goldenrod       { 209, 193, 102, 255 };
      constexpr color medium_orchid          { 189, 82, 189, 255 };
      constexpr color medium_purple          { 147, 112, 219, 255 };
      constexpr color medium_sea_green       { 52, 119, 102, 255 };
      constexpr color medium_slate_blue      { 106, 106, 141, 255 };
      constexpr color medium_spring_green    { 35, 142, 35, 255 };
      constexpr color medium_turquoise       { 0, 210, 210, 255 };
      constexpr color medium_violet_red      { 213, 32, 121, 255 };
      constexpr color midnight_blue          { 47, 47, 100, 255 };
      constexpr color mint_cream             { 245, 255, 250, 255 };
      constexpr color misty_rose             { 255, 228, 225, 255 };
      constexpr color moccasin               { 255, 228, 181, 255 };
      constexpr color navajo_white           { 255, 222, 173, 255 };
      constexpr color navy                   { 35, 35, 117, 255 };
      constexpr color navy_blue              { 35, 35, 117, 255 };
      constexpr color old_lace               { 253, 245, 230, 255 };
      constexpr color olive_drab             { 107, 142, 35, 255 };
      constexpr color orange                 { 255, 135, 0, 255 };
      constexpr color orange_red             { 255, 69, 0, 255 };
      constexpr color orchid                 { 239, 132, 239, 255 };
      constexpr color pale_goldenrod         { 238, 232, 170, 255 };
      constexpr color pale_green             { 115, 222, 120, 255 };
      constexpr color pale_turquoise         { 175, 238, 238, 255 };
      constexpr color pale_violet_red        { 219, 112, 147, 255 };
      constexpr color papaya_whip            { 255, 239, 213, 255 };
      constexpr color peach_puff             { 255, 218, 185, 255 };
      constexpr color peru                   { 205, 133, 63, 255 };
      constexpr color pink                   { 255, 181, 197, 255 };
      constexpr color plum                   { 197, 72, 155, 255 };
      constexpr color powder_blue            { 176, 224, 230, 255 };
      constexpr color purple                 { 160, 32, 240, 255 };
      constexpr color red                    { 255, 0, 0, 255 };
      constexpr color rosy_brown             { 188, 143, 143, 255 };
      constexpr color royal_blue             { 65, 105, 225, 255 };
      constexpr color saddle_brown           { 139, 69, 19, 255 };
      constexpr color salmon                 { 233, 150, 122, 255 };
      constexpr color sandy_brown            { 244, 164, 96, 255 };
      constexpr color sea_green              { 82, 149, 132, 255 };
      constexpr color sea_shell              { 255, 245, 238, 255 };
      constexpr color sienna                 { 150, 82, 45, 255 };
      constexpr color sky_blue               { 114, 159, 255, 255 };
      constexpr color slate_blue             { 126, 136, 171, 255 };
      constexpr color slate_gray             { 112, 128, 144, 255 };
      constexpr color snow                   { 255, 250, 250, 255 };
      constexpr color spring_green           { 65, 172, 65, 255 };
      constexpr color steel_blue             { 84, 112, 170, 255 };
      constexpr color tan                    { 222, 184, 135, 255 };
      constexpr color thistle                { 216, 191, 216, 255 };
      constexpr color tomato                 { 255, 99, 71, 255 };
      constexpr color transparent            { 0, 0, 1, 255 };
      constexpr color turquoise              { 25, 204, 223, 255 };
      constexpr color violet                 { 156, 62, 206, 255 };
      constexpr color violet_red             { 243, 62, 150, 255 };
      constexpr color wheat                  { 245, 222, 179, 255 };
      constexpr color white                  { 255, 255, 255, 255 };
      constexpr color white_smoke            { 245, 245, 245, 255 };
      constexpr color yellow                 { 255, 255, 0, 255 };
      constexpr color yellow_green           { 50, 216, 56, 255 };

      // greys
      constexpr color gray[] =
      {
         { 0, 0, 0, 255 },
         { 3, 3, 3, 255 },
         { 5, 5, 5, 255 },
         { 8, 8, 8, 255 },
         { 10, 10, 10, 255 },
         { 13, 13, 13, 255 },
         { 15, 15, 15, 255 },
         { 18, 18, 18, 255 },
         { 20, 20, 20, 255 },
         { 23, 23, 23, 255 },
         { 26, 26, 26, 255 },
         { 28, 28, 28, 255 },
         { 31, 31, 31, 255 },
         { 33, 33, 33, 255 },
         { 36, 36, 36, 255 },
         { 38, 38, 38, 255 },
         { 41, 41, 41, 255 },
         { 43, 43, 43, 255 },
         { 46, 46, 46, 255 },
         { 48, 48, 48, 255 },
         { 51, 51, 51, 255 },
         { 54, 54, 54, 255 },
         { 56, 56, 56, 255 },
         { 59, 59, 59, 255 },
         { 61, 61, 61, 255 },
         { 64, 64, 64, 255 },
         { 66, 66, 66, 255 },
         { 69, 69, 69, 255 },
         { 71, 71, 71, 255 },
         { 74, 74, 74, 255 },
         { 77, 77, 77, 255 },
         { 79, 79, 79, 255 },
         { 82, 82, 82, 255 },
         { 84, 84, 84, 255 },
         { 87, 87, 87, 255 },
         { 89, 89, 89, 255 },
         { 92, 92, 92, 255 },
         { 94, 94, 94, 255 },
         { 97, 97, 97, 255 },
         { 99, 99, 99, 255 },
         { 102, 102, 102, 255 },
         { 105, 105, 105, 255 },
         { 107, 107, 107, 255 },
         { 110, 110, 110, 255 },
         { 112, 112, 112, 255 },
         { 115, 115, 115, 255 },
         { 117, 117, 117, 255 },
         { 120, 120, 120, 255 },
         { 122, 122, 122, 255 },
         { 125, 125, 125, 255 },
         { 127, 127, 127, 255 },
         { 130, 130, 130, 255 },
         { 133, 133, 133, 255 },
         { 135, 135, 135, 255 },
         { 138, 138, 138, 255 },
         { 140, 140, 140, 255 },
         { 143, 143, 143, 255 },
         { 145, 145, 145, 255 },
         { 148, 148, 148, 255 },
         { 150, 150, 150, 255 },
         { 153, 153, 153, 255 },
         { 156, 156, 156, 255 },
         { 158, 158, 158, 255 },
         { 161, 161, 161, 255 },
         { 163, 163, 163, 255 },
         { 166, 166, 166, 255 },
         { 168, 168, 168, 255 },
         { 171, 171, 171, 255 },
         { 173, 173, 173, 255 },
         { 176, 176, 176, 255 },
         { 179, 179, 179, 255 },
         { 181, 181, 181, 255 },
         { 184, 184, 184, 255 },
         { 186, 186, 186, 255 },
         { 189, 189, 189, 255 },
         { 191, 191, 191, 255 },
         { 194, 194, 194, 255 },
         { 196, 196, 196, 255 },
         { 199, 199, 199, 255 },
         { 201, 201, 201, 255 },
         { 204, 204, 204, 255 },
         { 207, 207, 207, 255 },
         { 209, 209, 209, 255 },
         { 212, 212, 212, 255 },
         { 214, 214, 214, 255 },
         { 217, 217, 217, 255 },
         { 219, 219, 219, 255 },
         { 222, 222, 222, 255 },
         { 224, 224, 224, 255 },
         { 227, 227, 227, 255 },
         { 229, 229, 229, 255 },
         { 232, 232, 232, 255 },
         { 235, 235, 235, 255 },
         { 237, 237, 237, 255 },
         { 240, 240, 240, 255 },
         { 242, 242, 242, 255 },
         { 245, 245, 245, 255 },
         { 247, 247, 247, 255 },
         { 250, 250, 250, 255 },
         { 252, 252, 252, 255 },
         { 255, 255, 255, 255 },
      };
   }
 }
 #endif