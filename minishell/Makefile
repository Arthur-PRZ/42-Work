CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = src/
OBJDIR = obj/
LIBFTDIR = libft

SRC_FILES = main/main main/handle_input main/free_main parser/errors_managements2 lexer/tokenizer lexer/split  \
	lexer/is_valid_cmd lexer/quotes_checks lexer/quotes_clean lexer/sizeofany lexer/tokenizer_utils parser/ast \
	lexer/split_utils lexer/clean_tokens1 lexer/clean_tokens2 signals/signals2 signals/signals \
	parser/ast_util parser/errors_managements lexer/env_utils exec/exec exec/redirection exec/redirection2 exec/exec_heredoc\
	exec/get_cmd_path exec/env_exec exec/exec_cmd exec/exec_export exec/exec_unset exec/free exec/some_builtins \
	exec/exec_exit exec/exec_pipe exec/exec_utils exec/set_env_value exec/exec_heredoc2 exec/cd_utils
SRC = $(addprefix $(SRCDIR), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJDIR), $(addsuffix .o, $(SRC_FILES)))
NAME = minishell
LIBFT = $(LIBFTDIR)/libftprintf.a

G = \033[1;92m
RST = \033[0m

all: $(OBJDIR) $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L$(LIBFTDIR) -lftprintf -lreadline -ltermcap
	@echo "$(G)Compilation done!$(RST)"

$(OBJDIR)%.o: $(SRCDIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(G)Compiling..$(RST)"

$(OBJDIR):
	@mkdir -p $(OBJDIR)
	@mkdir -p $(OBJDIR)/main
	@mkdir -p $(OBJDIR)/lexer
	@mkdir -p $(OBJDIR)/exec
	@mkdir -p $(OBJDIR)/parser
	@mkdir -p $(OBJDIR)/signals

$(LIBFT):
	@make --no-print-directory -C $(LIBFTDIR)

clean:
	@rm -rf $(OBJDIR)
	@make clean --no-print-directory -C $(LIBFTDIR)
	@echo "$(G)Cleaned OBJ files$(RST)"

fclean: clean
	@rm -rf $(NAME)
	@make fclean --no-print-directory -C $(LIBFTDIR)
	@echo "$(G)All clean$(RST)"

re: fclean all
	@echo "$(G)Cleaned and Compiled$(RST)"

.PHONY: all clean fclean re
