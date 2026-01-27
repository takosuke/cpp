CFLAGS = -ggdb -Wall -Wextra -Werror -std=c++98
CC = g++

TARGET = phonebook_app
#SOURCE = PhoneBook.cpp phonebook_app.cpp
SOURCE = $(wildcard *.cpp)
OBJS := $(SOURCE:.cpp=.o)

.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET) 

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(TARGET)

.PHONY: fclean
fclean: clean

.PHONY: re
re: clean all

