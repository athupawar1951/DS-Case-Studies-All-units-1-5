#include <iostream>
using namespace std;

// Unit 3 Case Study: Stack and Queue using Linked Lists

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class Stack {
private:
    Node* topNode;

public:
    Stack() : topNode(nullptr) {}

    ~Stack() {
        while (!isEmpty()) pop();
    }

    bool isEmpty() const {
        return topNode == nullptr;
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = topNode;
        topNode = newNode;
        cout << value << " pushed onto the stack.\\n";
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow: stack is empty.\\n";
            return;
        }
        Node* temp = topNode;
        cout << "Popped element: " << temp->data << '\\n';
        topNode = topNode->next;
        delete temp;
    }

    void peek() const {
        if (isEmpty()) cout << "Stack is empty.\\n";
        else cout << "Top element: " << topNode->data << '\\n';
    }

    void display() const {
        if (isEmpty()) {
            cout << "Stack is empty.\\n";
            return;
        }
        cout << "Stack (top to bottom): ";
        for (Node* current = topNode; current != nullptr; current = current->next)
            cout << current->data << ' ';
        cout << '\\n';
    }
};

class Queue {
private:
    Node* frontNode;
    Node* rearNode;

public:
    Queue() : frontNode(nullptr), rearNode(nullptr) {}

    ~Queue() {
        while (!isEmpty()) dequeue();
    }

    bool isEmpty() const {
        return frontNode == nullptr;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            frontNode = rearNode = newNode;
        } else {
            rearNode->next = newNode;
            rearNode = newNode;
        }
        cout << value << " inserted into the queue.\\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow: queue is empty.\\n";
            return;
        }
        Node* temp = frontNode;
        cout << "Removed element: " << temp->data << '\\n';
        frontNode = frontNode->next;
        if (frontNode == nullptr) rearNode = nullptr;
        delete temp;
    }

    void getFront() const {
        if (isEmpty()) cout << "Queue is empty.\\n";
        else cout << "Front element: " << frontNode->data << '\\n';
    }

    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty.\\n";
            return;
        }
        cout << "Queue (front to rear): ";
        for (Node* current = frontNode; current != nullptr; current = current->next)
            cout << current->data << ' ';
        cout << '\\n';
    }
};

int main() {
    Stack stack;
    Queue queue;
    int mainChoice;

    do {
        cout << "\\n===== UNIT 3: STACK & QUEUE USING LINKED LISTS =====\\n";
        cout << "1. Stack operations\\n2. Queue operations\\n0. Exit\\n";
        cout << "Enter choice: ";
        if (!(cin >> mainChoice)) return 0;

        if (mainChoice == 1) {
            int choice, value;
            do {
                cout << "\\n--- Stack Menu ---\\n";
                cout << "1. Push\\n2. Pop\\n3. Peek\\n4. Display\\n0. Back\\n";
                cout << "Enter choice: ";
                cin >> choice;
                switch (choice) {
                    case 1:
                        cout << "Enter value: ";
                        cin >> value;
                        stack.push(value);
                        break;
                    case 2: stack.pop(); break;
                    case 3: stack.peek(); break;
                    case 4: stack.display(); break;
                    case 0: break;
                    default: cout << "Invalid choice. Try again.\\n";
                }
            } while (choice != 0);
        } else if (mainChoice == 2) {
            int choice, value;
            do {
                cout << "\\n--- Queue Menu ---\\n";
                cout << "1. Enqueue\\n2. Dequeue\\n3. Front\\n4. Display\\n0. Back\\n";
                cout << "Enter choice: ";
                cin >> choice;
                switch (choice) {
                    case 1:
                        cout << "Enter value: ";
                        cin >> value;
                        queue.enqueue(value);
                        break;
                    case 2: queue.dequeue(); break;
                    case 3: queue.getFront(); break;
                    case 4: queue.display(); break;
                    case 0: break;
                    default: cout << "Invalid choice. Try again.\\n";
                }
            } while (choice != 0);
        } else if (mainChoice != 0) {
            cout << "Invalid choice. Try again.\\n";
        }
    } while (mainChoice != 0);

    cout << "Program ended.\\n";
    return 0;
}
