#include "TileMap.h"

USING_NS_CC;

bool TileMap::init()
{
    if (!Node::init())
    {
        return false;
    }

    // Charger la carte � tuiles
    loadTileMap();

    // scale tilemap
    enlargeTileMap(4.0f);

    return true;
}

void TileMap::loadTileMap()
{
    // Chargement de la carte � tuiles � partir d'un fichier .tmx
    _tileMap = TMXTiledMap::create("tiled/map.tmx");
    // ajout de la carte � tuiles � la sc�ne
    this->addChild(_tileMap);
}

void TileMap::enlargeTileMap(float scale)
{
    _tileMap->setScale(scale);
}