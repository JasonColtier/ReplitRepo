
#include <iostream>
#include <limits>
#include <functional>

template<typename T>
struct Operation {
    T left;
    T right;
    char operand;
};

bool IsValidOperand(const char op) {
    return op == '+' || op == '-' || op == '*' || op == '/' || op == '%';
}

char PromptForOperand() {
    while (true) {
        std::cout << "enter operand : ";
        char operand;
        std::cin >> operand;

        if (!std::cin || !IsValidOperand(operand)) // if the previous extraction failed
        {
            // let's handle the failure
            std::cin.clear(); // put us back in 'normal' operation mode
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            return operand;
        }
    }
}

template<typename T>
T GetNumber() {
    while (true) {
        T number;

        std::cout << "Enter number : ";
        std::cin >> number;

        if (!std::cin) // if the previous extraction failed
        {
            // let's handle the failure
            std::cin.clear(); // put us back in 'normal' operation mode
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            return number;
        }
    }
}

template<typename T>
Operation<T> PromptForOperation() {

    Operation<T> operation{};

    operation.left = GetNumber<T>();

    operation.operand = PromptForOperand();

    operation.right = GetNumber<T>();

    return operation;
}

template<typename T>
T Add(const T left,const T right){
    return left + right;
}

template<typename T>
T Subtract(const T left,const T right){
    return left - right;
}

template<typename T>
T Multiply(const T left,const T right){
    return left * right;
}

template<typename T>
T Divide(const T left,const T right){
    return left / right;
}

int Modulo(const int left,const int right) {
    return left % right;
}

template<typename T>
using ArythmeticFunction = std::function<T(T,T)>;

template<typename T>
ArythmeticFunction<T> GetArithmeticFunction(const char operand){
    switch (operand) {
        case '+': return &Add<T>;
        case '-': return &Subtract<T>;
        case '*': return &Multiply<T>;
        case '/': return &Divide<T>;
        case '%': return &Modulo;
        default:return nullptr;
    }
}

using TypeForOperation = float;

int main() {

    //int (*funcPtr)() = function pointer to int func with no params
    //int (* const funcPtr)() = const function
    //int (const * funcPtr)() = function returning const int

    Operation<TypeForOperation> operation = PromptForOperation<TypeForOperation>();
    ArythmeticFunction<TypeForOperation> calculate = GetArithmeticFunction<TypeForOperation>(operation.operand);

    TypeForOperation result = calculate(operation.left,operation.right);
    std::cout<<"performing operation "<<operation.left<<" "<<operation.operand<<" "<<operation.right<<" \n";
    std::cout<<"result : "<<result;

    return 0;
}