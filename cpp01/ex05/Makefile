CFLAGS = -ggdb -Wall -Wextra -Werror -std=c++98
CC = g++

TARGET = harl_2.0
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
	rm -f $(OBJS)

.PHONY: fclean
fclean: clean
	rm -f $(TARGET)


.PHONY: re
re: clean all

