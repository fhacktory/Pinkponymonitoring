##
## Makefile for makefile in /home/bogira_j/rendu/Cpp/BOMBERMAN/cpp_bomberman
## 
## Made by Bogiraud Julien
## Login   <bogira_j@epitech.net>
## 
## Started on  Wed Jun 25 20:03:09 2014 Bogiraud Julien
## Last update Sat Oct 11 22:17:08 2014 camill_n
##

CC                  =	clang++ -O3

RM                  =   rm -f

CFLAGS              =	-Wall

CLIB                =   -lpthread -lcurl

PPM                 =	ppm

INCLUDE_PPM         =   ./include/

DIR_PPM		    =   ./src/

SRC_PPM	            =	$(DIR_PPM)kernel/main.cpp \
			$(DIR_PPM)kernel/script.cpp \
			$(DIR_PPM)network/network.cpp \
			$(DIR_PPM)config/config.cpp \

OBJ_PPM:=         $(SRC_PPM:$(DIR_PPM)%.cpp=$(DIR_PPM)%.o)

#---RULES---

all: $(PPM)

$(DIR_BOMBERMAN)%.o: $(DIR_PPM)%.cpp
	@$(CC) -c $< -o $@ -I$(INCLUDE_PPM) $(CFLAGS)

$(PPM): $(OBJ_PPM)
	@$(CC) $^ -o $@ $(CLIB)
	@echo -e "\033[32m\t$(PPM)\t DONE !\033[0m"

clean:
	@$(RM) $(OBJ_PPM)
	@echo -e "\033[32mDirectory cleaned !\033[0m"

fclean:	clean
	@$(RM) $(PPM)

re: fclean all

.PHONY: all clean fclean re
