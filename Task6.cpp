#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

class LinkedStack{
    private:
        node* top = nullptr;

    public:

        bool IsEmpty(){
            return top == nullptr;
        }

        void Push(int value){
            node* newNode = new node{value, top};
            top = newNode;
        }

        void Pop(){
            if (IsEmpty())
                cout << "Linked Stack is Empty!!!\n";
            else{
                node* topNode = top;

                cout << "Value at Top: " << top -> data << endl;
                top = top -> next;

                delete topNode;
            }
        }

        void Peek(){
            if (IsEmpty())
                cout << "Linked Stack is Empty!!!\n";
            else
                cout << "Value at Top: " << top -> data << endl;
        }

        void Display(){
            if (IsEmpty())
                cout << "Linked Stack is Empty!!!\n";
            else{
                node* currentNode = top;

                while(currentNode != nullptr){
                    cout << currentNode -> data << endl;
                    currentNode = currentNode -> next;
                }
            }
        }

        void ClearStack(){
            node* nextNode;

            while (top != nullptr){
                nextNode = top -> next;
                delete top;

                top = nextNode;
            }
        }
};
int main(){
    LinkedStack stack;
    int option = -1;

    while (option != 5){
        cout << "\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter Option: ";
        cin >> option;

        switch (option){
            case 1:
                int value;
                cout << "Enter Value to Push: ";
                cin >> value;
                stack.Push(value);
                break;
            case 2:
                stack.Pop();
                break;
            case 3:
                stack.Peek();
                break;
            case 4:
                stack.Display();
                break;
            case 5:
                cout << "Exiting Program!!!\n";
                stack.ClearStack();
                break;
            default:
                cout << "Invalid Option!!!\n";
        }
    }
    return 0;
}