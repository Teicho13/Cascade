#include "BulletManager.h"
#include "Core/Entities/Bullet.h"
#include "Core/Entities/Entity.h"

BulletManager::BulletManager()
{
    m_Bullets.reserve(30);
}

void BulletManager::SpawnBullet()
{
    m_Bullets.push_back(std::make_unique<Bullet>(m_player->GetPosition().x,m_player->GetPosition().y,3,12));
}

void BulletManager::SetPlayer(Entity* player)
{
    m_player = player;
}

void BulletManager::Update(float dt)
{
    for (int i = 0; i < m_Bullets.size(); ++i)
    {
        if(m_Bullets[i]->GetShouldDestroy())
        {
            m_Bullets.erase(m_Bullets.begin() + i);
            i--;
            continue;
        }

        m_Bullets[i]->Tick(dt);
    }
}

void BulletManager::Draw() const
{
    for (const auto& bullet : m_Bullets)
    {
        bullet->Draw();
    }
}
