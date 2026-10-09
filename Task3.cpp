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

    list.CountNodes();
    list.PrintList();

    list.AddNode(10);
    list.CountNodes();
    list.PrintList();

    list.AddNode(20);
    list.AddNode(30);
    list.CountNodes();
    list.PrintList();

    list.ClearList();
    return 0;
}