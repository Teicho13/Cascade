#include "Bullet.h"

#include "Core/Managers/TextureManager.h"

Bullet::Bullet(const float posX, const float posY, const int sizeX, const int sizeY)
	: m_Position(SDL_FPoint {posX,posY}),
	m_Size(SDL_Point{sizeX,sizeY})
{
}

void Bullet::SetPosition(float newX, float newY)
{
	m_Position.x = newX;
	m_Position.y = newY;
}

SDL_FPoint Bullet::GetPosition() const
{
	return m_Position;
}

SDL_Point Bullet::GetSize() const
{
	return m_Size;
}

SDL_Color Bullet::GetColor() const
{
	return m_Color;
}

void Bullet::Tick(float dt)
{
	SetPosition(m_Position.x, m_Position.y - m_Speed * dt);
	CheckBounds();
}

void Bullet::Draw() const
{
	TextureManager::RenderBoxFill(m_Position.x, m_Position.y, static_cast<float>(m_Size.x), static_cast<float>(m_Size.y), m_Color);
}

void Bullet::CheckBounds()
{
	if(m_Position.y <= 0.f - static_cast<float>(m_Size.y))
	{
		m_ShouldDestroy = true;
	}
}

void Bullet::SetShouldDestroy(bool shouldDestroy)
{
	m_ShouldDestroy = shouldDestroy;
}

bool Bullet::GetShouldDestroy() const
{
	return m_ShouldDestroy;
}
