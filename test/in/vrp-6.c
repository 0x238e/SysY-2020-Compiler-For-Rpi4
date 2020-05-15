/* { dg-require-effective-target int32plus } */

void exit(int);
void abort();

void test01(int a, int b)
{
    if (a < 5)
        abort();
    if (b < 5)
        abort();
    if (a - b != 5)
        abort();
}

void test02(int a, int b)
{
    if (a >= 12)
        if (b > 15)
            if (a - b < UINT_MAX - 15U)
                abort();
}

int main()
{
    unsigned x = 0x80000000;
    test01(x + 5, x);
    test02(14, 16);
    exit(0);
}
