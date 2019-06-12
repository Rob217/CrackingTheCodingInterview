#include<iostream>
#include<string>
#include<vector>

// Test whether all characters in string are unique

bool isUnique(const std::string &s)
{
    // true: all chacaters in string s are unique
    // false: at least one duplicate character exists

    long int charLength = 4294967296; // UTF-8 (1-4 8-bit bytes)
    // int charLength = 256; // ASCII
    
    if (s.length() > charLength)
        return false;

    std::vector<bool> charsSeen;
    charsSeen.resize(charLength);
    
    for (int c = 0; c < static_cast<int>(s.length()); c++)
    {
        if (charsSeen[s[c]]) // already found character
            return false;
        charsSeen[s[c]] = true;
    }

    return true;
}

int main() 
{
    std::string testString("abcdefghij");
    std::cout << testString << "\n";

    bool unique = isUnique(testString);
    if (unique)
        std::cout << "All characters in string are unique\n";
    else
        std::cout << "Characters in string are not unique\n";

    return 0;
}
