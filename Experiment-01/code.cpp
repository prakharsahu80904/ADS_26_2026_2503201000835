#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

#define SIZE 5

// ---------------- STACK IMPLEMENTATION ----------------
class Stack {
    int arr[SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int x) {
        if (top == SIZE - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
        cout << x << " pushed\n";
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return;
        }
        cout << arr[top--] << " popped\n";
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return;
        }

        cout << "Final Stack: ";
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
};

// ---------------- INFIX TO POSTFIX ----------------

int precedence(char op) {
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

bool isRightAssociative(char op) {
    return op == '^';
}

string infixToPostfix(string infix) {
    stack<char> st;
    string postfix = "";

    for (char ch : infix) {

        if (isalnum(ch)) {
            postfix += ch;
        }

        else if (ch == '(') {
            st.push(ch);
        }

        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }

        else {
            while (!st.empty() &&
                   st.top() != '(' &&
                   (precedence(st.top()) > precedence(ch) ||
                   (precedence(st.top()) == precedence(ch) &&
                    !isRightAssociative(ch)))) {

                postfix += st.top();
                st.pop();
            }

            st.push(ch);
        }
    }

    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

// ---------------- POSTFIX EVALUATION ----------------

int evaluatePostfix(string postfix) {
    stack<int> st;

    for (char ch : postfix) {

        if (isdigit(ch)) {
            st.push(ch - '0');
        }

        else {
            int b = st.top();
            st.pop();

            int a = st.top();
            st.pop();

            switch (ch) {
                case '+': st.push(a + b); break;
                case '-': st.push(a - b); break;
                case '*': st.push(a * b); break;
                case '/': st.push(a / b); break;
                case '^': {
                    int result = 1;
                    for (int i = 0; i < b; i++)
                        result *= a;
                    st.push(result);
                    break;
                }
            }
        }
    }

    return st.top();
}

int main() {

    // Stack demonstration
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.pop();

    s.display();

    // Infix to postfix
    string infix = "2+3*4";

    string postfix = infixToPostfix(infix);

    cout << "\nInfix: " << infix << endl;
    cout << "Postfix: " << postfix << endl;

    cout << "Result: "
         << evaluatePostfix(postfix) << endl;

    return 0;
}