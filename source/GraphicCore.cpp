#include <iostream>
#include "../headers/GraphicCore.h"

GraphicCore::GraphicCore() {
    //
}

GraphicCore::~GraphicCore() {
    manager->~TextureManager();
    delete manager;
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
}

/*
	Создание рендера
	(Create render)
*/
void GraphicCore::Init(SDL_Window *window) {
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) {
        SDL_Log("Render create error");
        SDL_Quit();
    }

    manager = new TextureManager(renderer);
}


/*
	Создаём нашу текстурку
	(Create texture)
*/
void GraphicCore::CreateTexture(std::string path) {
    manager->CreateTexture(path);
}

/*
	x, y - coordinates on window
*/
void GraphicCore::RenderTexture(SDL_Texture *texture, int x, int y) {
    int w, h;
    SDL_QueryTexture(texture, NULL, NULL, &w, &h);
    RenderTexture(texture, x, y, w, h);
}

/*
	w(width), h(height) of texture
*/
void GraphicCore::RenderTexture(SDL_Texture *texture, int x, int y, int w, int h) {
    SDL_Rect rectangle;
    rectangle.x = x;
    rectangle.y = y;
    rectangle.w = w;
    rectangle.h = h;
    SDL_RenderCopy(renderer, texture, NULL, &rectangle);
}

void GraphicCore::RenderAllTexturesInMap() {
    int x = 0;
    std::map<int, SDL_Texture *> *map = manager->getMapLink();
    for (auto it = map->begin(); it != map->end(); ++it) {
        RenderTexture(it->second, x, x);
        x += 100;
    }
    //std::cout << "RENDER PRESENT!" << std::endl;
    SDL_RenderPresent(renderer);
}

void GraphicCore::DeleteTexture(std::string path) {
    manager->deleteTexture(path);
}

void GraphicCore::viewManagerMap() {
    manager->viewMap();
}

void GraphicCore::clearRender() {
    //std::cout << "Renderer clean" << std::endl;
    SDL_RenderClear(renderer);
}

SDL_Renderer *GraphicCore::getRenderer() {
    return renderer;
}
