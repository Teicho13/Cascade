#pragma once
#include <SDL_pixels.h>
#include <string>

struct SDL_Renderer;
struct SDL_Texture;
struct SDL_FRect;
struct SDL_Rect;

class TextureManager
{
public:
	static SDL_Texture* CreateTexture(const std::string texturePath);
	static SDL_Texture* CreateTexture(const std::string texturePath, int& imageWidth, int& imageHeight);
	static void DeleteTexture(SDL_Texture* texture);

	static void RenderTexture(SDL_Texture* texture, const SDL_FRect* position);
	static void RenderTexture(SDL_Texture* texture, const SDL_Rect* sourcePos, const SDL_FRect* position);

	static void RenderTexture(SDL_Texture* texture, const SDL_Rect* position);
	static void RenderTexture(SDL_Texture* texture, const SDL_Rect* sourcePos, const SDL_Rect* position);

	static void Plot(const float posX, const float posY, const SDL_Color& color);
	static void RenderBox(const float posX, const float posY, const float width, const float height);
	static void RenderBox(const float posX, const float posY, const float width, const float height, const SDL_Color& color);
	static void RenderBoxFill(const float posX, const float posY, const float width, const float height);
	static void RenderBoxFill(const float posX, const float posY, const float width, const float height,const SDL_Color& color);
};