#include <iostream>
using namespace std;

struct Node{
    int val;
    struct Node *next;
};

class LinkedList{
private:
    Node *head;
public:
    LinkedList(){
        head = nullptr;
    }
    void create(){
        int n;

        cout << "Enter the size of linked list: ";        
        cin >> n;

        if (n <= 0) {
            head = nullptr;
            return;
        }

        int value;
        cout << "Enter the value: ";
        cin >> value;

        head = new Node;
        head-> val = value;
        head-> next = nullptr;

        Node *prev = head;

        for (int i = 1 ; i < n; i++){

            cout <<  "Enter the value: ";
            cin >> value;

            Node *current = new Node;
            current-> val = value;
            current-> next = nullptr;
            prev-> next = current;
            prev = current;
        }
    }
    void display(){
        if (head == nullptr) {
            cout << "List is empty";
            return;
        }
        Node *temp = head;
        while (temp != nullptr){
            cout << temp-> val << " ";
            temp = temp-> next;
        }
    }

    Node* Linear_search(int key);
    friend Node* RLinear_search(Node* temp , int key);  //recursive linear search
    Node* ImprovedLS(int key)    //improved linear search (move to head)
} 

Node* LinkedList :: Linear_search(int key){
    if (head == nullptr){
        return head;
    }
    Node* temp = head;

    while (temp != nullptr){
        if (temp-> val == key) return temp;
        temp = temp-> next;
    }
    return nullptr;

} 
Node* RLinear_search(Node* temp, int key) {
    if (temp == nullptr) {
        return nullptr;
    }
    if (temp->val == key) {
        return temp;
    }
    return RLinear_search(temp->next, key);
}
Node* LinkedList :: ImprovedLS(int key) {
    if (head == nullptr) return nullptr;
    if (head->val == key) return head;

    Node* prev = head;
    Node* curr = head->next;
    while (curr != nullptr) {
        if (curr->val == key) {
            prev->next = curr->next;
            curr->next = head;
            head = curr;
            return curr;
        }
        prev = curr;
        curr = curr->next;
    }
    return nullptr;
}
int main() {
    LinkedList list;
    list.create();
    cout << "Linked List: ";
    list.display();
    cout << endl;

    int key;
    cout << "Enter value to search: ";
    cin >> key;

    Node* result = list.Linear_search(key);
    if (result)
        cout << "Found (iterative): " << result->val << endl;
    else
        cout << "Not found (iterative)" << endl;

    result = RLinear_search(list.head, key); 
    if (result)
        cout << "Found (recursive): " << result->val << endl;
    else
        cout << "Not found (recursive)" << endl;

    result = list.ImprovedLS(key);
    if (result)
        cout << "Found and moved to head (improved): " << result->val << endl;
    else
        cout << "Not found (improved)" << endl;

    cout << "Linked List after improved search: ";
    list.display();
    cout << endl;

    return 0;
}