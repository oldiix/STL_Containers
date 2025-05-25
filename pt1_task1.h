#ifndef PT1_TASK1_H
#define PT1_TASK1_H

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <array>
#include <utility>

class Person {

private:
    std::string name;
    int age;

public:
    Person(std::string name, int age) : name(std::move(name)), age(age) {}
    ~Person() = default;

    [[nodiscard]] std::string getName() const { return name; }
    [[nodiscard]] int getAge() const { return age; }

    friend std::ostream& operator<<(std::ostream& os, const Person& person) {
        os << person.name << "(" << person.age << ")";
        return os;
    }
    bool operator==(const Person& other) const {
        return name == other.name && age == other.age;
    }
};


template <typename T, size_t A1, size_t A2>
std::array<T, A1 + A2> mergeSortedArrays(const  std::array<T, A1>& arr1, const std::array<T, A2>& arr2)
{
std::array<T, A1 + A2> result{};
    size_t i = 0, j = 0, k=0;
    while (i < A1 && j < A2)
    {
        if (arr1[i] < arr2[j])
        {
            result[k++] = arr1[i++];
        } else
        {
            result[k++] = arr2[j++];
        }
    }
    while (i < A1) result[k++] = arr1[i++];
    while (j < A2) result[k++] = arr2[j++];

    return result;
}

template <typename T>
void splitEvenOdd(const std::vector<T>& vec, std::vector<T>& even, std::vector<T>& odd)
{
    for (auto it = vec.begin(); it != vec.end(); ++it)
    {
        if (*it % 2 == 0)
            even.emplace_back(*it);
        else
            odd.emplace_back(*it);
    }
}

template <typename T>
bool isPalindrome(const std::deque<T>& deque)
{
    auto left = deque.begin();
    auto right = deque.empty() ? deque.begin() : std::prev(deque.end());

    while (left < right)
    {
        if (*left != *right)
            return false;
        ++left;
        --right;
    }

    return true;
}

#endif //PT1_TASK1_H
