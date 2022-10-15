#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
  int guess;
  bool isCorrect = false;

  int randNum = rand() % 99 + 1;  // Generate random number

  int guessTime = 0;

  cout << "Welcome to the Number Guessing Game !";
  cin.get();
  cout << "Choose your number between 1 to 99 : ";

  while (isCorrect == false) {
    cin >> guess;
    guessTime++;

    if (guess < randNum) {
      cout << "It's too small..." << endl;
      cout << "Try another one : ";
    }

    else if (guess > randNum) {
      cout << "It's too big..." << endl;
      cout << "Try another one : ";
    }

    else if (guess <= 0 || guess >= 100) {
      cout << "The number is out of range..." << endl;
      cout << "Try again : ";
    }

    else if (guess == randNum) {
      cout << "You won with " << guessTime << " guesses, Congratulations!" << endl;
      isCorrect = true;

      break;
    }
  }
  return 0;
}
