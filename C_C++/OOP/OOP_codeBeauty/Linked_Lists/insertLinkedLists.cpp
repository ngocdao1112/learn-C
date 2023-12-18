#include <iostream>
using namespace std;
class Node {
public: //tốn memory vì lưu trữ 2 giá trị trong cùng 1 ô nhớ
    int Value;
    Node* Next;
};
//linked lists to function
void printList(Node*n) {
    while(n != NULL) {
        cout << n->Value << endl;
        n = n->Next;
    }
}
void insertAtTheFront(Node** head, int newValue) {
    //1. prepare a newNode
    Node* newNode = new Node();
    newNode->Value = newValue;
    //2. put it in front of current head
    newNode->Next = *head;
    //3. move head of the list to point to the newNode
    *head = newNode;
}
void insertAtTheEnd(Node** head, int newValue) {
    //1. prepare a newNode
    Node* newNode = new Node();
    newNode->Value = newValue;
    newNode->Next = NULL;
    //2. if linked list is empty, newNode will be a head node
    if(*head == NULL) {
        *head = newNode;
        return;
    }
    //3. find the last node
    //Vòng lặp sẽ tiếp tục cho đến khi last->Next là NULL, tức là last là node cuối cùng trong danh sách.
    Node* last = *head;
    while(last->Next != NULL) { 
        last = last->Next;
    }
    //4. insert newNode after last node(at the end)
    last->Next = newNode;
}
//insert a node after a given node
// a -> b (odd) >>> vậy làm sao để mất địa chỉ từ a -> b mãi mãi
    // vì a đang connect to b, nếu a connect to newNode thì sẽ bị mất địa chỉ mãi mãi giữa a và b
    // vậy solution là lấy newNode connect to b trước để giữ address của b
// a -> newNode -> b (new)
void insertAfter(Node* previous, int newValue) {
    //1. check if previous node is NULL
    if(previous == NULL) {
        cout << "Previous can not be NULL";
        return;
    }
    //2. prepare a newNode
    Node* newNode = new Node();
    newNode->Value = newValue;
    //3. insert newNode after previous
    newNode->Next = previous->Next;
    previous->Next = newNode;
}

int main() {
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    head -> Value = 1;
    head -> Next = second;
    second -> Value = 2;
    second -> Next = third;
    third -> Value = 3;
    third -> Next = NULL;

    //insert a node at the end of a linked list
    insertAtTheEnd(&head, 4);
    insertAtTheEnd(&head, 5);

    //insert a node at the front of a linked list
    // insertAtTheFront(&head, -1);
    // insertAtTheFront(&head, -2);
    printList(head);
    
    return 0;
}