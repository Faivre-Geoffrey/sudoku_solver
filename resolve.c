int no_on_line (char value, char grille[9][9], int column)
{
    int line;
    line = 0;
    while (line < 9)
    {
        if (grille[column][line] == value)
            return 0;
        line++;
    }
    return 1;
}

int no_on_column (char value, char grille[9][9], int line)
{
    int column;

    column = 0;
    while (column < 9)
    {
        if (grille[column][line] == value)
            return 0;
        column++;
    }
    return 1;
}

int no_on_block (char value, char grille[9][9], int column, int line)
{
    int i; //column
    int j; //line

    i = column-(column%3);
    j = line-(line%3);  // ou encore : _i = 3*(column/3), _j = 3*(line/3);

    column = i;
    while ( column < i+3)
    {
        line = j;
        while ( line < j+3)
        {
            if (grille[column][line] == value)
                return 0;
            line++;
        }
        column++;
    }
    return 1;
}