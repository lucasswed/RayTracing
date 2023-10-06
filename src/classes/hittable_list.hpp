#ifndef HITTABLE_LIST_HPP
# define HITTABLE_LIST_HPP

#include "../rayTracing.hpp"
#include "Hittable.hpp"

#include <memory>
#include <vector>

using std::shared_ptr;
using std::make_shared;

class hitttable_list : public Hittable
{
  public:
    std::vector<shared_ptr<Hittable>> objects;

    hitttable_list() {}
    hitttable_list(shared_ptr<Hittable> object) { add(object); }

    void  clear() { this->objects.clear(); }

    void  add(shared_ptr<Hittable> object) {
      this->objects.push_back(object);
    }

    bool  hit(const Ray& r,Interval ray_t, hit_record& rec) const override {
      hit_record  temp_rec;
      bool  hit_anything = false;
      auto closest_so_far = ray_t.max;

      for (const auto& object : objects) {
        if (object->hit(r, Interval(ray_t.min, closest_so_far), temp_rec)) {
          hit_anything = true;
          closest_so_far = temp_rec.t;
          rec = temp_rec;
        }
      }
      return hit_anything;
    }
};

#endif