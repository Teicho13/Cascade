#include "CollisionManager.h"
#include "EnemyManager.h"

#include <iostream>

#include "BulletManager.h"
#include "Core/Math/Collision.h"

void CollisionManager::SetEnemyManager(EnemyManager* manager)
{
    enemyManager = manager;
}

void CollisionManager::SetBulletManager(BulletManager* manager)
{
    bulletManager = manager;
}

void CollisionManager::Update(float dt) const
{

    if(enemyManager == nullptr || bulletManager == nullptr)
        return;

    for (auto& bullet : bulletManager->GetBullets())
    {
        if(bullet->GetShouldDestroy())
            continue;

        for (auto& enemy : enemyManager->GetEnemies())
        {
            if(!enemy->GetIsActive())
                continue;
            
            if(Collision::AABB(bullet->GetPosition(),bullet->GetSize(),enemy->GetPosition(),enemy->GetSize()))
            {
                bullet->SetShouldDestroy(true);
                enemy->SetIsActive(false);
                enemyManager->EnemyRemoved();
                return;
            }
        }
    }
}
