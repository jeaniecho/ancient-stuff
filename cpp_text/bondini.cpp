#include <iostream>
using namespace std;

int main()
{
  cout << "\aOperation \"HyperHype\" is now activated!\n";
  cout << "Enter your agent code:________\b\b\b\b\b\b\b\b"; // "\b" == backspace
  long code;
  cin >> code;
  cout << "\aYou entered " << code << "...\n";
  cout << "\aCode verfied! Proceed with Plan Z3!\n";
  return 0;
}
