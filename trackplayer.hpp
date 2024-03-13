#pragma once

#include "common.h"

class Artist
{
public:
    Artist()
    {

    }
    ~Artist()
    {

    }
    explicit Artist(std::string name, std::string info, std::string avatarPath)
    {
        setName(name);
        setAvatar(avatarPath);
        setInfo(info);
    }
    void setName(std::string name)
    {
        this->name = name;
    }
    void setInfo(std::string info)
    {
        this->info = info;
    }
    void setAvatar(std::string path)
    {
        
    }
private:
    std::string name;
    std::string info;

    bool m_bDisplay = true;
};

class CTrackPlayer 
{
public:
    CTrackPlayer();
    ~CTrackPlayer();

    void InitArtists();


    /*void repeat(bool value = false)
    {
        repeat = value;
    }
    void random(bool value = false)
    {
        random = value;
    }*/
    void setVolume(unsigned int volume = 40)
    {
        this->volume = volume;
    }
    
private:

    //example view (have to make remote get songs (from web-server) using JSON or Protobuf)
    std::vector<std::pair<std::string, std::string>> br_phonk { 
        {"BRAZILIAN DANÇA PHONK", "6YNTHMANE, RXDXVIL"},
        {"TOMA TOMA TOMA", "$werve, TOKYOSLEEP, MC GW"},
        {"BALADINHA SINISTRA", "$werve, $pidxrs?808 & Crazy Mano"},
        {"AUTOMOTIVO ANGELICAL","DJ ZK3"},
        {"AUTOMOTIVO PEGA 1.0 (SLOWED + REVERB)", "Phonk Killer & PHOROMANE"},
        {"MTG DESESPERANÇA 1.0 (SLOWED + REVERB)", "Phonk Killer"}
    };
    
    bool random = false;
    bool repeat = false;
    unsigned int volume = 40;

    std::vector<Artist> artists;


};
