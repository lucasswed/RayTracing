#ifndef SPHERE_HPP
# define SPHERE_HPP

#include "../rayTracing.hpp"
#include "Hittable.hpp"

class Sphere : public Hittable {
  private:
    point3  center;
    double  radius;
    shared_ptr<Material> mat;
  public:
    Sphere(const point3& _center, double _radius, shared_ptr<Material> _material)
    : center(_center), radius(_radius), mat(_material) {}

    bool  hit(const Ray& r, Interval ray_t, hit_record& rec) const override {
      Vec3  oc = center - r.origin();
        auto  a = r.direction().length_squared();
        auto  h = dot(r.direction(), oc);
        auto  c = oc.length_squared() - radius*radius;
        auto  discriminant = h*h - a*c;

        if (discriminant < 0) return false;
        auto sqrtd = sqrt(discriminant);

        // Find the nearest root that lies in the acceptable range
        auto root = (h - sqrtd) / a;
        if (!ray_t.surrounds(root)) {
          root = (h + sqrtd) / a;
          if (!ray_t.surrounds(root))
            return false;
        }

        rec.t = root;
        rec.p = r.at(rec.t);
        Vec3 outward_normal = (rec.p - center) / radius;
        rec.set_face_normal(r, outward_normal);
        rec.mat = mat;

        return true;
    }
};

#endif