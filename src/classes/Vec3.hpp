#ifndef VEC3_HPP
# define VEC3_HPP

#include <cmath>
#include <iostream>

using std::sqrt;

class Vec3
{
  public:
    double e[3];
  
    Vec3() : e{0, 0, 0} {}
    Vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}
    ~Vec3() {}

    double x() const { return e[0]; }
    double y() const { return e[1]; }
    double z() const { return e[2]; }

    Vec3 operator-() const { return Vec3(-e[0], -e[1], -e[2]); }
    double operator[](int i) const { return e[i]; }
    double& operator[](int i) { return e[i]; }

    Vec3& operator+=(const Vec3& v) {
      this->e[0] += v.e[0];
      this->e[1] += v.e[1];
      this->e[2] += v.e[2];
      return *this;
    }

    Vec3& operator*=(double t) {
      this->e[0] *= t;
      this->e[1] *= t;
      this->e[2] *= t;
      return *this;
    }

    Vec3& operator/=(double t) {
      return *this *= 1/t;
    }

    double length() const {
      return sqrt(length_squared());
    }

    double length_squared() const {
      return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
    }
};

// Point3 is just an alias for Vec3, but useful for geometric clarity in the code.
using point3 = Vec3;

// Vector utility functions

inline std::ostream& operator<<(std::ostream& out, const Vec3& v) {
  return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

inline Vec3 operator+(const Vec3& u, const Vec3& v) {
  return  Vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

inline Vec3 operator-(const Vec3& u, const Vec3& v) {
  return  Vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

inline Vec3 operator*(const Vec3& u, const Vec3& v) {
  return  Vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

inline Vec3 operator*(double t, const Vec3& v) {
  return Vec3(t * v.e[0], t * v.e[1], t * v.e[2]);
}

inline Vec3 operator*(const Vec3& v, double t) {
  return t * v;
}

inline Vec3 operator/(const Vec3& v, double t) {
  return (1/t) * v;
}

inline double dot(const Vec3& u, const Vec3& v) {
  return u.e[0] * v.e[0] + u.e[1] * v.e[1] + u.e[2] * v.e[2];
}

inline Vec3 cross(const Vec3& u, const Vec3& v) {
  return Vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
              u.e[2] * v.e[0] - u.e[0] * v.e[2],
              u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

inline Vec3 unit_vector(const Vec3& v) {
  return v / v.length();
}

#endif