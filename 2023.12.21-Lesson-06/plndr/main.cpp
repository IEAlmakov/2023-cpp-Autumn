#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

std::string findMostFrequentWord(const std::string& text) {
    std::string mostFrequentWord;
    int maxCount = 0;
    char* textCopy = strdup(text.c_str());
    char* token = strtok(textCopy, " ,.-");

    while (token != NULL)
    {
        std::string word = token;
        int count = 0;
        char* searchPos = textCopy;
        while ((searchPos = strstr(searchPos, token)) != NULL)
        {
            count++;
            searchPos += strlen(token);
        }

        if (count > maxCount)
        {
            maxCount = count;
            mostFrequentWord = word;
        }

        token = strtok(NULL, " ,.-");
    }

    free(textCopy);
    return mostFrequentWord;
}

bool isPalindrome(const std::string& str)
{
    int i = 0, j = str.length() - 1;
    while (i < j) {
        if (str[i] != str[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main() {
    char input[1000];
    std::cout << "Enter the text: ";
    std::cin.getline(input, sizeof(input));
    std::string text(input);

    std::string mostFrequent = findMostFrequentWord(text);
    std::cout << "Most frequent word: " << mostFrequent << std::endl;

    std::string palindrome = "deified";
    bool isPal = isPalindrome(palindrome);

    if (isPal) {
        std::cout << palindrome << " is a palindrome" << std::endl;
    }
    else
    {
        std::cout << palindrome << " is not a palindrome" << std::endl;
    }

    return 0;
}
