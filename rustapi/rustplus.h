#pragma once
#include "includes/proto/rustapi.pb.h"

// websockets
#include "includes/easyws/easywsclient.hpp"

#include <string>
#include <cstdint>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <Windows.h>

using namespace easywsclient;

using namespace rustplus;

class RustPlusSocket
{
public:   
    RustPlusSocket(const char* host = "178.32.14.213", const char*  port = "27121", uint64_t uSteamId = 76561199198207009, int32_t iPlayerToken = 1430174311)
    {
#ifdef _WIN32
        INT rc;
        WSADATA wsaData;
        rc = WSAStartup(MAKEWORD(2, 2), &wsaData);
        if (rc)
            std::cout << "WSAStartup Failed.\n";
#endif
        url += host;
        url += ":";
        url += port;

        this->uSteamId = uSteamId;
        this->iPlayerToken = iPlayerToken;

        std::cout << "Connecting to " << url << " ..." << std::endl;

        ws = WebSocket::from_url(url);

        if (ws)
            std::cout << "Connected!\n";
        else
            std::cout << "we have problems :(\n";
    }
    ~RustPlusSocket()
    {
        ws->close();
        ws = nullptr;
        delete ws;
    }
    rustplus::AppRequest initProto();
    
    void sendTeamMessage(const char* message);
    rustplus::AppTeamChat getMessagesFromTeamChat();
    rustplus::AppTime getTime();

    WebSocket::pointer ws = nullptr;
private:

    std::string url = "ws://";

    uint64_t uSteamId;
    int32_t iPlayerToken;

    uint32_t uSeq = 0;
};