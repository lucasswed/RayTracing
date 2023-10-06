#ifndef RAYTRACING_HPP
# define RAYTRACING_HPP

#include <cmath>
#include <limits>
#include <memory>
#include <cstdlib>
#include <iostream>

using std::shared_ptr;
using std::make_shared;
using std::sqrt;

// Constants

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// Utility functions

inline double degrees_to_radians(double degrees) {
  return degrees * pi / 180.0;
}

inline double random_double() {
  // returns a random real in [0, 1]
  return rand() / (RAND_MAX + 1.0);
}

inline double random_double(double min, double max) {
  // returns a random real in [min, max]
  return min + (max-min)*random_double();
}

#include "classes/Ray.hpp"
#include "classes/Vec3.hpp"
#include "classes/Interval.hpp"

#endif