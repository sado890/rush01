int    ft_is_invalid(int tavuk, int doner)
{
    if((tavuk == 1 && (doner == 1 || doner == 2 || doner == 3)) ||
       (tavuk == 2 && doner == 4) ||
       (tavuk == 3 && doner == 4) ||
       (tavuk == 4 && (doner == 2 || doner == 3)))
    {
        return (1);
    }
    return (0);
}

void    ft_is_solvable(int **game)
{
    int    i;
    int    x;

    x = 0;
    i = 0;
    while (i < 2)
    {
        while (x < 4)
        {
            if(ft_is_invalid(game[i][x],game[i+1][x]))
            {
                exit(1);
            };
            x++;
        }
        game[0];
        game[1];
        i++;
    }
    //can be solved
}