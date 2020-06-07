
int arr[] = {1, 2, 3, 4};
int a = 1234;

int fib(int n) {
  if (n <= 2)
    return 1;
  else
    return fib(n - 1) + fib(n - 2);
}

int main() {
  int b = -(a);
  a = a + 1;
  a = a - 2;
  a = a * 3;
  a = a / 4;
  a = a % 5;
  // a = 4

  if (a > 0)
    b = a;
  else if (a == 0)
    b = 0;
  else
    b = -(a);

  if (b > 0)
    b = fib(b);
  // b = 4

  arr[3] = a + b;
  // arr[3] = 8

  int c = 10;
  int sum = 0;
  while (c > 0) {
    sum = sum + c;
    c = c - 1;
  }

  return sum + arr[3];
}