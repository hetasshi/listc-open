#include <iostream>
using namespace std;

struct Node {
    string val;
    Node* next;

    Node(string _val) : val(_val), next(nullptr) {}
};

struct Stack {
    Node* top;

    Stack() : top(nullptr) {}

    bool is_empty() {
        return top == nullptr;
    }

    void push(string _val) {
        Node* p = new Node(_val);
        p->next = top;
        top = p;
    }

    void pop() {
        if (is_empty()) return;
        Node* p = top;
        top = top->next;
        delete p;
    }

    string peek() {
        return is_empty() ? "" : top->val;
    }

    void print() {
        if (is_empty()) return;
        Node* p = top;
        while (p) {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    cout << boolalpha << s.is_empty() << endl;

    s.push("3");
    s.push("123");
    s.push("8");
    s.push("12");
    s.push("77");
    s.push("5");

    s.print();
    cout << s.is_empty() << endl;

    s.pop();
    s.print();

    s.push("1234");
    s.print();

    s.pop();
    s.print();

    s.pop();
    s.print();

    cout << s.peek() << endl;

    return 0;
}
