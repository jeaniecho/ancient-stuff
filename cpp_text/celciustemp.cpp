#include <iostream>
using namespace std;

double fahrenheit(double);

int main()
{
  cout << "Please enter a Celcius value: ";
  double celcius;
  cin >> celcius;
  fahrenheit(celcius);
  double result = fahrenheit(celcius);
  cout << celcius << " degrees Celcius is " << result << " Fahrenheit." << endl;
  return 0;
}

double fahrenheit(double n)
{
  return 1.8 * n + 32.0;
}
