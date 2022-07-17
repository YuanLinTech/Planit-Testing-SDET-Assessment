#include <iostream>
#include <string>
using namespace std;

char GetMostFrequentCharacter(string word)
{
    unsigned int j,k,m,n = 0;
    char ch = '\0';
    // The character which has the maximum number of occurrence in the input string and appears first in the string.
    char MostFrequentCharacter = '\0';
    // A character array storing all characters in the input string "word" converted to lowercase.
    char LowerWordChar[255];
    // A 64-bit integer array storing the number of occurrence of each character in the input string.
    __int64 Frequency[255];
    // The maximum number of occurrence of a character in the input string.
    __int64 MaxFrequency = 0;
    // The index of the character which has the maximum number of occurrence in the input string and appears first in the string.
    unsigned int MaxFrequencyIndex = 0; 

    // Prefill the integer array Frequency[255] with 255 "0"s.
    for (j = 0; j < 255; j++) 
    {
        Frequency[j] = 0;
    }

    // Convert all letters in the string "word" to lowercase and store it in the character array "LowerWord".
    for (k = 0; word.c_str()[k]; k++)
    {
        LowerWordChar[k] = tolower(word.c_str()[k]);
    }

    /* The word.c_str()[k] condition of the for loop stops the loop before it copies the null terminator ('\0').
    Add this one line after the for loop to copy the null terminator to the output character array.*/
    LowerWordChar[k] = word.c_str()[k]; // Copy the null terminator.

    // Convert LowerWordStr into a string
    string LowerWordStr(LowerWordChar);

    // Check the number of occurrence of each letter in the string LowerWordStr and store the number of occurrence in the array Frequency[m]
    for (m = 0; LowerWordStr.c_str()[m]; m++)
    {
        ch = LowerWordStr.c_str()[m];
        Frequency[m] = count(LowerWordStr.begin(), LowerWordStr.end(), ch);
    }

    // Find the maximum number of occurrence of a character in the input string.
    MaxFrequency = Frequency[0];
    for (n = 1; n < 255; n++)
    {
        if (Frequency[n] > MaxFrequency)
        {
            MaxFrequency = Frequency[n];
            MaxFrequencyIndex = n;
        }
    }

    // Determine the character which has the maximum number of occurrence in the input string and appears first in the string
    MostFrequentCharacter = LowerWordChar[MaxFrequencyIndex];

    // Return the character which has the maximum number of occurrence in the input string and appears first in the string
    return MostFrequentCharacter;
}

int main() 
{
    string word;
    getline(cin, word);
    char result = GetMostFrequentCharacter(word);
    cout << result << endl;
    return 0;
}
