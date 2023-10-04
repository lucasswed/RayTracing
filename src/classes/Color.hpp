#ifndef COLOR_HPP
# define COLOR_HPP

#include "Vec3.hpp"
#include <iostream>

using color = Vec3;

void write_color(std::ostream& out, const color& pixel_color) {
  // write the translated [0,255] value of each color component
  out << int(255.999 * pixel_color.x()) << ' '
      << int(255.999 * pixel_color.y()) << ' '
      << int(255.999 * pixel_color.z()) << '\n';
}

#endif