#ifndef QUEUETP_H_
#define QUEUETP_H_

template <class T>
class QueueTp
{
private:
    struct Node {
        T item;
        Node* next;
    };
    Node* front;
    Node* rear;
    int items;
    const int qsize;

    // copy 금지
    QueueTp(const QueueTp& q) : qsize(0) {}
    QueueTp& operator=(const QueueTp& q) { return *this; }

public:
    QueueTp(int qs = 10);
    ~QueueTp();

    bool isempty() const { return items == 0; }
    bool isfull() const { return items == qsize; }
    bool enqueue(const T& item);
    bool dequeue(T& item);
};

// ---- 구현부 ----
template <class T>
QueueTp<T>::QueueTp(int qs) : qsize(qs)
{
    front = rear = nullptr;
    items = 0;
}

template <class T>
QueueTp<T>::~QueueTp()
{
    Node* temp;
    while (front != nullptr)
    {
        temp = front;
        front = front->next;
        delete temp;
    }
}

template <class T>
bool QueueTp<T>::enqueue(const T& item)
{
    if (isfull())
        return false;
    Node* add = new Node;
    add->item = item;
    add->next = nullptr;
    items++;

    if (front == nullptr)
        front = add;
    else
        rear->next = add;
    rear = add;
    return true;
}

template <class T>
bool QueueTp<T>::dequeue(T& item)
{
    if (isempty())
        return false;
    item = front->item;
    Node* temp = front;
    front = front->next;
    delete temp;
    items--;

    if (items == 0)
        rear = nullptr;

    return true;
}

#endif
