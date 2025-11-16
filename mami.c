#include <unistd.h>
int    ft_is_invalid(int tavuk, int doner)
{
    int     toplam;
    
    toplam = tavuk + doner;
    if(toplam == 2)
    {
        return (1);
    }
    if(toplam >= 6 && toplam <= 8)
    {
        return (1);
    }
    return (0);
    /* bunu burada bıraktım çünkü anlatırken teker teker göstermektense direkt buraya bakarız
    
    if((tavuk == 1 && doner == 1) 2||
       (tavuk == 2 && doner == 4)  6||
       (tavuk == 3 && (doner == 3 || doner == 4))  6 veya 7||
       (tavuk == 4 && (doner == 2 || doner == 3 || doner == 4))) 6 veya 7 veya 8 
       {
        return (1);
        }
        return (0);*/
}
int    ft_is_solvable(int **game)
{
    int    i;
    int    x;

    x = 0;
    i = 0;
    while (i < 4)
    {
        x = 0;
        while (x < 4)
        {
            if(ft_is_invalid(game[i][x],game[i+1][x]))
            {
                return (1);
            };
            x++;
        }
        i = i + 2;
    }
    return (0);
}