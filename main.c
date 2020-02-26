
/*
geoffreyfaivre.fr
Build whith : gcc test.c resolve.c -L. -lft
And execut whith :
a.out "9...7...." "2...9..53" ".6..124.." "84...1.9." "5.....8.." ".31..4..." "..37..68." ".9..5.714" "47......." | cat -e
*/



void    ft_putchar(char c);
void    ft_putstr(char *str);
int no_on_line (int value, char grille[9][9], int column);
int no_on_column (int value, char grille[9][9], int line);
int no_on_block (int value, char grille[9][9], int column, int line);

void affichage (char grille[9][9])
{
    int column;
    int line;

    column = 0;
    while ( column < 9 )
    {
        line = 0;
        while ( line < 9 )
        {
            ft_putchar(grille[column][line]);
            
            line++;
            if (line < 9)
            {
                ft_putstr(" ");
            }
            else
            {
                ft_putchar('\n');
            }
        }
        column++;
    }
}

int ft_isGood (char grille[9][9], int position)
{
    int column;
    int line;
    char value;

    if (position == 9*9)
        return ( 1 );
    column = position/9;
    line = position%9;
    if (grille[column][line] != '.')
        return ( ft_isGood(grille, position+1) );
    value = '1';
    while ( value <= '9' )
    {
        if(no_on_line(value,grille,column) && 
            no_on_column(value,grille,line) &&
                no_on_block(value,grille,column,line))
        {
            grille[column][line] = value;
            if ( ft_isGood (grille, position+1) )
                return 1;
        }
        value++;
    }
    grille[column][line] = '.';
    return 0;
}

int make_tableau(char grid[9][9], char **argv)
{
    int column;
    int line;

    column = 0;
    while(column < 9)
    {
        line = 0;
        while(line < 9)
        {
            if (argv[column + 1][line] > '0' && argv[column + 1][line] <= '9' )
            {
                grid[column][line] = argv[column + 1][line] ;
            }
            else if (argv[column + 1][line] == '.')
                grid[column][line] = '.';
            else
            {
                ft_putstr("Error\n");
                return 1;
            }

            line++;
        }
        column++;
    }
    return 0;
}

int main (int argc, char *argv[])
{
    if (argc != 10)
    {
        ft_putstr("Error");
        return 1;
    }
    char grid[9][9] ;

    if (make_tableau(grid, argv))
        return 1;

    ft_isGood(grid,0);
    affichage(grid);
    return 0;
}

