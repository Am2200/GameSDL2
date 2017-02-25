//
// Created by Am on 20.02.2017.
//

#ifndef CMAKETEST_TEXTUREMANAGER_H
#define CMAKETEST_TEXTUREMANAGER_H

#include "FullSDL.h"
#include "EnumTypes.h"
#include <functional>
#include <map>

class TextureManager {
public:
    TextureManager(SDL_Renderer *);
    ~TextureManager();
    //Создаём текстурку и запихиваем её в мапу
    void CreateTexture(std::string);
    void clearMap();
    void viewMap();
    std::map<int, SDL_Texture *> *getMapLink();

    //Пока только путь path
    template<typename T>
    SDL_Texture *getTexture(T value) {
        //if (enumTypes[0] == typeid(value))
        int id = typeid(value).hash_code();
        return map->find(id)->second;
    }

    template<typename T>
    void deleteTexture(T value) {
        int hash = calculateHash(value);
        map->erase(hash);
        /*
        std::string name = getTypeName(value);
        switch (name)
        {
        case "Integer":
            auto it = map->find(value);
            map->erase(it);
            break;
        case "String":
            size_t hash = hash_fn(value);
            auto it = map->find(hash);
            map->erase(it);
            break;
        }
        */
    }

    /**
     * Зачем нужна эта функция мне пока не ясно...
     * @tparam T
     * @param value
     * @return
     */
    template<typename T>
    std::string getTypeName(T value) {
        int id = typeid(value).hash_code();

        std::string name = nullptr;
        return name;
    }

private:
    //В мапе текстурки хранятся по значению хеша пути(к файлу)
    void addTextureToMap(SDL_Texture *, int);
    int calculateHash(std::string);
    std::hash<std::string> hash_fn;
    SDL_Renderer *renderer = nullptr;
    std::map<int, SDL_Texture *> *map;
};


#endif //CMAKETEST_TEXTUREMANAGER_H
