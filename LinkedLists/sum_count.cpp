#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *next;
};

class LinkedList {
private:
    Node *head;
public:
    LinkedList() : head(nullptr) {}

    void create() {
        int n, value;
        cout << "Enter the number of elements: ";
        cin >> n;

        for (int i = 0; i < n; ++i) {
            cout << "Enter the value: ";
            cin >> value;
            Node* temp = new Node{value, nullptr};

            if (head == nullptr) {
                head = temp;
            } else {
                Node* curr = head;
                while (curr->next != nullptr) {
                    curr = curr->next;
                }
                curr->next = temp;
            }
        }
    }

    void display() const {
        if (head == nullptr) {
            cout << "Linked List is empty";
            return;
        }
        Node *temp = head;
        while (temp != nullptr) {
            cout << temp->val << " ";
            temp = temp->next;
        }
    }
    int count() const {
        int c = 0;
        Node *temp = head;
        while (temp != nullptr) {
            c++;
            temp = temp->next;
        }
        return c;
    }

    int get_sum() const {
        int sum = 0;
        Node *temp = head;
        while (temp != nullptr) {
            sum += temp->val;
            temp = temp->next;
        }
        return sum;
    }
};

int main() {
    LinkedList list;
    list.create();
    cout << "Linked List: ";
    list.display();
    cout << endl;
    cout << "Count: " << list.count() << endl;
    cout << "Sum: " << list.get_sum() << endl;
}