NAME	= phonebook
SRCS	= $(wildcard *.cpp) # IS THIS ALLOWED???
OBJS	= $(SRCS:.cpp=.o)
CXX		= c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
