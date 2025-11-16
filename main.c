#include <unistd.h>
#include <stdlib.h>

void print_board(int **game);
void fill_guaranteed_indexs(int **game, int **board);
void check_argc(int arg_count, char **arg_values);
void check_argv(int arg_count, char **arg_values, int i, int last, int x, int **game);
void malloc_game(int ***game);
void malloc_board(int ***board);
void fill_other_indexs(int **game, int **board);
void solve(int **board, int **game);
void finish_program(int **game, int **board);
void do_top(int **game, int **board, int col);
void do_bottom(int **game, int **board, int col);
void do_left(int **game, int **board, int row);
void do_right(int **game, int **board, int row);

int	main(int arg_count, char **arg_values)
{
	int	**game;
    int **board;

    check_argc(arg_count, arg_values);
	malloc_game(&game);
    malloc_board(&board);
	check_argv(arg_count, arg_values, game);
    solve(board, game);
    finish_program(int **game, int **board);
}

void    print_board(int **board)
{
    int i;
    int j;
    char c;

    i = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            if (board[i][j] == -1)
                write(1, ". ", 2);
            else
            {
                c = board[i][j] + '0';
                write(1, &c, 1);
                write(1, " ", 1);
            }
            j++;
        }
        write(1, "\n", 1);
        i++;
    }
}
void solve(int **board, int **game)
{
    fill_guaranteed_indexs(game, board);
    fill_other_indexs(game, board);
    print_board(board);
}
void	fill_guaranteed_indexs(int **game, int **board)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		// Top game
		void do_top(int **game, int **board, int col);
		// Bottom game
		void do_bottom(int **game, int **board, int col);
		// Left game
		void do_left(int **game, int **board, int row);
		// Right game
		void do_right(int **game, int **board, int row);
		i++;
	}
}
void check_argc(int arg_count, char **arg_values)
{
    if (arg_count != 2)
    {
        write(1, "eksik veri\n", 6);
        exit(1);
    }
    return (0);
}
void check_argv(int arg_count, char **arg_values, int **game)
{
    int row;
    int col;
    int x;
    int i;
    char last;

    x = 0;
    i = 0;
    last = '\0';
    while (arg_values[1][x] && i < 16)
    {
		row = i / 4;
	    col = i % 4;
	    if (arg_values[1][x] >= '1' && arg_values[1][x] <= '4')
	    {
	    	game[row][col] = arg_values[1][x] - '0';
    		i++;
	    }
	    else if (arg_values[1][x] == ' ' && last == ' ')
	    {
	    	game[row][col] = -1;
	    	i++;
    	}
	    else if (arg_values[1][x] != ' ')
	    {
	    	write(1, "gecersiz karakter\n", 18);
	    	return (1);
	    }
	    last = arg_values[1][x];
    	x++;
    }
	if (i != 16)
	{
		write(1, "eksik veri\n", 11);
		return (1);
	}
}
void finish_program(int **game, int **board)
{
    int i;
    i = 0;
    while (i < 4)
    {
        free(board[i]);
        i++;
    }
    i = 0;
    while (i < 4)
    {
        free(board[i]);
        i++;
    }
    free(board);
    free(game);
}
void    malloc_game(int ***game)
{
    int i;

    *game = (int **)malloc(sizeof(int *) * 4);
    i = 0;
    while (i < 4)
    {
        (*game)[i] = (int *)malloc(sizeof(int) * 4);
        i++;
    }
}
void    malloc_board(int ***board)
{
    int i;

    *board = (int **)malloc(sizeof(int *) * 4);
    i = 0;
    while (i < 4)
    {
        (*board)[i] = (int *)malloc(sizeof(int) * 4);
        i++;
    }
}
void do_top(int **game, int **board, int col)
{
    if (game[0][i] == 1)
			board[0][i] = 4;
	else if (game[0][i] == 4)
	{
		j = 0;
		while (j < 4)
		{
			board[j][i] = j + 1;
			j++;
		}
	}
}
void do_bottom(int **game, int **board, int col)
{
    if (game[1][i] == 1)
			board[3][i] = 4;
	else if (game[1][i] == 4)
	{
		j = 0;
		while (j < 4)
		{
			board[3 - j][i] = j + 1;
			j++;
		}
	}
}
void do_left(int **game, int **board, int row)
{
    if (game[2][i] == 1)
            board[i][0] = 4;
    else if (game[2][i] == 4)
    {
        j = 0;
        while (j < 4)
        {
            board[i][j] = j + 1;
            j++;
        }
    }
}
void do_right(int **game, int **board, int row)
{
    if (game[3][i] == 1)
            board[i][3] = 4;
    else if (game[3][i] == 4)
    {
        j = 0;
        while (j < 4)
        {
            board[i][3 - j] = j + 1;
            j++;
        }
    }
}
void fill_other_indexs(int **game, int **board)
{
}