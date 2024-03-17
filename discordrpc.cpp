#include "discordrpc.h"

int DiscordRPC::Start()
{
    auto result = discord::Core::Create(1152688746400075876, DiscordCreateFlags_Default, &core);
    state.core.reset(core);
    

    //m_bIsPlaying = true
    char szMusic[64] = "24 - Money Man";
    char szDetails[128];

    if(m_bIsPlaying)
    {
        activity.SetState("Узнаем трек...");

        std::string partyId = "195291";

        activity.GetParty().SetId(partyId.c_str());
        activity.GetSecrets().SetJoin("Слушать вместе");
    }
    else
    {
        sprintf_s(szDetails, "AFK (%lli)", time(0));
        activity.SetDetails(szDetails);
        activity.SetState("");

    }
    activity.GetAssets().SetLargeImage("https://media1.tenor.com/m/Q823-830Ri0AAAAd/christian-bale-american-psycho.gif");
    activity.GetAssets().SetLargeText("Аналог Spotify без VPN");
    activity.SetType(discord::ActivityType::Listening);
    state.core->ActivityManager().UpdateActivity(activity, [](discord::Result result) {});

    do { 
        MusicActivityUpdate();
        state.core->RunCallbacks();
        
        std::this_thread::sleep_for(std::chrono::milliseconds(1000u));
    } while (!interrupted);
    return 0;
}

void DiscordRPC::MusicActivityUpdate()
{
    char szState[128];
    char szDetails[128];
#ifdef DEBUG_C
    int musicTimeLength = 169;
    int musicCurrentTime = 49;
    char musicName[128] = "24 - Money Man";
#else
    int musicCurrentTime = 0;
    int musicTimeLength = 0;
    char musicName[128];
#endif
    for(int i = musicCurrentTime; i <= musicTimeLength; i++)
    {
        sprintf_s(szDetails, "Слушает: %s", musicName);
        activity.SetDetails(szDetails);
        sprintf_s(szState, "Прослушано %02i:%02i из %02i:%02i", (i > 60 ? i / 60 : 0), i % 60, musicTimeLength / 60, musicTimeLength % 60);
        activity.SetState(szState);
        state.core->ActivityManager().UpdateActivity(activity, [](discord::Result result){});
    }
    
}

void changeMusicActivity(int musicTimeLength, int musicCurrentTime, char* musicName)
{
    
}