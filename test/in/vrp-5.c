/* { dg-require-effective-target int32plus } */
void exit(int);
void abort();

void test(int a, int b)
{
    if (a < 5)
        abort();
    if (b < 5)
        abort();
    if (a + b != 0U)
        abort();
}

int main()
{
    int x = 0x80000000;
    test(x, x);
    exit(0);
}
