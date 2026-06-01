NAME = ex03
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra
SRCS = main.cpp Fixed.cpp bsp.cpp Point.cpp
OBJS = $(SRCS:%.cpp=%.o)

all: $(NAME)
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:clean
	rm -f $(NAME)

re:fclean all

.PHONY:all clean fclean re