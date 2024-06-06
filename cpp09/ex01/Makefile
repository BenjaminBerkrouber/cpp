NAME = RPN
CC = c++
CFLAGS = -g -std=c++98 -Wall -Wextra -Werror
SRC = main.cpp srcs/RPN.cpp
INC = RPN.hpp
OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))
INCLUDES_DIR = includes/
DEPS = $(addprefix $(INCLUDES_DIR), $(INC))

RED=\033[0;31m
GREEN=\033[0;32m
BLUE=\033[0;34m
NC=\033[0m

all: $(NAME) end

$(NAME): compilat $(OBJ)
	@echo "$(BLUE)----------Creating the executable----------$(NC)"
	@echo " $(NAME)"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

compilat:
	@echo "$(BLUE)----------Compiling----------$(NC)"

debug: CFLAGS += -DDEBUG=1

debug: clean all

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
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re end
