#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  double area;
  cout << "Enter the floor area, in square feet: ";
  cin >> area;

  double side;
  side = sqrt(area);
  cout << "That's equivalent of a square " << side << "feet to the side." << endl;

  return 0;
}
