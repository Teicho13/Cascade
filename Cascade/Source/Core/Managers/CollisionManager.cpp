#include "CollisionManager.h"

#include <iostream>

#include "Core/Math/Collision.h"

void CollisionManager::Update(float dt, const std::array<Enemy*, 75>& enemies, const std::vector<std::unique_ptr<Bullet>>& bullets)
{
    for (auto& bullet : bullets)
    {
        for (auto& enemy : enemies)
        {
            if(!enemy->GetIsActive())
                continue;
            
            if(Collision::AABB(bullet->GetPosition(),bullet->GetSize(),enemy->GetPosition(),enemy->GetSize()))
            {
                bullet->SetShouldDestroy(true);
                enemy->SetIsActive(false);
            }
        }
    }
}
