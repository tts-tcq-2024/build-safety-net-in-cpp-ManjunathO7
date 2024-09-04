#include "Soundex.h"
#include <iostream>
#include <string>
using namespace std;

bool isAlpha(char c)
{
    return c >= 'A' && c <= 'Z';
}

char getSoundexCode(char c)
{
    static const char soundexTable[26] = {
        '0', '1', '2', '3', '0', '1', '2', '0', '0', '2', // A-J
        '2', '4', '5', '5', '0', '1', '2', '6', '2', '3', // K-T
        '0', '1', '0', '2', '0', '2'                      // U-Z
        };

    c = toupper(c);
    if (isAlpha(c)) {
        return soundexTable[c - 'A'];
    }
    return '0';  // For non-alphabetic characters
}

bool isNotVowel(char c)
{
    static const char vowels[5] = {'A', 'E', 'I', 'O', 'U'};
    c = toupper(c);
    for (char vowel : vowels)
    {
        if (c == vowel)
        {
            return false;
        }
    }
    return true;
}


bool isHOrW(char c)
{
    return c == 'H' || c == 'W';
}

bool shouldSkip(char code, char prevCode, char prevChar) 
{
    bool c1 = (code == prevCode && isNotVowel(prevChar));
    bool c2 = isHOrW(prevChar);

    return c1 || c2;
}


string constructSoundex(const string& name)
{
    string soundex(1, toupper(name[0]));
    char prevCode = getSoundexCode(name[0]);

    for (int i = 1; i < name.length() && soundex.length() < 4; ++i)
    {
        char code = getSoundexCode(name[i]);
        if (isAlpha(name[i]) && code != prevCode) {
            soundex += code;
            prevCode = code;
        }
    }
    return soundex + string(4 - soundex.length(), '0');  // Pad with zeros to 4 characters
}


string generateSoundex(const string& name)
{
    if (name.empty()) 
    {
        return "";
    }
    return constructSoundex(name);
}
