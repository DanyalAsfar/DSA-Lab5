#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
    node* prev;
};

class DoublyLinkedList{
    public:
        node* head = nullptr;
        node* tail = nullptr;

        void AddNode(int value){
            node* newNode = new node{value,nullptr, tail};

            if (tail == nullptr)
                head = newNode;
            else
                tail -> next = newNode;
            
            tail = newNode;
        }

        void PrintForward(){
            node* currentNode = head;

            if (currentNode == nullptr)
                cout << "Linked List is Empty!!!\n\n";
            else{
                while (currentNode != nullptr){
                    cout << currentNode -> data << endl;
                    currentNode = currentNode -> next;
                }
            }

        }

        void PrintReverse(){
            node* currentNode = tail;

            if (currentNode == nullptr)
                cout << "Linked List is Empty!!!\n\n";
            else{
                while (currentNode != nullptr){
                    cout << currentNode -> data << endl;
                    currentNode = currentNode -> prev;
                }
            }

        }

        void ClearList(){
            node* currentNode = head;
            node* nextNode;

            while (currentNode != nullptr){
                nextNode = currentNode -> next;
                delete currentNode;
                currentNode = nextNode;
            }

            head = nullptr;
            tail = nullptr;
        }
};

int main(){
    int numberOfNodes, data;
    DoublyLinkedList list;
    cout << "Empty List:\nForward:\n";
    list.PrintForward();
    cout << "Reverse:\n";
    list.PrintReverse();

    cout << "Enter Number (Non-Negative) of Nodes to Add:\n";
    cin >> numberOfNodes;

    while (numberOfNodes < 0){
        cout << "Count Should be Non-Negative!!!\nTry Again:\n";
        cin >> numberOfNodes;
    }

    for (int count = 0; count < numberOfNodes; count++){
        cout << "\nEnter an Integer:\n";
        cin >> data;

        list.AddNode(data);
    }

    cout << "Filled List:\nForward:\n";
    list.PrintForward();
    cout << "Reverse:\n";
    list.PrintReverse();

    list.ClearList();
    list.PrintForward();
    return 0;
}