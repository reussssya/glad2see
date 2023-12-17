#include "trackplayer.hpp"
#include <iostream>


CTrackPlayer::CTrackPlayer(QWidget *parent) : QWidget(parent)
{
    InitArtists();
    //connect()
    btnPlay->setStyleSheet("QPushButton { background-color: D9D9D9 }");
    btnPlay->setGeometry(740,55, 60,60);



    connect(btnPlay, &QPushButton::clicked, this, &CTrackPlayer::clicked_onPlay);
}

CTrackPlayer::~CTrackPlayer()
{

}

void CTrackPlayer::InitArtists()
{
    for(const auto& x : br_phonk)
    {
        Artist a;
        a.setName(x.second);
        artists.push_back(a);
    }
}

void CTrackPlayer::clicked_onFavourite()
{

}

void CTrackPlayer::clicked_onPlay()
{

}

void CTrackPlayer::clicked_onNext()
{

}
void CTrackPlayer::clicked_onPrevious()
{

}
void CTrackPlayer::clicked_onRepeat()
{

}
void CTrackPlayer::clicked_onRandom()
{

}
void CTrackPlayer::clicked_onVolume()
{

}

