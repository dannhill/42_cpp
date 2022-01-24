#pragma once
#include <iostream>
#include <string>

class Karen {
	public:
		Karen();
		~Karen();

		void	complain(std::string level);
		int		ciao;
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
};