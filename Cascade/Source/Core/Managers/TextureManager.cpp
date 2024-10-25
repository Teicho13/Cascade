#include "TextureManager.h"

#include "ResourceManager.h"
#include "Core/Graphics/Renderer.h"


SDL_Texture* TextureManager::CreateTexture(const std::string texturePath)
{
	//Create texture
	SDL_Texture* TempTexture = ResourceManager::GetResourceManager()->GetTexture(texturePath);

	return TempTexture;
}

SDL_Texture* TextureManager::CreateTexture(const std::string texturePath, int& imageWidth, int& imageHeight)
{

	//Create texture
	SDL_Surface* Surface = ResourceManager::GetResourceManager()->GetSurface(texturePath);
	SDL_Texture* TempTexture = ResourceManager::GetResourceManager()->GetTexture(texturePath);


	imageWidth = Surface->w;
	imageHeight = Surface->h;
	//Free Surface since we don't need it anymore
	SDL_FreeSurface(Surface);
	return TempTexture;
}

void TextureManager::DeleteTexture(SDL_Texture* texture)
{
	SDL_DestroyTexture(texture);
}

void TextureManager::RenderTexture(SDL_Texture* texture, const SDL_FRect* position)
{
	SDL_RenderCopyF(Renderer::GetRenderer(), texture, NULL, position);
}

void TextureManager::RenderTexture(SDL_Texture* texture, const SDL_Rect* sourcePos, const SDL_FRect* position)
{
	SDL_RenderCopyF(Renderer::GetRenderer(), texture, sourcePos, position);
}

void TextureManager::RenderTexture(SDL_Texture* texture, const SDL_Rect* position)
{
	SDL_RenderCopy(Renderer::GetRenderer(), texture, NULL, position);
}

void TextureManager::RenderTexture(SDL_Texture* texture, const SDL_Rect* sourcePos, const SDL_Rect* position)
{
	SDL_RenderCopy(Renderer::GetRenderer(), texture, sourcePos, position);
}

void TextureManager::Plot(const float posX, const float posY, const SDL_Color& color)
{
	SDL_SetRenderDrawColor(Renderer::GetRenderer(), color.r, color.g, color.b, color.a);
	SDL_RenderDrawPointF(Renderer::GetRenderer(),posX,posY);
}

void TextureManager::RenderBox(const float posX, const float posY, const float width, const float height)
{
	SDL_SetRenderDrawColor(Renderer::GetRenderer(), 255, 0, 0, 255);
	SDL_FRect tempRect = SDL_FRect{posX, posY, width, height};
	SDL_RenderDrawRectF(Renderer::GetRenderer(), &tempRect);
}

void TextureManager::RenderBox(const float posX, const float posY, const float width, const float height,
	const SDL_Color& color)
{
	SDL_SetRenderDrawColor(Renderer::GetRenderer(), color.r,color.g,color.b,color.a);
	SDL_FRect tempRect = SDL_FRect{posX, posY, width, height};
	SDL_RenderDrawRectF(Renderer::GetRenderer(), &tempRect);
}

void TextureManager::RenderBoxFill(const float posX, const float posY, const float width, const float height)
{
	SDL_SetRenderDrawColor(Renderer::GetRenderer(), 255, 0, 0, 255);
	SDL_FRect tempRect = SDL_FRect{ posX, posY, width, height };
	SDL_RenderFillRectF(Renderer::GetRenderer(), &tempRect);
}

void TextureManager::RenderBoxFill(const float posX, const float posY, const float width, const float height, const SDL_Color& color)
{
	SDL_SetRenderDrawColor(Renderer::GetRenderer(), color.r,color.g,color.b,color.a);
	SDL_FRect tempRect = SDL_FRect{ posX, posY, width, height };
	SDL_RenderFillRectF(Renderer::GetRenderer(), &tempRect);
}


