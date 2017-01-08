//
// Created by Le Van on 4/1/17.
//
#include <cstddef>

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

//size()
//empty() - bool returns true if empty
//get(index) - returns value at nth item - 0 for first
//push_front(value)
//pop_front() - remove front item and return its value
//push_back(value)
//pop_back()
//front()
//back()

template<class T>
class LinkedList
{
    struct Node {
        T _data;
        Node *_next;

        //Default constructor
        Node()
                : _next(NULL)
        {}

        //Parametrized constructor
        Node(const T& data)
                : _data(data)
                , _next(NULL)
        {}

        Node(const T& data, Node *next)
                : _data(data)
                , _next(next)
        {}
/*
        T get_data() {
            return _data;
        }

        Node<T>* get_next(){
            return _next;
        }
*/
    };

    Node *_head;

public:
    LinkedList();
    LinkedList(T data);
    ~LinkedList();
    size_t size();
    bool empty();
    T get(int index);
    void push_front(const T &data);
    T pop_front();
    void push_back(const T &data);
    T pop_back();
};
template<class T> LinkedList<T>::LinkedList()
        : _head(NULL)
{}

template<class T> LinkedList<T>::LinkedList(T data) {
    _head = new Node(data);
}

template<class T> LinkedList<T>::~LinkedList() {
    Node *cur = _head;
    while(cur != NULL){
        _head = cur->_next;
        delete cur;
        cur = _head;
    }
}

template<class T> T LinkedList<T>::get(int index) {
    Node *cur = _head;
    for (int i = 0; i < index; i++)
        cur = cur->_next;
    return cur->_data;
}

template<class T> size_t LinkedList<T>::size() {
    size_t size = 0;
    for (Node *cur = _head; cur != NULL; cur = cur->_next)
        size++;
    return size;
}

template<class T> bool LinkedList<T>::empty() {
    if (_head == NULL)
        return true;
}

template<class T> void LinkedList<T>::push_front(const T &data) {
    Node *front = new Node(data,_head);
    //front->_data = data;
    //front->_next = _head;
    _head = front;
}

template<class T> T LinkedList<T>::pop_front() {
    T data = _head->_data;
    Node *pop = _head;
    _head = pop->_next;
    delete pop;
    return data;
}

template<class T> void LinkedList<T>::push_back(const T &data) {
    Node *back = new Node(data);
    Node *cur = _head;
    while (cur->_next != NULL)
        cur = cur->_next;
    cur->_next = back;
}

template<class T> T LinkedList<T>::pop_back() {
    Node *cur = _head;
    if (cur->_next == NULL){
        _head = NULL;
        T data = cur->_data;
        delete cur;
        return data;
    }
    while (cur->_next->_next != NULL)
        cur = cur->_next;
    Node *pop = cur->_next;
    T data = pop->_data;
    cur->_next = NULL;
    delete pop;
    return data;
}
#endif //LINKED_LIST_LINKEDLIST_H
