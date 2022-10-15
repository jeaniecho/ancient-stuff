#include <iostream>
using namespace std;

int main()
{
  int chest = 42;
  int waist = 42;
  int inseam = 42;

  cout << "Monsieur cuts a striking figue!\n";
  cout << "chest = " << chest << " (42 in decimal)\n";
  cout << hex;
  cout << "waist = " << waist << " (0x42 in hex)\n";
  cout << oct;
  cout << "inseam = " << inseam << " (042 in octal)\n";
  return 0;
}
