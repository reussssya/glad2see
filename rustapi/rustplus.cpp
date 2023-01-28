#include "rustplus.h"

using namespace easywsclient;
using namespace rustplus;

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
	ws->poll();
	ws->dispatch([&](const std::string& message) { appMessage.ParseFromString(message); });

}

AppTeamChat RustPlusSocket::getMessagesFromTeamChat()
{
	auto request = initProto();
	request.mutable_getteamchat()->CopyFrom(AppEmpty());
	std::string data = request.SerializeAsString();
	ws->sendBinary(data);
	AppMessage appMessage;
	do
	{
		ws->poll(-1);
		ws->dispatch([&](const std::string& message) { appMessage.ParseFromString(message); });
	} while ((!appMessage.has_response() || !appMessage.response().has_teamchat()) && !(appMessage.has_response() && appMessage.response().has_error()));
	if (appMessage.response().has_error())
		std::cout << appMessage.response().error().DebugString() << "GetTeamChat\n\n";
	return appMessage.response().teamchat();
}

AppTime RustPlusSocket::getTime()
{
	auto request = initProto();
	request.mutable_gettime()->CopyFrom(AppEmpty());
	std::string data = request.SerializeAsString();
	ws->sendBinary(data);
	AppMessage appMessage;
	do
	{
		ws->poll(-1);
		ws->dispatch([&](const std::string& message) { appMessage.ParseFromString(message); });
	} while (!appMessage.has_response() || !appMessage.response().has_time());
	if (appMessage.response().has_error())
		std::cout << appMessage.response().error().DebugString() << "GetTime\n\n";
	return appMessage.response().time();
}