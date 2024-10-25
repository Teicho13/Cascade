#include "Collision.h"

bool Collision::AABB(SDL_FPoint PosA, SDL_Point SizeA, SDL_FPoint PosB, SDL_Point SizeB)
{
    if (PosA.x < PosB.x + static_cast<float>(SizeB.x) &&
        PosA.x + static_cast<float>(SizeA.x) > PosB.x &&
        PosA.y < PosB.y + static_cast<float>(SizeB.y) &&
        PosA.y + static_cast<float>(SizeA.y) > PosB.y)
    {
        return true;
    }
    return false;
}
