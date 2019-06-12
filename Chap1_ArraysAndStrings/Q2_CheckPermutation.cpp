#include<iostream>
#include<string>
#include<vector>
#include<algorithm> // sort

// Check whether two strings are a permutation of each other

bool sortStrings(std::string a, std::string b)
{
    // sort strings and compare
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    std::cout << a << ", " << b << "\n";
    for (int i = 0; i < static_cast<int>(a.length()); i++)
        if (a[i] != b[i])
            return false;
    return true;
}

bool countChars(const std::string &a, const std::string &b)
{
    // count characters and compare

    int nChars = 256; // assuming ASCII
    std::vector<int> countChars_a;
    std::vector<int> countChars_b;
    countChars_a.resize(nChars); 
    countChars_b.resize(nChars); 
    for (int i = 0; i < static_cast<int>(a.length()); i++)
    {
        countChars_a[a[i]]++;
        countChars_b[b[i]]++; 
    }
    for (int j = 0; j < nChars; j++)
        if (countChars_a[j] != countChars_b[j])
            return false;
    return true;
}


int main() 
{
    std::string a("abcdefg");
    std::string b("gfedabc");

    bool isPermutation;

    if (a.length() != b.length())
        isPermutation = false;
    else
    {
        // isPermutation = sortStrings(a, b);
        isPermutation = countChars(a, b);
    }

    if (isPermutation)
        std::cout << "Strings are permutation of each other\n";
    else
        std::cout << "Strings are not permutation of each other\n";

    return 0;
}
