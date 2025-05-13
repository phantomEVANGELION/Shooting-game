#pragma once
#include "chicken.h"
extern Atlas atlas_chicken_slow;

class ChickenSlow : public Chicken
{
public:
    ChickenSlow()
    {
        animation_run.add_frame(&atlas_chicken_slow);
        speed_run = 25.0f;
    }
    ~ChickenSlow() = default;
};