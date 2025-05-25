#include "pt1_task1.h"
#include <iostream>


int main()
{
    std::array<int, 5> arr1 = {1, 3, 5, 7, 9};
    std::array<int, 4> arr2 = {2, 4, 6, 8};

    auto merged = mergeSortedArrays(arr1, arr2);
    std::cout << "Merged Arrays: ";
    for (const auto &i : merged) std :: cout << i << " ";
    std::cout << "\n";


    std::vector<int> numbers = {5, 7, 13, 77, 8, 4, 122};
    std::vector<int> even, odd;
    splitEvenOdd(numbers, even, odd);

    std::cout << "Even Numbers: ";
    for (const auto &i : even) std :: cout << i << " ";
    std::cout << "\n";
    std::cout << "Odd Numbers: ";
    for (const auto &i : odd) std :: cout << i << " ";
    std::cout << "\n";


    std::deque<char> word = {'a', 'b', 'b', 'a'};
    std::cout << "Is palindrome: " << (isPalindrome(word) ? "true" : "false") << "\n";

    std::deque<std::string> car_model = { "Civic", "Ford" };
    std::cout << "Is string deque palindrome: " << (isPalindrome(car_model) ? "true" : "false") << "\n";

    std::deque<Person> persons = {
        Person("Anna", 11),
        Person("Bob", 44),
        Person("Anna", 11),
    };
    std::cout << "Is person deque palindrome: " << (isPalindrome(persons) ? "true" : "false") << "\n";
    return 0;
}

