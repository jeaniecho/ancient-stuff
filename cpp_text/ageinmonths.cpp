#include <iostream>
using namespace std;

int monthAge(int);

int main()
{
  cout << "Enter your age: ";
  int age;
  cin >> age;
  int result = monthAge(age);
  cout << "Your age in months is " << result << endl;

  return 0;
}

int monthAge(int n)
{
  return 12 * n;
}
