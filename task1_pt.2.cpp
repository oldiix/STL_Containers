#include <iostream>
#include <stack>
#include <sstream>
#include <unordered_map>
#include <functional>

int main()
{
    std::string expresssion = "10 2 8 * + 3 -";
    std::istringstream iss(expresssion);
    std::stack<int> stack;
    std::string token;

    std::unordered_map<std::string, std::function<int(int, int)>> operations = {
        {"+", [](int a, int b) { return a + b; }},
        {"-", [](int a, int b) { return a - b; }},
        {"*", [](int a, int b) { return a * b; }},
        {"/", [](int a, int b) { return a / b; }},
    };

    while (iss >> token)
    {
        if(isdigit(token[0]) || (token.size() > 1 && token[0] == '-'))
        {
            stack.push(std::stoi(token));
        } else
        {
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();
            stack.push(operations[token](a, b));
        }
    }

    std::cout << "Final result: " << stack.top() << std::endl;
    return 0;
}