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
    int get_max (){
        int max = INT_MIN;

        if (p == nullptr) {
            cout << "List is empty";
            return 0;
        }

        struct Node *temp = p;
        while (temp != nullptr){
            if (temp->val > max) max = temp->val;
            temp = temp->next;
        }
        return max;
    }
    int get_min(){
        int min = INT_MAX;

        if (p == nullptr) {
            cout << "List is empty";
            return 0;
        }
        struct Node *temp = p;
        while (temp != nullptr){
            if (temp->val < min) min = temp->val;
            temp = temp->next;
        }
        return min;
    }
};

int main(){
    LinkedList list;
    list.create();

    int max = list.get_max();
    int min = list.get_min();

    cout << "Maximum value in the list: " << max << endl;
    cout << "Minimum value in the list: " << min << endl;

}