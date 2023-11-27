#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class St {
private:
    Node* t;

public:
    St() : t(nullptr) {}

    void push(int val) {
        Node* n = new Node(val);
        if (!t) {
            t = n;
        } else {
            n->next = t;
            t = n;
        }
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return -1;
        } else {
            Node* temp = t;
            int val = temp->data;
            t = t->next;
            delete temp;
            return val;
        }
    }

    bool isEmpty() {
        return t == nullptr;
    }
};

int eval(const string& postfix) {
    St stack;
    for (char c : postfix) {
        if (isdigit(c)) {
            stack.push(c - '0');
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            if (stack.isEmpty()) {
                cout << "Invalid postfix expression." << endl;
                return 0;
            }
            int op2 = stack.pop();
            if (stack.isEmpty()) {
                cout << "Invalid postfix expression." << endl;
                return 0;
            }
            int op1 = stack.pop();

            switch (c) {
                case '+':
                    stack.push(op1 + op2);
                    break;
                case '-':
                    stack.push(op1 - op2);
                    break;
                case '*':
                    stack.push(op1 * op2);
                    break;
                case '/':
                    if (op2 == 0) {
                        cout << "Division by zero is not allowed." << endl;
                        return 0;
                    }
                    stack.push(op1 / op2);
                    break;
            }
        }
    }

    if (stack.isEmpty()) {
        cout << "Invalid postfix expression." << endl;
        return 0;
    }

    return stack.pop();
}

int main() {
    string postfix;
    cout << "Enter the postfix expression: ";
    getline(cin, postfix);

    int res = eval(postfix);

    if (res != 0) {
        cout << "Result of postfix expression " << postfix << " is: " << res << endl;
    }

    return 0;
}
