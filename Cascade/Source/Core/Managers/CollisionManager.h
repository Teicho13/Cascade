#pragma once
#include <array>
#include <vector>

#include "Core/Entities/Bullet.h"
#include "Core/Entities/Enemy.h"


class BulletManager;
class EnemyManager;

class CollisionManager
{
public:
    void SetEnemyManager(EnemyManager* manager);
    void SetBulletManager(BulletManager* manager);

    void Update(float dt) const;

private:
    EnemyManager* enemyManager = nullptr;
    BulletManager* bulletManager = nullptr;
};
