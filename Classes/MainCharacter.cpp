#include "MainCharacter.h"

bool MainCharacter::init()
{
    // appeler la m�thode init de la superclasse
    if (!Sprite::init())
    {
        return false;
    }

    // Cr�ation du sprite � partir de l'image "sprite.png"
    this->initWithFile("sprites/characters/sprite-resize.png");

    // D�termination de la taille de l'�cran
    auto visibleSize = Director::getInstance()->getVisibleSize();

    // D�finition de la position du sprite au milieu de l'�cran
    this->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));

    return true;
}