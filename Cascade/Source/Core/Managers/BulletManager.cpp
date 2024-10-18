#include "BulletManager.h"
#include "Core/Entities/Bullet.h"
#include "Core/Entities/Entity.h"

void BulletManager::SpawnBullet()
{
    if(m_ActiveBullets <= 19)
    {
        m_Bullets[m_ActiveBullets] = new Bullet(m_player->GetPosition().x,m_player->GetPosition().y,3,12);
        m_ActiveBullets++;
    }
}

void BulletManager::SetPlayer(Entity* player)
{
    m_player = player;
}

void BulletManager::Update(float dt) const
{
    if(m_ActiveBullets > 0)
    {
        for(int i = 0; i < m_ActiveBullets; i++)
        {
            m_Bullets[i]->Tick(dt);
        }
    }
}

void BulletManager::Draw() const
{
    if(m_ActiveBullets > 0)
    {
        for(int i = 0; i < m_ActiveBullets; i++)
        {
            m_Bullets[i]->Draw();
        }
    }
}
