SOURCES	= Bureaucrat.cpp Form.cpp \
			ShrubberyCreationForm.cpp \
			RobotomyRequestForm.cpp \
			PresidentialPardonForm.cpp \
			Intern.cpp \
			main.cpp 

NAME = Throw

CC = clang++

CFLAGS = -std=c++98 -Wall -Wextra -Werror

OBJS = $(SOURCES:%.cpp=objs/%.o)
ODIR = objs

all : $(NAME)

$(NAME)	: $(ODIR) $(OBJS)
		@echo "Linking..."
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
		@say "🤬🤬🤬"

$(ODIR)/%.o : %.cpp
		@echo "Compiling file..."
		@$(CC) $(CFLAGS) -c $< -o $@

clean:
		@echo "Removing executable..."
		@rm -f $(NAME)
		@rm -f *_shrubbery

fclean: clean
		@echo "Removing object files..."
		@rm -rf objs

re:		fclean all

$(ODIR) :
		@mkdir objs

.PHONY: all clean fclean re
