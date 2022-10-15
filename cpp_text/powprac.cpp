#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  cout << "Enter your lower number of power: ";
  double lower;
  cin >> lower;
  cout << "Enter your upper number of power: ";
  double upper;
  cin >> upper;
  double result = pow(lower, upper);
  cout << "Your reulst is " << result << endl;

  return 0;
}
