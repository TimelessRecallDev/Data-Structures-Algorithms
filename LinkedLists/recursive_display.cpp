#include<iostream>
using namespace std;

struct Node{
    int val;
    Node *next;
};

class LinkedList{
private:
    Node *p;
public:
    LinkedList(){
        p = nullptr;
    }
    void create() {
        int n, value;
        cout << "Enter the number of elements: ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            cout << "Enter the value: ";
            cin >> value;
            Node* temp = new Node;
            temp->val = value;
            temp->next = nullptr;
            if (p == nullptr) {
                p = temp;
            } else {
                Node* curr = p;
                while (curr->next != nullptr) {
                    curr = curr->next;
                }
                curr->next = temp;
            }
        }
    }
    void Recursive_display(Node *node){
        if (node == nullptr) {
            return;
        }
        cout << node->val << " ";
        Recursive_display(node->next);
    }
    void Reverse_display(Node *node){
        if (node == nullptr){
            return;
        }
        Reverse_display(node-> next);
        cout << node-> val << " ";
    }
    Node* getHead() {
        return p;
    }
};

int main(){
    LinkedList list;
    list.create();
    cout << "Linked List: ";
    list.Recursive_display(list.getHead());
    list.Reverse_display(list.getHead());
    
}