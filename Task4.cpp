#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

class CircularLinkedList{
    public:
        node* head = nullptr;
        node* tail = nullptr;

        void AddNode(int value){
            node* newNode = new node;
            newNode -> data = value;

            // if list empty
            if (tail == nullptr){
                head = newNode;
            }
            else
                tail -> next = newNode;

            newNode -> next = head;
            tail = newNode;
        }

        void PrintList(){
            if (head == nullptr){
                cout << "\nCircular Linked List Empty!!!\n";
                return;
            }

            node* currentNode = head;

            /* normal nullptr based traversal wouldn't terminate since the "next" of last node
               does not point to nullptr, it instead points back to head pointer and so the 
               cycle continues forever */
            do{
                cout << currentNode -> data << endl;
                currentNode = currentNode -> next;
            } while(currentNode != head);

        }

        void CountNodes(){
            int count = 0;

            node* currentNode = head;

            if (head != nullptr){
                do{
                    count++;
                    currentNode = currentNode -> next;
                } while(currentNode != head);
            }

            cout << "\nTotal Nodes: " << count << endl;
        }

        void DeleteNode(int value){
            node* currentNode = tail;
            node* prevNode;
            node* nextNode = head;

            if (head == nullptr){
                cout << "Circular Linked List is Empty!!!\n";
                return;
            }

            do{
                prevNode = currentNode;
                currentNode = nextNode;
                nextNode = currentNode -> next;
            } while (nextNode != head && currentNode -> data != value);

            if (currentNode -> data == value){
                if (head == tail){
                    head = nullptr;
                    tail = nullptr;
                }
                else{
                    if (currentNode == head)
                        head = currentNode -> next;
                    if (currentNode == tail)
                        tail = prevNode;

                    prevNode -> next = currentNode-> next;
                }

                delete currentNode;
            }
            else
                cout << "Node Not Found!!!\n";
        }

        void ClearList(){
            node* currentNode = head;
            node* nextNode;

            if (tail != nullptr)
                tail -> next = nullptr;
            
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
    CircularLinkedList list;

    cout << "\nDeleting from Empty List:\n";
    list.DeleteNode(10);

    list.AddNode(10);
    list.AddNode(20);
    list.AddNode(20);
    list.AddNode(30);
    cout << "\nStarting List:\n";
    list.PrintList();

    cout << "\nDeleting Node 45:\n";
    list.DeleteNode(45);
    list.PrintList();

    cout << "\nDeleting Node 20:\n";
    list.DeleteNode(20);
    list.PrintList();

    cout << "\nDeleting Node 10:\n";
    list.DeleteNode(10);
    list.PrintList();

    cout << "\nDeleting Node 30:\n";
    list.DeleteNode(30);
    list.PrintList();

    cout << "\nDeleting Node 20:\n";
    list.DeleteNode(20);
    cout << "Print List:\n";
    list.PrintList();

    list.ClearList();
    return 0;
}