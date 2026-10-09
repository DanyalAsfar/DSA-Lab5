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

        void InsertBefore(int position, int value){
            int currentPosition = 1;

            node* currentNode = head;

            while (currentNode != nullptr && currentPosition != position){
                    currentNode = currentNode -> next;
                    currentPosition++;
            }

            // empty list or end reached without reaching the position
            if (currentNode == nullptr ){
                cout << "No Node at Position: " << position << endl << endl;
                return;
            }

            node* newNode = new node;
            newNode -> data = value;
        
            newNode -> next = currentNode;
            newNode -> prev = currentNode -> prev;
            currentNode -> prev = newNode;

            if (currentPosition == 1)
                head = newNode;
            else
                newNode -> prev -> next = newNode;

        }

        void deleteNode(int value){
            node* currentNode = head;

            if (currentNode == nullptr)
                cout << "Linked List is Empty!!!\n\n";
            else{
                while (currentNode != nullptr && currentNode -> data != value){
                    currentNode = currentNode -> next;
                }
                
                if (currentNode == nullptr){
                    cout << "Node Does Not Exist!!!\n\n";
                    return;
                }

                //coming here means data exists
                // updating forward link
                if (currentNode -> prev != nullptr){ // currentNode is not head
                    currentNode -> prev -> next = currentNode -> next;
                }
                else // current node is head
                    head = currentNode -> next;

                // updating reverse link
                if (currentNode -> next != nullptr){ // currentNode is not tail
                    currentNode -> next -> prev = currentNode -> prev;
                }
                else
                    tail = currentNode -> prev;
                delete currentNode;
            
            }
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

    cout << "Deleting Node 10:\n";
    list.deleteNode(10);

    list.AddNode(10);
    list.AddNode(20);
    list.AddNode(20);
    list.AddNode(30);

    cout << "\nFilled List\nForward:\n";
    list.PrintForward();
    cout << "\nReverse:\n";
    list.PrintReverse();

    cout << "\nDeleting Node 45:\n";
    list.deleteNode(45);
    
    cout << "\nInserting Node 5 before Position 1 (head):\n";
    list.InsertBefore(1, 5);

    cout << "Forward:\n";
    list.PrintForward();
    cout << "\nReverse:\n";
    list.PrintReverse();

    cout << "\nDeleting Node 5:\n";
    list.deleteNode(5);

    cout << "Forward:\n";
    list.PrintForward();
    cout << "\nReverse:\n";
    list.PrintReverse();

    cout << "\nDeleting Node 20:\n";
    list.deleteNode(20);

    cout << "Forward:\n";
    list.PrintForward();
    cout << "\nReverse:\n";
    list.PrintReverse();

    cout << "\nInserting node 15 before Position 2, and deleting node 20: \n";
    list.InsertBefore(2, 15);
    list.deleteNode(20);

    cout << "Forward:\n";
    list.PrintForward();
    cout << "\nReverse:\n";
    list.PrintReverse();

    cout << "\nDeleting Node 10:\n";
    list.deleteNode(10);

    cout << "Forward:\n";
    list.PrintForward();
    cout << "\nReverse:\n";
    list.PrintReverse();

    cout << "\nDeleting Node 30:\n";
    list.deleteNode(30);

    cout << "Forward:\n";
    list.PrintForward();
    cout << "Reverse:\n";
    list.PrintReverse();

    cout << "\nDeleting Node 15:\n";
    list.deleteNode(15);

    cout << "Forward:\n";
    list.PrintForward();
    cout << "\nReverse:\n";
    list.PrintReverse();
    
    return 0;
}