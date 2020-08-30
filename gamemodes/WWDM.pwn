/*

		░██╗░░░░░░░██╗░█████╗░██████╗░██╗░░░░░██████╗░░██╗░░░░░░░██╗██╗██████╗░███████╗
		░██║░░██╗░░██║██╔══██╗██╔══██╗██║░░░░░██╔══██╗░██║░░██╗░░██║██║██╔══██╗██╔════╝
		░╚██╗████╗██╔╝██║░░██║██████╔╝██║░░░░░██║░░██║░╚██╗████╗██╔╝██║██║░░██║█████╗░░
		░░████╔═████║░██║░░██║██╔══██╗██║░░░░░██║░░██║░░████╔═████║░██║██║░░██║██╔══╝░░
		░░╚██╔╝░╚██╔╝░╚█████╔╝██║░░██║███████╗██████╔╝░░╚██╔╝░╚██╔╝░██║██████╔╝███████╗
		░░░╚═╝░░░╚═╝░░░╚════╝░╚═╝░░╚═╝╚══════╝╚═════╝░░░░╚═╝░░░╚═╝░░╚═╝╚═════╝░╚══════╝

		██████╗░███╗░░░███╗
		██╔══██╗████╗░████║ 𝘎𝘢𝘮𝘦𝘮𝘰𝘥𝘦: 𝘞𝘰𝘳𝘭𝘥𝘸𝘪𝘥𝘦 𝘋𝘦𝘢𝘵𝘩𝘔𝘢𝘵𝘤𝘩
		██║░░██║██╔████╔██║ 𝘈𝘶𝘵𝘩𝘰𝘳: 𝘌𝘮𝘮𝘦𝘵𝘵
		██║░░██║██║╚██╔╝██║ 𝘋𝘢𝘵𝘦: 28𝘵𝘩 𝘈𝘶𝘨𝘶𝘴𝘵
		██████╔╝██║░╚═╝░██║ 𝘊𝘰𝘱𝘺𝘳𝘪𝘨𝘩𝘵 © 2020 𝘈𝘭𝘭 𝘳𝘪𝘨𝘩𝘵𝘴 𝘳𝘦𝘴𝘦𝘳𝘷𝘦𝘥.
		╚═════╝░╚═╝░░░░░╚═╝
*/


// stdlib;
const MAX_PLAYERS = (20);

#include <a_samp>


// libraries;
#include <a_mysql>
#include <env>

// logger;
#define SAMP_LOGGER_COMPAT
#include <logger>

#include <streamer>

// ysi packages;
#define YSI_NO_HEAP_MALLOC
#include <YSI_Coding\y_timers>
#include <YSI_Coding\y_iterate>

#include <sscanf2>

// pawnplus;
#include <PawnPlus>
#include <pp-mysql>

// modules;
#include <database/database_init>


main()
{
	log("Gamemode successfully initialised.");
	assert(MAX_PLAYERS == GetMaxPlayers());
}
