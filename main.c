#include <unistd.h>
#include <stdlib.h>

void    malloc_game(int ***game);
void    malloc_board(int ***board);
void    check_argc(int arg_count, char **arg_values);
void    check_argv(int arg_count, char **arg_values, int **game);
void    finish_program(int **game, int **board);
void    solve(int **board, int **game);
void    print_board(int **board);
void    fill_guaranteed_indexs(int **game, int **board);
void    fill_other_indexs(int **game, int **board);
void    do_top_g(int **game, int **board, int col);
void    do_bottom_g(int **game, int **board, int col);
void    do_left_g(int **game, int **board, int row);
void    do_right_g(int **game, int **board, int row);
void    check_colrows(int **board, int row, int col);

int main(int arg_count, char **arg_values)
{
	int	**game;
    int **board;

    check_argc(arg_count, arg_values);
	malloc_game(&game);
    malloc_board(&board);
    check_argv(arg_count, arg_values, game);
    solve(board, game);
    print_board(board);
    finish_program(game, board);
    return (0);
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
void    solve(int **board, int **game)
{
    fill_guaranteed_indexs(game, board);
    fill_other_indexs(game, board);
    print_board(board);
}
void	fill_guaranteed_indexs(int **game, int **board)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		do_top_g(game, board, i);
        do_bottom_g(game, board, i);
        do_left_g(game, board, i);
        do_right_g(game, board, i);
		i++;
	}
}
void    check_argc(int arg_count, char **arg_values)
{
    if (arg_count != 2)
    {
        write(1, "eksik veri\n", 11);
        exit(1);
    }
}
void    check_argv(int arg_count, char **arg_values, int **game)
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
	    	exit(1);
	    }
	    last = arg_values[1][x];
    	x++;
    }
	if (i != 16)
	{
		write(1, "eksik veri\n", 11);
		exit(1);
	}
}
void    finish_program(int **game, int **board)
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
        free(game[i]);
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
    int j;

    *board = (int **)malloc(sizeof(int *) * 4);
    i = 0;
    while (i < 4)
    {
        (*board)[i] = (int *)malloc(sizeof(int) * 4);
        j = 0;
        while (j < 4)
        {
            (*board)[i][j] = -1;
            j++;
        }
        i++;
    }
}
void    do_top_g(int **game, int **board, int col)
{
    if (game[0][col] == 1)
        board[0][col] = 4;
    else if (game[0][col] == 4)
    {
	    int row = 0;
	    while (row < 4)
	    {
	    	board[row][col] = row + 1;
	    	row++;
	    }
    }
    
    if (game[0][col] == 2 && game[1][col] == 3)
    {
        board[1][col] = 4;
    }
    else if (game[0][col] == 3 && game[1][col] == 2)
    {
        board[2][col] = 4;
    }
    else if (game[0][col] == 3 && game[1][col] == 1)
    {
        board[0][col] = 2;
        board[1][col] = 3;
    }
}
void    do_bottom_g(int **game, int **board, int col)
{
    if (game[1][col] == 1)
        board[3][col] = 4;
    else if (game[1][col] == 4)
    {
        int row = 0;
        while (row < 4)
        {
            board[3 - row][col] = row + 1;
            row++;
        }
    }

    if (game[1][col] == 2 && game[0][col] == 3)
    {
        board[2][col] = 4;
    }
    else if (game[1][col] == 3 && game[0][col] == 2)
    {
        board[1][col] = 4;
    }
    else if (game[1][col] == 3 && game[0][col] == 1)
    {
        board[3][col] = 2;
        board[2][col] = 3;
    }
}
void    do_left_g(int **game, int **board, int row)
{
    if (game[2][row] == 1)
        board[row][0] = 4;
    else if (game[2][row] == 4)
    {
        int col = 0;
        while (col < 4)
        {
            board[row][col] = col + 1;
            col++;
        }
    }

    if (game[2][row] == 2 && game[3][row] == 3)
    {
        board[row][1] = 4;
    }
    else if (game[2][row] == 3 && game[3][row] == 2)
    {
        board[row][2] = 4;
    }
    else if (game[2][row] == 3 && game[3][row] == 1)
    {
        board[row][0] = 2;
        board[row][1] = 3;
    }
}
void    do_right_g(int **game, int **board, int row)
{
    if (game[3][row] == 1)
        board[row][3] = 4;
    else if (game[3][row] == 4)
    {
        int col = 0;
        while (col < 4)
        {
            board[row][3 - col] = col + 1;
            col++;
        }
    }

    if (game[3][row] == 2 && game[2][row] == 3)
    {
        board[row][2] = 4;
    }
    else if (game[3][row] == 3 && game[2][row] == 2)
    {
        board[row][1] = 4;
    }
    else if (game[3][row] == 3 && game[2][row] == 1)
    {
        board[row][3] = 2;
        board[row][2] = 3;
    }
}
void    fill_other_indexs(int **game, int **board)
{
	int row;
	int col;

	(void)game;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			if (board[row][col] == -1)
				check_colrows(board, row, col);
			col++;
		}
		row++;
	}
}
void    check_colrows(int **board, int row, int col)
{
	int arr[4] = {1, 2, 3, 4};
	int temparr[4];
	int i;

	int count = 0;
	i = 0;
	while (i < 4)
	{
		if (board[row][i] >= 1 && board[row][i] <= 4)
			arr[board[row][i] - 1] = 0;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (board[i][col] >= 1 && board[i][col] <= 4)
			arr[board[i][col] - 1] = 0;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (arr[i] != 0 && count < 4)
		{
			temparr[count] = arr[i];
			count++;
		}
		i++;
	}
	if (count == 1)
		board[row][col] = temparr[0];
}