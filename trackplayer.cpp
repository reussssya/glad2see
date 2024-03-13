#include "trackplayer.hpp"
#include <iostream>


CTrackPlayer::CTrackPlayer()
{
    InitArtists();
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
