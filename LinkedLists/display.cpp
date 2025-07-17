#include<iostream>
using namespace std;

struct Node{
    int val;
    struct Node *next;
};

class LinkedList{
private:
    struct Node *p;
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
   void display(){
    if (p == nullptr) cout << "Linked List is empty ";
    struct Node * temp = p;
    while (temp != 0){
        cout << temp-> val << " " ;
        temp = temp-> next;
    }
   }
};
int main(){
    LinkedList list;
    list.create();
    cout << "Linked List: ";
    list.display();
    cout << endl;

}