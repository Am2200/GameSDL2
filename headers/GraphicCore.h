#ifndef CMAKETEST_GRAPHICCORE_H
#define CMAKETEST_GRAPHICCORE_H

#include "FullSDL.h"
#include "TextureManager.h"

/*
	Как хранить изображения? - Менеджер текстурок!
*/
class GraphicCore
{
public:
    GraphicCore();
    ~GraphicCore();
    void Init(SDL_Window *);
    void CreateTexture(std::string);
    void RenderTexture(SDL_Texture*, int, int);
    void RenderTexture(SDL_Texture*, int, int, int, int);
    void RenderAllTexturesInMap();
    void DeleteTexture(std::string);
    void viewManagerMap();
    void clearRender();
    SDL_Renderer* getRenderer();
private:
    TextureManager *manager = nullptr;
    SDL_Texture *texture = nullptr;
    SDL_Renderer *renderer = nullptr;
};

#endif //CMAKETEST_GRAPHICCORE_H
