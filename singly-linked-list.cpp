#include <iostream>

template <typename T>
class Node
{
private:
    T data;
    Node<T> *next;

public:
    Node(T data)
    {
        this->data = data;
        next = nullptr;
    }

    T GetData() { return data; };
    Node<T> *GetNext() { return next; };

    void SetData(T data) { this->data = data; };
    void SetNext(Node<T> *next) { this->next = next; };
};

template <typename T>
class LinkedList
{
private:
    Node<T> *head = nullptr;
    Node<T> *tail = nullptr;

public:
    void AddNode(T data)
    {
        Node<T> *new_node = new Node<T>(data);
        if (head == nullptr)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            tail->SetNext(new_node);
            tail = new_node;
        }
    }
    void printList()
    {
        Node<T> *current = head;
        while (current != nullptr)
        {
            std::cout << current->GetData() << '\n';
            current = current->GetNext();
        }
    }
    void deleteNode(T remValue)
    {
        Node<T> *current = head;
        Node<T> *previous = nullptr;

        while (current != nullptr)
        {
            if (current->GetData() == remValue)
            {
                if (previous == nullptr)
                {
                    head = current;
                }
                else if (current == tail)
                {
                    tail = previous;
                }
                else
                {
                    previous->SetNext(current->GetNext());
                }
                delete current;
                return;
            }
            previous = current;
            current = current->GetNext();
        }
    }
};

int main()
{
    LinkedList<std::string> list;
    list.AddNode("one");
    list.AddNode("two");
    list.AddNode("three");

    list.printList();

    list.deleteNode("two");

    list.printList();
}