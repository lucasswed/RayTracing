#ifndef RAY_HPP
# define RAY_HPP

#include "Vec3.hpp"

class Ray
{
  private:
    point3  orig;
    Vec3    dir;
  public:
    Ray() {}
    Ray(const point3& origin, const Vec3& direction) : orig(origin), dir(direction) {}
    ~Ray() {}

    const point3& origin() const { return this->orig; }
    const Vec3&   direction() const { return this->dir; }

    point3 at(double t) const {
      return this->orig + t * this->dir;
    }
};

#endif