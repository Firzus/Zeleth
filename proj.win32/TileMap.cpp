#include "TileMap.h"

cocos2d::Scene* TileMap::createScene()
{
    // 'scene' est un autre pointeur vers une Scene
    auto scene = Scene::create();

    // 'layer' est un pointeur vers votre propre classe
    auto layer = TileMap::create();

    // ajouter la couche � la sc�ne
    scene->addChild(layer);

    // retourner la sc�ne
    return scene;
}

// surcharge de la m�thode init
bool TileMap::init()
{
    // appeler la m�thode init de la superclasse
    if (!Scene::init())
    {
        return false;
    }

    // Charger la carte � tuiles
    loadTileMap();

    // scale tilemap
    enlargeTileMap(3.0f);

    return true;
}

void TileMap::loadTileMap()
{
    // Chargement de la carte � tuiles � partir d'un fichier .tmx
    _tileMap = cocos2d::TMXTiledMap::create("tiled/map.tmx");
    // ajout de la carte � tuiles � la sc�ne
    this->addChild(_tileMap);
}

void TileMap::enlargeTileMap(float scale)
{
    _tileMap->setScale(scale);
}
