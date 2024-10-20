#pragma once
#include <memory>
#include <vector>


class Bullet;
class Entity;
class BulletManager
{
public:
    BulletManager();
    
    void SpawnBullet();
    void SetPlayer(Entity* player);

    void Update(float dt);
    void Draw() const;
    
    private:
    Entity* m_player = nullptr;
    std::vector<std::unique_ptr<Bullet>> m_Bullets;
};
