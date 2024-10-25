#pragma once
#include <SDL_rect.h>

class Collision
{
public:
    static bool AABB(SDL_FPoint PosA, SDL_Point SizeA, SDL_FPoint PosB, SDL_Point SizeB);
};
