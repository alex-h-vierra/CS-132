////
// Author:     Your Name 
// Section:    A or B
// Assignment:   #
// Description:  Short description of what the program accomplishes 
// (at least a couple sentences – also you should say where the input
// data comes from, what information is output, and where the output 
// data is sent to (the screen or a file)  
////

#include <iostream>

using namespace std;

class Node {
public:
    Node(int num ) {
        data = num;
        next = nullptr;
    }

    int data;   //purposely public
    Node* next;
};  // end of Node class


class Stack {
public:
    Stack(){
        // default constructor: create the empty stack and initialize your all member variables
        push(count);
        pop();
        top();
        isEmpty();
        getCount();
    }
    ~Stack() {      // OPTIONAL destructor
        // your code...and so on for each of the member functions
    }

    void push( int num ) { Node* temp = new Node(num); head->next = temp; head = temp;}  // you will need to add real code
    int pop( ) { return count; }
    int top( ) { return head->data; }
    bool isEmpty( ) { return head; }
    int getCount( ) { return count++; }

private:
    Node* head;
    int count;
};  // end of Stack class


int main( ){

    Stack stack;  // calls constructor

    cout << "Before pushing \n";
    cout << "Stack size: " << stack.getCount() << endl;
    cout << "Stack is " << (stack.isEmpty() == true? "empty\n": "not empty\n");

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);


    cout << "\nAfter pushing 1-5 \n";
    cout << "Stack size: " << stack.getCount() << endl;
    cout << "Stack is " << (stack.isEmpty() == true ? "empty\n": "not empty\n");
    cout << "Top of the stack is: " << stack.top() << "\n\n";

    // example output given below for above lines

    cout << "\nPopping off the stack: " << stack.pop() << endl;
    cout << "Popping off the stack: " << stack.pop() << endl;

    cout << "Stack size: " << stack.getCount() << endl;
    cout << "Stack is " << (stack.isEmpty() == true ? "empty\n": "not empty\n");
    cout << "Top of the stack is: " << stack.top() << "\n\n";

    stack.push(6);
    stack.push(7);

    cout << "After pushing 6-7 \n";
    cout << "Stack size: " << stack.getCount() << endl;
    cout << "Stack is " << (stack.isEmpty() == true ? "empty\n": "not empty\n");
    cout << "Top of the stack is: " << stack.top() << "\n\n";

    stack.push(8);
    stack.push(9);

    cout << "After pushing 8-9 \n";
    cout << "Stack size: " << stack.getCount() << endl;
    cout << "Stack is " << (stack.isEmpty() == true ? "empty\n": "not empty\n");
    cout << "Top of the stack is: " << stack.top() << "\n\n";

    while( stack.isEmpty() == false) {
        cout << "Popping off the stack: " << stack.pop() << endl;
    }

    cout << "Stack size: " << stack.getCount() << endl;
    cout << "Stack is " << (stack.isEmpty() == true ? "empty\n": "not empty\n");
    cout << "Top of the stack is: " << stack.top() << "\n\n";

}   // end of main