#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "common.h"
#include "vendor/discord-rpc/include/discord.h"

class DiscordRPC
{
public:
    DiscordRPC()
    {
        m_bIsPlaying = true;
        //Start();
    }
    ~DiscordRPC()
    {

    }
    int Start();

    void changeMusicActivity(int, int, char*);

private:
    struct DiscordState {
        discord::User currentUser;

        std::unique_ptr<discord::Core> core;
    };
    DiscordState state{};

    discord::Core* core{};
    discord::Activity activity{};
    void MusicActivityUpdate();
    volatile bool interrupted = false;
    volatile bool m_bIsPlaying = false;
};


