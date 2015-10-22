/*
		Anti sprint-macro system by shendlaw
*/

#include "modules\header\antisprintmacro.txt"
#include "modules\header\colors.txt"
#include "modules\src\player.inc"
#include "modules\src\common.inc"

public TimerAntiSprintMacro(playerid)
{
	AntiSprintMacro[playerid] = 0;
	return 1;
}

public TimerAntiSprintMacroWarn(playerid)
{
    new string[150];
	
	format(string, sizeof(string), ""COL_SEC"%s "COL_PRIM"has been running like a cheetah, and since this ain't no zoo, hes kicked!",Player[playerid][Name], Player[playerid][pHealth], Player[playerid][pArmour]);
    SendClientMessageToAll(-1, string);
	
	PauseRound();
	SendClientMessageToAll(-1, ""COL_PRIM"Round has been auto-paused.");
	
	SetTimerEx("OnPlayerKicked", 500, false, "i", playerid);
	return 1;
}

public AnnounceSprintMacroUser(playerid)
{
	
	if(AntiSprintMacroWarns[playerid] == 2)
	{
		SetTimer("TimerAntiSprintMacroWarn", 1000, false);	
	}
	else
	{
	    AntiSprintMacroWarns[playerid] += 1;
	}
	return 1;
}