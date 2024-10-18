#pragma once
#include <array>


class Bullet;
class Entity;
class BulletManager
{
public:
    void SpawnBullet();
    void SetPlayer(Entity* player);

    void Update(float dt) const;
    void Draw() const;
    
    private:
    int m_ActiveBullets = 0;
    std::array<Bullet*, 20> m_Bullets;
    Entity* m_player = nullptr;
};
