#include <iostream>
using namespace std;

double yard(double);

int main()
{
  cout << "Enter your distance in furlongs: ";
  double furlongs;
  cin >> furlongs;
  double result = yard(furlongs);
  cout << "Your distance in yard is " << result << " yards." << endl;
  return 0;
}

double yard(double n)
{
  return 220 * n;
}
