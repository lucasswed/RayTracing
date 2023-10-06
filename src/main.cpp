#include "rayTracing.hpp"
#include "classes/Color.hpp"
#include "classes/Sphere.hpp"
#include "classes/Camera.hpp"
#include "classes/Hittable.hpp"
#include "classes/hitttable_list.hpp"

int main(void) {
  // World
  hitttable_list world;

  world.add(make_shared<Sphere>(point3(0,0,-1), 0.5));
  world.add(make_shared<Sphere>(point3(0,-100.5,-1), 100));

  Camera  cam;

  cam.aspect_ratio = 16.0/9.0;
  cam.image_width = 400;
  cam.samples_per_pixel = 100;

  cam.render(world);
}