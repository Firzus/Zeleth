#include "SetMusicVolume.h"

bool SetMusicVolume::init()
{
    if (!Node::init())
    {
        return false;
    }

    createTextMusic();
    createSliderMusic();

    return true;
}

void SetMusicVolume::createTextMusic()
{
    textMusic = Label::createWithTTF("Music", "fonts/ui/normal.ttf", 24);

    textMusic->setPosition(Vec2(0, 50));

    this->addChild(textMusic);
}

void SetMusicVolume::createSliderMusic()
{
    // Cr?er le slider
    slider = Slider::create();

    // Configurer la texture du slider et de la barre de progression

    slider->loadBarTexture("sprites/ui/settings/audio/Slider_Back.png");
    slider->loadProgressBarTexture("sprites/ui/settings/audio/Slider_PressBar.png");
    slider->loadSlidBallTextures
    (
        "sprites/ui/settings/audio/SliderNode_Normal.png",
        "sprites/ui/settings/audio/SliderNode_Press.png",
        "sprites/ui/settings/audio/SliderNode_Disable.png"
    );

    // Configurer la valeur maximale du slider
    slider->setMaxPercent(100);

    // D?finir la valeur actuelle du slider (ici, 75% du volume)
    slider->setPercent(75);

    // Ajouter un ?v?nement qui sera d?clench? lorsque la valeur du slider change
    slider->addEventListener([](Ref* sender, Slider::EventType type) {
        if (type == Slider::EventType::ON_PERCENTAGE_CHANGED) {
            auto slider = static_cast<Slider*>(sender);
            int percent = slider->getPercent();
            // Mettre ? jour le volume de la musique en fonction de la valeur du slider
            SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(percent / 100.0f);
        }
        });

    // Ajouter le slider ? la sc?ne
    this->addChild(slider);
}
