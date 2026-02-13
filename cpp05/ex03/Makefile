CFLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++

TARGET = burrocracia
SOURCE = Bureaucrat.cpp AForm.cpp main.cpp PresidentialPardonForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp Intern.cpp
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
