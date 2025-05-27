#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

int main()
{
    std::string sentence = "Hello, World!";
    std::istringstream iss(sentence);
    std::vector<std::string> words;
    std::string word;

    while(iss >> word)
        words.push_back(word);

    auto print = [](const std::string& word) {
        std::cout << word << " ";
    };

    std::ranges::reverse(words);
    std::ranges::for_each(words, print);

    return 0;
}
