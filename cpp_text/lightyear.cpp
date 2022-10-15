#include <iostream>
using namespace std;

double lightyear(double);

int main()
{
  cout << "Enter the number of light years: ";
  double light;
  cin >> light;
  double result = lightyear(light);
  cout << light << " light years = " << result << " astronomical units." << endl;
  return 0;
}

double lightyear(double n)
{
  return 63240 * n;
}
