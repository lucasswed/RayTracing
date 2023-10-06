#ifndef HITTABLE_HPP
# define HITTABLE_HPP

#include "../rayTracing.hpp"

class Material;

class hit_record {
  public:
    point3  p;
    Vec3    normal;
    shared_ptr<Material> mat;
    double  t;
    bool    front_face;

    void  set_face_normal(const Ray& r, const Vec3& outward_normal) {
      // Sets the hit record normal Vector
      // NOTE: the parameter `outward_normal` is assumed to have unit length

      front_face = dot(r.direction(), outward_normal) < 0;
      normal = front_face ? outward_normal : -outward_normal;
    }
};

class Hittable {
  public:
    virtual ~Hittable() = default;

    virtual bool  hit(const Ray& r, Interval ray_t, hit_record& rec) const = 0;
};

#endif