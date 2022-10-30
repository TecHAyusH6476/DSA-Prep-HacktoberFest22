// Stack operations shown using Array
#include <bits/stdc++.h>
using namespace std;

// Push Element to Stack
void push(int num, int arr[], int *top, int maxSz) {
    if(*top == maxSz - 1) {
        cout << "Stack Overflow!!!" << endl;
        return;
    }
    arr[++(*top)] = num;
    cout << endl;
    return;
}

// Pop Element from Stack
void pop(int arr[], int *top) {
    if(*top == -1) {
        cout << "Stack Underflow!!!" << endl;
        return;
    }
    cout << "Element Deleted : " << arr[(*top)--] << endl;
    return;
}

// Check size of Stack
void size(int arr[], int *top, int maxSz) {
    if(*top == maxSz - 1) {
        cout << "Stack Overflow!!!" << endl;
        return;
    }
    if(*top == -1) {
        cout << "Stack Underflow!!!" << endl;
        return;
    }
    cout << "Stack Size : " << ((*top) + 1) << endl;
    return;
}

// Determine top element of stack
void topEle(int arr[], int *top) {
    if(*top == -1) {
        cout << "Stack Underflow!!!" << endl;
        return;
    }
    cout << "Top Element : " << arr[*top] << endl;
}

// Chcek if stack is empty or not
void checkEmpty(int arr[], int *top) {
    if(*top == -1)  cout << "Stack is Empty!!!" << endl;
    else cout << "Stack is not Empty!!!" << endl;
    return;
}

// Check if Stack is overflowed or not
void checkOver(int arr[], int *top, int maxSz) {
    if(*top == maxSz - 1) cout << "Stack is Completely Full!!!" << endl;
    else cout << "Stack is not full!!!" << endl;
    return;
}

// Printing Stack
void printStack(int arr[], int *top) {
    cout << "Stack is : ";
    for(int i = *top; i >= 0; i--) cout << arr[i] << " ";
    cout << endl;
    return;
}

// Main Method
int main() {
    int maxSz, ch, top = -1;
    cout << "Enter stack max size : ";
    cin >> maxSz;
    int arr[maxSz];
    
    while(1) {
        cout << "\nEnter 1. To Push" << endl;
        cout << "Enter 2. To Pop" << endl;
        cout << "Enter 3. To Check Size" << endl;
        cout << "Enter 4. To Check Max-Size" << endl;
        cout << "Enter 5. To Show the Top element" << endl;
        cout << "Enter 6. To Check for Empty Stack" << endl;
        cout << "Enter 7. To Check for Overflow" << endl;
        cout << "Enter 8. To Print the Stack" << endl;
        cout << "Enter 9. To Exit" << endl;
        cout << "Enter your choice : ";
        cin >> ch;
        switch(ch) {
            case 1:
                int num;
                cout << "Enter number : ";
                cin >> num;
                push(num, arr, &top, maxSz);
                break;
            
            case 2:
                pop(arr, &top);
                break;
                
            case 3:
                size(arr, &top, maxSz);
                break;
            
            case 4:
                cout << "Max-Size of stack : " << maxSz << endl;
                break;
            
            case 5:
                topEle(arr, &top);
                break;
            
            case 6:
                checkEmpty(arr, &top);
                break;
                
            case 7:
                checkOver(arr, &top, maxSz);
                break;
                
            case 8:
                printStack(arr, &top);
                break;
            
            case 9:
                exit(0);
                break;
            
            default:
                cout << "Wrong Choice!!!" << endl;
        }
    }
    return 0;
}