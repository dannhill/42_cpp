#include "Karen.hpp"

Karen::Karen() {
	return;
}

Karen::~Karen() {
	return;
}

typedef	void (Karen::*fptr)(void);

void	Karen::complain(std::string level) {
	std::string	levels[] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
		fptr	func[] = {
		&Karen::debug,
		&Karen::info,
		&Karen::warning,
		&Karen::error
	};
	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
			(this->*func[i])();
	}
	return;
}

void	Karen::debug(void) {
	std::cout << "I love to get extra levels for my AAA-FirstPersonShooter-RolePlayingGame-Action-Adventure";
	std::cout << "-StoryDriven-Simulative-Arcade videogame. I just love it!" << std::endl;
	return;
}

void	Karen::info(void) {
	std::cout << "I can't believe more levels cost money. ";
	std::cout << "You don't put enough! ";
	std::cout << "If you did i would not have to ask for it!"	<< std::endl;
	return;
}

void	Karen::warning(void) {
	std::cout << "I think I deserve to have some extra levels for free. "
	 "I’ve been playing this game for years and you just "
	 "started fixing it last month." << std::endl;
	return;
}

void	Karen::error(void) {
	std::cout << "This is unacceptable, I want to speak to the "
	"game director now." << std::endl;
	return;
}