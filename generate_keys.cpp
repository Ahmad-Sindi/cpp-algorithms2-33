/* Algorithm Challenge & Problem Solving
 * 33 - Fill Array With Generated Keys
 *
 * This program generates a number of keys based on user input, stores them inside an array of strings, and prints all generated keys.
 *
 * Each key is composed of multiple segments:
 *   - 4 Capital Letters
 *   - 4 Digits
 *   - 4 Capital Letters
 *   - A separator (#)
 *   - 4 Digits
 *
 * Concepts Reinforced:
 *   - Random character generation using ASCII ranges
 *   - Enum-based selection for character types
 *   - String construction and concatenation
 *   - Working with arrays of strings
 *   - Clean modular function design
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Enum representing types of characters that can be generated
enum enCharType
{
    SmallLetter = 1,
    CapitalLetter = 2,
    SpecialCharacter = 3,
    Digit = 4
};

// Generates a random number in a given range [From, To]
int Randnumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

// Returns a random character based on the selected character type
char GetRandomCharacter(enCharType Type)
{
    switch (Type)
    {
    case enCharType::SmallLetter:
        return char(Randnumber(97, 122)); // a-z
    case enCharType::CapitalLetter:
        return char(Randnumber(65, 90)); // A-Z
    case enCharType::SpecialCharacter:
        return char(Randnumber(33, 47)); // Special chars
    case enCharType::Digit:
        return char(Randnumber(48, 57)); // 0-9
    }
    return '?'; // fallback character
}

// Prints all strings stored inside the array
void PrintStringArray(string arr[100], int ArrayLength)
{
    cout << "\nArray elements: " << ArrayLength << "\n\n";
    for (int i = 0; i < ArrayLength; i++)
    {
        cout << "Array[" << i + 1 << "] : " << arr[i] << "\n";
    }
    cout << "\n";
}

// Generates a random word of a given type and length
string GenerateWord(enCharType CharType, short Length)
{
    string Word = "";

    for (int i = 1; i <= Length; i++)
        Word += GetRandomCharacter(CharType);

    return Word;
}

// Generates a full formatted key made of multiple character segments
string GenerateKey()
{
    string Key = "";

    Key += GenerateWord(enCharType::CapitalLetter, 4) + "-"; // 4 capital letters
    Key += GenerateWord(enCharType::Digit, 4) + "-";         // 4 digits
    Key += GenerateWord(enCharType::CapitalLetter, 4) + "-"; // 4 capital letters
    Key += "#";                                              // special marker
    Key += GenerateWord(enCharType::Digit, 4);               // final digits

    return Key;
}

// Fills the array with automatically generated keys
void FillArrayWithKeys(string arr[100], int ArrayLength)
{
    for (int i = 0; i < ArrayLength; i++)
        arr[i] = GenerateKey();
}

// Reads a positive number from user
int ReadPositiveNumber(string Message)
{
    int Number = 0;

    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);

    return Number;
}

int main()
{
    // Seed randomizer (must be called once)
    srand((unsigned)time(NULL));

    string arr[100];
    int ArrayLength = 0;

    ArrayLength = ReadPositiveNumber("How many keys do you want to generate?\n");

    FillArrayWithKeys(arr, ArrayLength);

    PrintStringArray(arr, ArrayLength);

    return 0;
}
