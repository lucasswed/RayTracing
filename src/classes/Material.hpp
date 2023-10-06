#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include "../rayTracing.hpp"
#include "hittable_list.hpp"

class Material {
  public:
    virtual ~Material() = default;

    virtual bool scatter(
        const Ray& r_in, const hit_record& rec, color& attenuation, Ray& scattered
    ) const = 0;
};

class lambertian : public Material
{
  private:
    color albedo;
  public:
    lambertian(const color& a) : albedo(a) {}

    bool scatter(const Ray& r_in, const hit_record& rec, color& attenuation, Ray& scattered) const override {
      auto  scatter_direction = rec.normal + random_unit_vector();
      (void)r_in;
      // Catch degenerate scatter direction
      if (scatter_direction.near_zero())
        scatter_direction = rec.normal;

      scattered = Ray(rec.p, scatter_direction);
      attenuation = albedo;
      return true;
    }
};

class Metal : public Material
{
  private:
    color   albedo;
    double  fuzz;
  public:
    Metal(const color& a, double f) : albedo(a), fuzz(f < 1 ? f : 1) {}

    bool scatter(const Ray& r_in, const hit_record& rec, color& attenuation, Ray& scattered) const override {
      Vec3 reflected = reflect(unit_vector(r_in.direction()), rec.normal);
      scattered = Ray(rec.p, reflected + fuzz*random_unit_vector());
      attenuation = albedo;
      return (dot(scattered.direction(), rec.normal) > 0);
    }
};

#endif