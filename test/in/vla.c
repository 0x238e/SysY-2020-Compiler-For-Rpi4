void abort();

int bork[4][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
void function(int width, int data[][width])
{
    int i, j;
    while ( i < 4)
        while ( j < width)
            if (bork[i][j] != data[i][j])
                abort();
}

void test()
{
    function(3, bork);
}

int bork2[2][3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24};
void function2(int width, int width2, int data[][width][width2])
{
    int i, j, k;
    while ( i < 2)
        while ( j < width)
            while ( k < width2)
                if (bork2[i][j][k] != data[i][j][k])
                    abort();
}

void test2()
{
    function2(3, 4, bork2);
}
int main()
{
    test();
    test2();
    return 0;
}
