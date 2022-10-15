#include <iostream>
using namespace std;

void mice(int);
void run(int);

int main()
{
  mice(2);
  run(2);

  return 0;
}

void mice(int n)
{
  while(n > 0)
  {
    cout << "Three blind mice" << endl;
    n--;
  }
}

void run(int m)
{
  while(m > 0)
  {
    cout << "See how they run" << endl;
    m--;
  }
}
