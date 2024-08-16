#include "TextureManager.h"
#include <SDL_image.h>

#include "Core/Graphics/Renderer.h"


SDL_Texture* TextureManager::CreateTexture(const std::string texturePath)
{
	//Create texture
	SDL_Surface* Surface = IMG_Load(texturePath.c_str());
	SDL_Texture* TempTexture = SDL_CreateTextureFromSurface(Renderer::GetRenderer(), Surface);
	//Free Surface since we dont need it anymore
	SDL_FreeSurface(Surface);
	return TempTexture;
}

SDL_Texture* TextureManager::CreateTexture(const std::string texturePath, int& imageWidth, int& imageHeight)
{

	//Create texture
	SDL_Surface* Surface = IMG_Load(texturePath.c_str());
	SDL_Texture* TempTexture = SDL_CreateTextureFromSurface(Renderer::GetRenderer(), Surface);

	imageWidth = Surface->w;
	imageHeight = Surface->h;
	//Free Surface since we dont need it anymore
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

void TextureManager::RenderBox(const float posX, const float posY, const float width, const float height)
{
	SDL_SetRenderDrawColor(Renderer::GetRenderer(), 255, 0, 0, 255);
	SDL_FRect tempRect = SDL_FRect(posX, posY, width, height);
	SDL_RenderDrawRectF(Renderer::GetRenderer(), &tempRect);
}


