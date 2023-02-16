#include <iostream>
#include <ctime>
using namespace std;

int playerRandomNumber();
int computerGuessNumber(int playerSecretNumber, int high, int low);
void printAnswer(int guess, int playerSecretNumber);
int isContinue(int number);

int main()
{
    int playerSecretNumber;
    int guess;
    bool isPlaying = true;
    int high = 100, low = 0;
    cout << "Press your Secret Number (this number is in [0; 100]): ";
    playerSecretNumber = playerRandomNumber();
    cout << endl;
    do
    {
        guess = computerGuessNumber(playerSecretNumber, high, low);
        cout << "Computer's number guess is: " << guess << endl;
        cout << endl;
        if (guess > playerSecretNumber)
            high = guess - 1;
        else
            low = guess + 1;
        printAnswer(guess, playerSecretNumber);
        cout << endl;
        if (guess == playerSecretNumber)
        {
            isPlaying = false;
        }
    }   while (isPlaying);
    cout << "Thanks for playing!" << endl;
    return 0;
}

int playerRandomNumber()
{
    int number;
    cin >> number;
    return number;
}

int computerGuessNumber(int playerSecretNumber, int high, int low)
{
    int guess = rand();
    guess = (guess % (high - low + 1)) + low;
    return guess;
}

void printAnswer(int guess, int playerSecretNumber)
{
    if (guess > playerSecretNumber)
        cout << "Your number is bigger than my Secret Number!" << endl;
    else if (guess < playerSecretNumber)
        cout << "Your number is smaller than my Secret Number!" << endl;
    else
        cout << "Congratulations! You've got my Secret Number!! My Secret Number is: " << playerSecretNumber << endl;
}
