#include <iostream>
#include <stack>
#include <unordered_map>

bool isMatching(char open, char close)
{
    return (open == '(' && close == ')') || (open == '{' && close == '}') || (open == '[' && close == ']');
}
bool checkBalancedBrackets(const std::string& str, bool (*isBalancedBracket)(char, char))
{
    std::stack<char> openStack;
    for (char ch : str )
    {
        if (ch == '(' || ch == '{' || ch == '[')
        {
            openStack.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (openStack.empty() || !isBalancedBracket(openStack.top(), ch)) return false;
            openStack.pop();
        }
    }
    return openStack.empty();
}
int main()
{
    std::string input = "{[()]}";
    std::cout << "Balanced: " << std::boolalpha << checkBalancedBrackets(input, isMatching) << std::endl;
    return 0;
}