#pragma once
#include "chicken.h"
extern Atlas atlas_chicken_medium;

class ChickenMedium : public Chicken
{
public:
    ChickenMedium()
    {
        animation_run.add_frame(&atlas_chicken_medium);
        speed_run = 50.0f;
    }
    ~ChickenMedium() = default;
};