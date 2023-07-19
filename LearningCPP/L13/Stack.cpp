#include <array>
#include <iostream>
#include <cassert>

constexpr int maxStackValue{10};

class Stack {
public:

    void reset() {
        m_stackSize = 0;
    };

    bool push(const int pushedValue) {
        if (m_stackSize + 1 < maxStackValue) {
            m_stack[m_stackSize] = pushedValue;
            m_stackSize++;
            return true;
        } else {
            return false;
        }

    };

    int pop() {
        assert(m_stackSize != 0 && "m_stack is empty !");

        int returnedValue{m_stack[m_stackSize]};
        --m_stackSize;
        return returnedValue;
    };

    void print() {
        std::cout << "( ";
        for (int i{0}; i < m_stackSize; ++i) {
            std::cout << m_stack[i] << " ";
        }
        std::cout << ")\n";
    }

private:
    std::size_t m_stackSize{0};
    std::array<int,maxStackValue> m_stack {};
};


int main() {
    Stack stack;
    stack.print();

    stack.push(5);
    stack.push(3);
    stack.push(8);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();

    stack.print();

    return 0;
}