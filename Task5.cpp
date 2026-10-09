#include <iostream>
using namespace std;

class ArrayStack{
    public:
        int items[5];
        int top = -1;

        bool IsEmpty(){
            return top == -1;
        }

        bool IsFull(){
            return top == 4;
        }

        void Push(int value){
            if (IsFull())
                cout << "Stack is Full, Cannot Push!!!\n";
            else{
                top ++;
                items[top] = value;
            }
        }

        void Pop(){
            if (IsEmpty())
                cout << "Stack is Empty!!!\n";
            else{
                cout << "Value at Top: " << items[top] << endl;
                top--;
            }
        }

        void Peek(){
            if (IsEmpty())
                cout << "Stack is Empty!!!\n";
            else
                cout << "Value at Top: " << items[top] << endl;
        }

        void Display(){
            int current = top;

            if (IsEmpty())
                cout << "Stack is Empty!!!\n";
            else
                while (current != -1)
                {
                    cout << items[current] << endl ;
                    current--;
                }
                
        }
};
int main(){
    ArrayStack stack;

    cout << "Pushing 10, 20, 30, 40, 50, 60:\n";
    stack.Push(10);
    stack.Push(20);
    stack.Push(30);
    stack.Push(40);
    stack.Push(50);
    stack.Push(60);
    stack.Display();

    cout << "Popping 50:\n";
    stack.Pop();

    cout << "Peeking 40:\n";
    stack.Peek();

    cout << "Popping the Entire Stack:\n";
    stack.Pop();
    stack.Pop();
    stack.Pop();
    stack.Pop();
    cout << "Extra Pop:\n";
    stack.Pop();
    return 0;
}