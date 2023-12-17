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
        avatar->load(QString::fromStdString(path));
    }
private:
    std::string name;
    std::string info;
    QPixmap* avatar;

    bool m_bDisplay = true;
};

class CTrackPlayer : public QWidget
{
    Q_OBJECT
public:
    CTrackPlayer(QWidget *parent = nullptr);
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
    
    QMediaPlayer *pMediaPlayer;

    //QMediaPlaylist *pMediaPlaylist;

    QToolButton* btnPlay = new QToolButton(this);
    QToolButton* btnNext = new QToolButton(this);
    QToolButton* btnPrevious = new QToolButton(this);
    QToolButton* btnFavourite = new QToolButton(this);
    QToolButton* btnVolume = new QToolButton(this);
    QToolButton* btnRepeat = new QToolButton(this);
    QToolButton* btnRandom = new QToolButton(this);
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

public slots:
    void clicked_onPlay();
    void clicked_onNext();
    void clicked_onPrevious();
    void clicked_onFavourite();
    void clicked_onVolume();
    void clicked_onRepeat();
    void clicked_onRandom();


};
