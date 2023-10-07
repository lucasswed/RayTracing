#include "rayTracing.hpp"

#include "classes/Color.hpp"
#include "classes/Sphere.hpp"
#include "classes/Camera.hpp"
#include "classes/Material.hpp"
#include "classes/hittable_list.hpp"

int main(void)
{
  // World
  hitttable_list world;

  auto ground_material = make_shared<lambertian>(color(0.5, 0.5, 0.5));
  world.add(make_shared<Sphere>(point3(0,-1000,0), 1000, ground_material));
  for (int a = -11; a < 11; a++) {
      for (int b = -11; b < 11; b++) {
          auto choose_mat = random_double();
          point3 center(a + 0.9*random_double(), 0.2, b + 0.9*random_double());
          if ((center - point3(4, 0.2, 0)).length() > 0.9) {
              shared_ptr<Material> sphere_material;
              if (choose_mat < 0.8) {
                  // diffuse
                  auto albedo = color::random() * color::random();
                  sphere_material = make_shared<lambertian>(albedo);
                  world.add(make_shared<Sphere>(center, 0.2, sphere_material));
              } else if (choose_mat < 0.95) {
                  // metal
                  auto albedo = color::random(0.5, 1);
                  auto fuzz = random_double(0, 0.5);
                  sphere_material = make_shared<Metal>(albedo, fuzz);
                  world.add(make_shared<Sphere>(center, 0.2, sphere_material));
              } else {
                  // glass
                  sphere_material = make_shared<dielectric>(1.5);
                  world.add(make_shared<Sphere>(center, 0.2, sphere_material));
              }
          }
      }
  }

  Camera cam;

  cam.aspect_ratio      = 16.0 / 9.0;
  cam.image_width       = 1200;
  cam.samples_per_pixel = 500;
  cam.max_depth         = 50;

  cam.vfov     = 20;
  cam.lookfrom = point3(13,2,3);
  cam.lookat   = point3(0,0,0);
  cam.vup      = Vec3(0,1,0);

  cam.defocus_angle = 0.6;
  cam.focus_dist    = 10.0;

  cam.render(world);
}