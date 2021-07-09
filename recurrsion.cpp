#include <iostream>
#include <cstdlib>
using namespace std;
int getFactorial(int number);
int getFibSum(int uptoNum);

int main()
{

  int choice, number = 0;
  do
  {
    cout << "\nEnter 1 to get Factorial of a number"
         << "\nEnter 2 to print Fabonacci Sum upto a number "
         << "\nEnter 0 to exit : ";
    cin >> choice;
    switch (choice)
    {
    case 0:
      exit(0);
      break;
    case 1:
      cout << "\nEnter the number to get it's Factorial : ";
      cin >> number;
      cout << "\nFactorial of " << number << " is " << getFactorial(number) << "\n";
      break;
    case 2:
      cout << "\nEnter the number to get it's Fabonacci Sum : ";
      cin >> number;
      cout << "\nFabonacci sum of " << number << " is " << getFibSum(number) << "\n";
      break;
    default:
      cout << "\nInvalid Choice, Enter a valid number !";
      break;
    }
  } while (choice != 0);

  return 0;
}

int getFactorial(int number)
{
  if (number == 0)
  {
    return 1;
  }
  return number * getFactorial(number - 1);
}
int getFibSum(int uptoNum)
{
  if (uptoNum < 3)
  {
    return 1;
  }
  return getFibSum(uptoNum - 2) + getFibSum(uptoNum - 1);
}