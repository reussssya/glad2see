#include "rustplus.h"

using namespace easywsclient;
using namespace rustplus;

inline bool is_return(const char& input)
{
    return input == '\n' || input == '\r';
}

std::string getLastLine (const std::string& input)
{
    if(input.length() == 1) return input;
    size_t position = input.length()-2; // last character might be a return character, we can jump over it anyway
    while((!is_return(input[position])) && position > 0) position--;
    // now we are at the \n just before the last line, or at the first character of the string
    if(is_return(input[position])) position += 1;
    // now we are at the beginning of the last line
    return input.substr(position);
}


AppRequest RustPlusSocket::initProto()
{
	AppRequest request;
	request.set_seq(uSeq);
	uSeq++;
	request.set_playerid(uSteamId);
	request.set_playertoken(iPlayerToken);
	return request;
}

void RustPlusSocket::sendTeamMessage(const char* message)
{
	AppSendMessage msg;
	msg.set_message(message);
	auto request = initProto();

	request.mutable_sendteammessage()->CopyFrom(msg);
	ws->sendBinary(request.SerializeAsString());
	AppMessage appMessage;
	//ws->poll();
	ws->dispatch([&](const std::string& message) { appMessage.ParseFromString(message); });

}

AppTeamChat RustPlusSocket::getMessagesFromTeamChat(bool bLastMsg = 0)
{
	auto request = initProto();
	request.mutable_getteamchat()->CopyFrom(AppEmpty());
	ws->sendBinary(request.SerializeAsString());
	AppMessage appMessage;
	do
	{
		ws->poll();
      	ws->dispatch([&](const std::string& message) { 	std::cout << (bLastMsg ? getLastLine(message) : message) << std::endl; });
		Sleep(1000);
	} while ((!appMessage.has_response() || !appMessage.response().has_teamchat()) && !(appMessage.has_response() && appMessage.response().has_error()));
	
	return appMessage.response().teamchat();
	while (ws->getReadyState() != WebSocket::CLOSED) 
	{
      	ws->poll();
      	ws->dispatch([&](const std::string& message) { 	std::cout << (bLastMsg ? getLastLine(message) : message) << std::endl; });
		Sleep(1000);
    }
}
AppTime RustPlusSocket::getTime()
{
	AppTime time;

	return time;
}