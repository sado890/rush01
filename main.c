#include <unistd.h>
#include <stdlib.h>

void print_board(int **game);

int	main(int arg_count, char **arg_values)
{
	int	**game;
	int	i;
	int	x;
	int	row;
	int	col;

    i = 0;
    x = 0;
    row = 0;
    col = 0;
	if (arg_count != 2)
	{
		write(1, "error\n", 6);
		return (1);
	}
	game = malloc(4 * sizeof(int *));
    while (i < 4)
	{
		game[i] = malloc(4 * sizeof(int));
		if (!game[i])
			return (1);
		i++;
	}
	i = 0;
	char prev = 0;
    while (arg_values[1][x] && i < 16)
    {
		row = i / 4;
	    col = i % 4;
	    if (arg_values[1][x] >= '1' && arg_values[1][x] <= '4')
	    {
	    	game[row][col] = arg_values[1][x] - '0';
    		i++;
	    }
	    else if (arg_values[1][x] == ' ' && prev == ' ')
	    {
	    	game[row][col] = -1;
	    	i++;
    	}
	    else if (arg_values[1][x] != ' ')
	    {
	    	write(1, "gecersiz karakter\n", 18);
	    	return (1);
	    }
	    prev = arg_values[1][x];
    	x++;
    }
	if (i != 16)
	{
		write(1, "eksik veri\n", 11);
		return (1);
	}
    print_board(game);
    i = 0;
    while (i < 4)
    {
	    free(game[i]);
	    i++;
    }
    free(game);
	    return (0);
}

void    print_board(int **game)
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
            if (game[i][j] == -1)
                write(1, ". ", 2);
            else
            {
                c = game[i][j] + '0';
                write(1, &c, 1);
                write(1, " ", 1);
            }
            j++;
        }
        write(1, "\n", 1);
        i++;
    }
}