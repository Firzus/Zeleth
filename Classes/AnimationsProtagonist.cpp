#include "AnimationsProtagonist.h"

bool AnimationsProtagonist::init()
{
    if (!Sprite::init())
    {
        return false;
    }

    return true;
}

void AnimationsProtagonist::loadAnimations()
{
    // Load the sprite sheet that contains the frames for the main character animation
    this->spritecache = SpriteFrameCache::getInstance();
    this->spritecache->addSpriteFramesWithFile("sprites/characters/main/down/mainCharacter-down.plist");
    this->spritecache->addSpriteFramesWithFile("sprites/characters/main/up/mainCharacter-up.plist");
    this->spritecache->addSpriteFramesWithFile("sprites/characters/main/left/mainCharacter-left.plist");
    this->spritecache->addSpriteFramesWithFile("sprites/characters/main/right/mainCharacter-right.plist");
}

void AnimationsProtagonist::getStartRotation()
{
    this->setSpriteFrame("mainCharacter-down-1.png");
}

void AnimationsProtagonist::getLeftWalkAnimation()
{
    // Create an animation using the frames from the sprite sheet
    Vector<SpriteFrame*> frames;
    for (int i = 0; i <= 3; i++) {
        auto frame = this->spritecache->getSpriteFrameByName(StringUtils::format("mainCharacter-left-%d.png", i));
        frames.pushBack(frame);
    }

    auto mainCharacterLeftAnimation = Animation::createWithSpriteFrames(frames, 0.2f);
    auto mainCharacterLeftAnimate = Animate::create(mainCharacterLeftAnimation);

    this->runAction(RepeatForever::create(mainCharacterLeftAnimate));
}

void AnimationsProtagonist::getRightWalkAnimation()
{
    // Create an animation using the frames from the sprite sheet
    Vector<SpriteFrame*> frames;
    for (int i = 0; i <= 3; i++)
    {
        auto frame = this->spritecache->getSpriteFrameByName(StringUtils::format("mainCharacter-right-%d.png", i));
        frames.pushBack(frame);
    }

    auto mainCharacterRightAnimation = Animation::createWithSpriteFrames(frames, 0.2f);
    auto mainCharacterRightAnimate = Animate::create(mainCharacterRightAnimation);

    this->runAction(RepeatForever::create(mainCharacterRightAnimate));
}

void AnimationsProtagonist::getDownWalkAnimation()
{
    // Create an animation using the frames from the sprite sheet
    Vector<SpriteFrame*> frames;
    for (int i = 0; i <= 3; i++)
    {
        auto frame = this->spritecache->getSpriteFrameByName(StringUtils::format("mainCharacter-down-%d.png", i));
        frames.pushBack(frame);
    }

    auto mainCharacterDownAnimation = Animation::createWithSpriteFrames(frames, 0.2f);
    auto mainCharacterDownAnimate = Animate::create(mainCharacterDownAnimation);

    this->runAction(RepeatForever::create(mainCharacterDownAnimate));
}

void AnimationsProtagonist::getUpWalkAnimation()
{
    // Create an animation using the frames from the sprite sheet
    Vector<SpriteFrame*> frames;
    for (int i = 0; i <= 3; i++)
    {
        auto frame = this->spritecache->getSpriteFrameByName(StringUtils::format("mainCharacter-up-%d.png", i));
        frames.pushBack(frame);
    }

    auto mainCharacterUpAnimation = Animation::createWithSpriteFrames(frames, 0.2f);
    auto mainCharacterUpAnimate = Animate::create(mainCharacterUpAnimation);

    this->runAction(RepeatForever::create(mainCharacterUpAnimate));
}

void AnimationsProtagonist::getIdleLeft()
{
    this->stopAllActions();
    this->setSpriteFrame("mainCharacter-left-1.png");
}

void AnimationsProtagonist::getIdleRight()
{
    this->stopAllActions();
    this->setSpriteFrame("mainCharacter-right-1.png");
}

void AnimationsProtagonist::getIdleUp()
{
    this->stopAllActions();
    this->setSpriteFrame("mainCharacter-up-1.png");
}

void AnimationsProtagonist::getIdleDown()
{
    this->stopAllActions();
    this->setSpriteFrame("mainCharacter-down-1.png");
}

void AnimationsProtagonist::setAnimationState(AnimationState state)
{
    _animationState = state;
}

void AnimationsProtagonist::setAnimation(AnimationState state)
{
    // Si l'animation en cours d'ex?cution est la m?me que celle demand?e, ne rien faire
    if (_animationState == state) return;

    // Mettre ? jour l'?tat de l'animation
    _animationState = state;

    // Arr?ter toutes les actions en cours d'ex?cution
    this->stopAllActions();

    // S?lectionner l'animation ? ex?cuter en fonction de l'?tat de l'animation
    switch (_animationState)
    {
    case AnimationState::Right:
        getRightWalkAnimation();
        break;
    case AnimationState::Left:
        getLeftWalkAnimation();
        break;
    case AnimationState::Down:
        getDownWalkAnimation();
        break;
    case AnimationState::Up:
        getUpWalkAnimation();
        break;
    case AnimationState::IdleRight:
        getIdleRight();
        break;
    case AnimationState::IdleLeft:
        getIdleLeft();
        break;
    case AnimationState::IdleUp:
        getIdleUp();
        break;
    case AnimationState::IdleDown:
        getIdleDown();
        break;
    }
}
