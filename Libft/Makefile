#VARIABLES:
NAME = libft.a
.SILENT:
AR = ar rcs
RM = rm -f
CC = gcc
CCFLAGS = -Wall -Wextra -Werror

#SOURCES:
SRC_FILES =	ft_memset ft_bzero ft_strlen ft_atoi ft_atol ft_isdigit ft_isalpha\
ft_isprint ft_isascii ft_isalnum ft_memchr ft_memcpy\
ft_memcmp ft_memmove ft_strchr ft_strdup ft_strlcat ft_strlcpy\
ft_strncmp ft_toupper ft_tolower ft_strnstr ft_strrchr ft_calloc ft_substr\
ft_strtrim ft_split ft_strjoin ft_itoa ft_strmapi ft_striteri ft_putchar_fd\
ft_putstr_fd ft_putendl_fd ft_putnbr_fd\

### 

OBJ_DIR = obj/
SRC		= $(addsuffix .c, $(SRC_FILES))
OBJS	= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
#OBJS = $(SRC_FILES:%.c=OBJ_DIR:%.o)
OBJSF	= .cache_exists

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@ranlib $(NAME)

$(OBJ_DIR)%.o: %.c | $(OBJSF)
	$(CC) $(CCFLAGS) -c $< -o $@

$(OBJSF):
		@mkdir -p $(OBJ_DIR)

clean:
	$(RM) -rf $(OBJ_DIR)
	$(RM) $(OBJSF)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean