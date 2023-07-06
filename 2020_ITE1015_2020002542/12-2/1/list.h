//list.h
#include <iostream>
using namespace std;

template <class T>
class Node
{
    public:
        T data;
        Node<T>* next;
};

template <class T>
class List
{
    private:
        Node<T>* head;// head is only one! head only points first node!
    public:
        List() : head(NULL) {}
        ~List()
        {
            Node<T>* endPoint = head;
            while (head == NULL) {
                endPoint = head;
                while ((endPoint->next)->next!=NULL)
                    endPoint = endPoint->next;

                delete endPoint->next;
                endPoint->next = NULL;
            }
        }

        List(T* arr, int n_nodes)
        {
            head = new Node<T>;
            Node<T>* tail = head;
            head->data = arr[0];

            for (int i=1; i<n_nodes; i++) {
                Node<T>* temp = new Node<T>;
                temp->data = arr[i];
                tail->next = temp;
                tail = temp;
            }
            tail->next = NULL;
        }

        void insert_at(int idx, const T& data)
        {
            Node<T>* temp = new Node<T>;
            temp->data = data;
            Node<T>* idx_num = head;
            for (int i=0; i<idx-1; i++)
                idx_num = idx_num->next; //front of index node.
            temp->next = idx_num->next; 
            idx_num->next = temp;
        }

        void remove_at(int idx)
        {
            Node<T>* rm_idx = head;
            Node<T>* frontOfRm = head;
            for (int i=0; i<idx; i++) {
                rm_idx = rm_idx->next;
                frontOfRm = frontOfRm->next;
            }
            rm_idx = rm_idx->next;

            frontOfRm->next = rm_idx->next;
            delete rm_idx;
        }

        void pop_back()
        {
            Node<T>* idx = head;
            while(true) {
                if ((idx->next)->next == NULL)
                    break;
                else 
                    idx = idx->next;
            }

            Node<T>* temp = idx->next;
            idx->next = NULL;
            delete temp;
        }

        void push_back(const T& val)
        {
            Node<T>* idx = head;
            while(true) {
                if (idx->next == NULL)
                    break;
                else
                    idx = idx->next;
            }

            Node<T>* newNode = new Node<T>;
            newNode->data = val;
            newNode->next = NULL;
            idx->next = newNode;
        }

        void pop_front()
        {
            Node<T>* rm = head;
            head = head->next;
            delete rm;
        }
        
        void push_front(const T& val)
        {
            Node<T>* newNode = new Node<T>;
            newNode->data = val;
            newNode->next = head;
            head = newNode;
        }

        friend ostream& operator<<(ostream& out, List& rhs)
        {
            Node<T>* idx = rhs.head;
            while (idx!=NULL) {
                out << idx->data;
                if (idx->next!=NULL)
                    out << ", ";
                idx = idx->next;
            }
            return out;
        }
};
