NAME = DiamondTrap
CC = c++
CFLAGS = -g -std=c++98 -Wall -Wextra -Werror -Wshadow  -Wno-shadow
SRC = main.cpp  srcs/ClapTrap.cpp srcs/printer.cpp srcs/ScavTrap.cpp srcs/FragTrap.cpp srcs/DiamondTrap.cpp
INC =  ClapTrap.hpp  ClapTrap.h ScavTrap.hpp ScavTrap.h FragTrap.hpp FragTrap.h DiamondTrap.hpp DiamondTrap.h
OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))
INCLUDES_DIR = includes/
DEPS = $(addprefix $(INCLUDES_DIR), $(INC))

RED=\033[0;31m
GREEN=\033[0;32m
BLUE=\033[0;34m
NC=\033[0m

all: start $(NAME) end

start:
	@echo " "
	@echo "$(GREEN)----------Starting the compilation of $(NAME)----------$(NC)"
	@echo "$(BLUE)"
	@echo "  ____  ____  ____         _      ____  "
	@echo " / ___||  _ \|  _ \       / _ \  |___ \ "
	@echo "| |    | |_) | |_) |  == | | | |   __) |"
	@echo "| |___ |  __/|  __/   == | |_| | / __/ "
	@echo " \____||_|   |_|          \___/ |_____| "
	@echo "$(NC)"

$(NAME): compilat $(OBJ)
	@echo "$(BLUE)----------Creating the executable----------$(NC)"
	@echo " $(NAME)"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

compilat:
	@echo "$(BLUE)----------Compiling----------$(NC)"


$(OBJ_DIR)%.o: %.cpp $(DEPS)
	@echo " $<"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I$(INCLUDES_DIR) -c $< -o $@

end:
	@echo "$(GREEN)----------Successfully compiled!----------$(NC)"
	@echo " "

clean:
	@echo "$(RED)----------Cleaning up files----------$(NC)"
	@echo " $(OBJ_DIR)"
	@echo " "
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(RED)----------Full cleanup...----------$(NC)"
	@echo " "
	@rm -rf $(NAME) a.out

re: fclean all

.PHONY: all clean fclean re start end
