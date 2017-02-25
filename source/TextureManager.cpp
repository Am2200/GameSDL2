#include "../headers/TextureManager.h"
#include <iostream>

TextureManager::TextureManager(SDL_Renderer *renderer) {
    map = new std::map<int, SDL_Texture *>;
    this->renderer = renderer;
}

TextureManager::~TextureManager() {
    delete map;
}

void TextureManager::CreateTexture(std::string path) {
    SDL_Texture *texture = IMG_LoadTexture(renderer, path.c_str());
    if (texture == nullptr) {
        std::cout << IMG_GetError() << std::endl;
    }
    addTextureToMap(texture, calculateHash(path));
}

void TextureManager::addTextureToMap(SDL_Texture *texture, int hash) {
    std::pair<int, SDL_Texture *> e = std::make_pair(hash, texture);
    map->insert(e);
}

int TextureManager::calculateHash(std::string path) {
    size_t hash = hash_fn(path);
    return hash;
}


void TextureManager::clearMap() {
    map->clear();
}

void TextureManager::viewMap() {
    for (auto id = map->begin(); id != map->end(); ++id) {
        std::cout << "First: " << id->first << " Second: " << id->second << std::endl;
    }
}

std::map<int, SDL_Texture *> *TextureManager::getMapLink() {
    return map;
}
