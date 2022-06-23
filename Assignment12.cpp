#include <iostream>
using namespace std;

template<class T>
class Stack 
{
private:
    int Size;
    int Top;
    T* Data;
public:
    Stack(int = 9);
    ~Stack();
    bool Push(const T&);
    bool Pop(T&);
    bool isEmpty() const;
    bool isFull() const;
};

template<class T>
Stack<T> ::Stack(int n) 
{
    if (n > 0 && n < 9999)
        Size = n;
    else
        Size = 9;
    Top = -1;
    Data = new T[Size];
}

template<class T>
Stack<T> ::~Stack() 
{
    delete[] Data;
}

template<class T>
bool Stack<T> ::Push(const T& Item) 
{
    if (!isFull()) 
    {
        Top++;
        Data[Top] = Item;
        return true;
    }
    return false;
}

template<class T>
bool Stack<T> ::Pop(T& Item) 
{
    if (!isEmpty()) 
    {
        Item = Data[Top];
        Top--;
        return true;
    }
    return false;
}

template<class T>
bool Stack<T>::isEmpty() const 
{
    if (Top == -1)
        return true;
    return false;
}

template<class T>
bool Stack<T>::isFull() const 
{
    if (Top == Size)
        return true;
    return false;
}

int main() 
{
    Stack<int> a(99);
    int d;

    a.Push(30);
    a.Push(4);
    a.Push(75);
            
    while (a.Pop(d)) 
        cout << d << endl;
}