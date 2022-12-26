#include "GameScene.h"

Scene* GameScene::createScene()
{
    // 'scene' est un autre pointeur vers une Scene
    auto scene = Scene::create();

    // 'layer' est un pointeur vers votre propre classe
    auto layer = GameScene::create();

    // ajouter la couche � la sc�ne
    scene->addChild(layer);

    // retourner la sc�ne
    return scene;
}

// surcharge de la m�thode init
bool GameScene::init()
{
    // appeler la m�thode init de la superclasse
    if (!Scene::init())
    {
        return false;
    }

    // Cr�ation de l'instance de TileMap
    _tileMap = TileMap::create();
    // ajout de la carte � tuiles � la sc�ne
    this->addChild(_tileMap);

    return true;
}