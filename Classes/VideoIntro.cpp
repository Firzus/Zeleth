#include "VideoIntro.h"

bool VideoIntro::init()
{
    if (!Node::init())
    {
        return false;
    }

    return true;
}

void VideoIntro::createVideo()
{
    auto videoPlayer = cocos2d::ui::VideoPlayer::create();

    // Chargez la vid�o en utilisant le chemin du fichier
    videoPlayer->setFileName("video/IntroZeleth.mp4");

    // Ajout de l'objet VideoPlayer � la sc�ne
    addChild(videoPlayer);

    // D�marrage de la lecture de la vid�o
    videoPlayer->play();

    // Activez le mode plein �cran
    videoPlayer->setFullScreenEnabled(true);
}