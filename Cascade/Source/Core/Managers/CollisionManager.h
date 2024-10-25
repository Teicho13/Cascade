#pragma once
#include <array>
#include <vector>

#include "Core/Entities/Bullet.h"
#include "Core/Entities/Enemy.h"


class CollisionManager
{
public:
    void Update(float dt, const std::array<Enemy*,75> &enemies, const std::vector<std::unique_ptr<Bullet>> &bullets);
};
