#include "Karen.hpp"

typedef enum e_level {
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	LDEFAULT
}			level;

static std::string deEnum(level lev) {
	std::string levs[] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR",
		"LDEFAULT"
    };
	return levs[lev];
}

static level	inEnum(std::string lev) {
	std::string levs[] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	for (int i = 0; i < 4; i++)
	{
		if (lev == levs[i])
			return (level)i;
	}
	return LDEFAULT;
}

static void	mainSwitch(level eLev, Karen &karen){
	std::string	lev(deEnum(eLev));

	switch(eLev)
	{
		case DEBUG:
			std::cout << "[ DEBUG ]" << std::endl;
			karen.complain(lev);
			std::cout << std::endl;
			mainSwitch(INFO, karen);
			return;
		case INFO:
			std::cout << "[ INFO ]" << std::endl;
			karen.complain(lev);
			std::cout << std::endl;
			mainSwitch(WARNING, karen);
			return;
		case WARNING:
			std::cout << "[ WARNING ]" << std::endl;
			karen.complain(lev);
			std::cout << std::endl;
			mainSwitch(ERROR, karen);
			return;
		case ERROR:
			std::cout << "[ ERROR ]" << std::endl;
			karen.complain(lev);
			std::cout << std::endl;
			return;
		default:
			std::cout << "[ Probably complaining about"
			" insignificant problems ]" << std::endl;
			std::cout << std::endl;
			return;
	}
}

int	main(int c, char **v){
	if (c != 2)
	{
		std::cout << "Error: Wrong number of arguments." << std::endl;
		return 1;
	}
	Karen 		karen;
	std::string lev(v[1]);
	level		eLev(inEnum(lev));

	mainSwitch(eLev, karen);

	return 0;	
}