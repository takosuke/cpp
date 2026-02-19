CFLAGS = -ggdb -Wall -Wextra -Werror -std=c++98
CC = c++

TARGET = phonebook_app
SOURCE = Contact.cpp PhoneBook.cpp main.cpp
OBJS := $(SOURCE:.cpp=.o)

.PHONY: all clean fclean re
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET) 

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean 
	make all
