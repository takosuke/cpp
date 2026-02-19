CFLAGS = -Wall -Wextra -Werror -std=c++98
CC = g++

TARGET = megaphone
SOURCE = megaphone.cpp

.PHONY: all clean fclean re
all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(TARGET)

fclean: clean

re: fclean 
	make all
