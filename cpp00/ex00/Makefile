CFLAGS = -Wall -Wextra -Werror -std=c++98
CC = g++

TARGET = megaphone
SOURCE = megaphone.cpp

.PHONY: all
all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f $(TARGET)

.PHONY: fclean
fclean: clean

.PHONY: re
re: fclean all
