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



#include <YSI_Coding\y_hooks>

// variables;
static MySQL: handler;

// hooks;
hook OnGameModeInit()
{
	MySQL_CreateConnection();

	return Y_HOOKS_CONTINUE_RETURN_1;
}

// functions;
static MySQL_CreateConnection()
{
	new hostname[10];
	if (Env_Has("MYSQL_HOSTNAME"))
	{
		Env_Get("MYSQL_HOSTNAME", hostname, sizeof hostname);
	}

	new username[5];
	if (Env_Has("MYSQL_USER"))
	{
		Env_Get("MYSQL_USER", username, sizeof username);
	}

	new database[8];
	if (Env_Has("MYSQL_DATABASE"))
	{
		Env_Get("MYSQL_DATABASE", database, sizeof database);
	}


	new MySQLOpt: options = mysql_init_options();
	mysql_set_option(options, AUTO_RECONNECT, true);
	mysql_set_option(options, MULTI_STATEMENTS, true);
	mysql_set_option(options, POOL_SIZE, 2);

	handler = mysql_connect(hostname, username, "", database, options);


	if (mysql_errno(handler) != 0)
	{
		err("[MySQL]: Can't connect to database!");

		SendRconCommand("exit");
		return 1;
	}

	log("[MySQL]: Successfully connected to database.");

	return 1;
}

hook OnGameModeExit()
{
	if (!mysql_close(handler))
	{
		fatal("Failed to terminate the database connection. Please check this.");
	}

	return Y_HOOKS_CONTINUE_RETURN_1;
}

// callback;
public OnQueryError(errorid, const error[], const callback[], const query[], MySQL:handle)
{
	return 1;
}
