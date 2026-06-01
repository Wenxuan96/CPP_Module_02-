# Compiler and flags
NAME = ex00
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra

# Source and object files
SRCS = Fixed.cpp main.cpp
OBJS = $(SRCS:%.cpp=%.o)

# Default target
all: $(NAME)

# Link object files into executable
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# Compile each .cpp into .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Remove object files
clean:
	rm -f $(OBJS)

# Remove object files and executable
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re