#include "Discord.h"
#include "chrono"
#include "Settings\Settings.h"
static int64_t eptime = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();

void Discord::Intialize()
{
    DiscordRichPresence discordPresence;

	DiscordEventHandlers Handle;
	memset(&Handle, 0, sizeof(Handle));
	Discord_Initialize("", &Handle, 1, NULL);
}
std::time_t CurrentTime = std::time(0);
void Discord::Update()
{
    DiscordRichPresence discordPresence;
    memset(&discordPresence, 0, sizeof(discordPresence));
    //string statee = "State : " + gui::state;
    discordPresence.state = Settings::GameState.c_str();
    discordPresence.details = "Playing Pubg Mobile";

    //discordPresence.startTimestamp = 1;
    discordPresence.largeImageKey = "darkness_blackbg";
    discordPresence.largeImageText = "";
    discordPresence.startTimestamp = CurrentTime;    /*discordPresence.endTimestamp = 1507665886;*/


    discordPresence.partyId = "ae488379-351d-4a4f-ad32-2b9b01c91657";
    Discord_UpdatePresence(&discordPresence);
}