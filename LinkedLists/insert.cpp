#include <iostream>
using namespace std;

struct Node{
    int val;
    struct Node* next;
};
class LinkedList{
private:
    Node *head;
    int size;
public: 
    LinkedList(){
        head = nullptr;
        size = 0;
    }
    void create(){
        cout << "Enter the size of linked list :";
        cin >> size;
        int data;
        cout << "Enter the value: ";
        cin >> data;
        head = new Node;
        head-> val = data;
        head-> next = nullptr;
        Node* prev = head;

        for (int i = 1 ; i < size ; i++){
             Node* current = new Node;
             cout << "Enter the value: \n";
             cin >> data;

             current-> val = data;
             current-> next = nullptr;

             prev-> next = current;
             prev = current;
        }
    }
    void Insert(int index, int data){   //insert function
        if (index < 0 || index > size) return;
        if (index == 0){           //add at begining
            Node *temp = new Node;
            temp-> val = data;
            temp-> next = head;
            head = temp;
        }
        else{
            Node* temp = new Node;
            temp-> val = data;          
            Node* tracker = head; 
            for (int i = 0 ; i < index - 1 ; i++){
                tracker = tracker -> next;
            }
            temp-> next = tracker-> next;
            tracker-> next = temp;
        }
        size++; 
    }
    void display() const {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main(){
    LinkedList list;
    list.create();
    cout << "Initial Linked List: ";
    list.display();

    int index, data;
    cout << "Enter index to insert: ";
    cin >> index;
    cout << "Enter value to insert: ";
    cin >> data;

    list.Insert(index, data);
    cout << "Linked List after insertion: ";
    list.display();

    return 0;
}