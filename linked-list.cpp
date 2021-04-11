#include <iostream>

using namespace std;

template <typename T>
class Node {
    public:
        T data;
        Node<T>* next_;

        Node(T data, Node<T>* next_ = nullptr) {
            this->next_ = next_;
            this->data = data;
        }
};


template <typename T>
class LinkedList {
    protected:
        size_t n = 0;
        Node<T>* head = nullptr;

    public:
        T get(size_t pos) {
            if (pos >= this->n) throw "Exceed bound";
            Node<T>* curr = this->head;
            while (pos--) {
                curr = curr->next;
            }
            return curr->data;
        }

        void insert(size_t pos, T data) {
            if (pos > this->n) throw "Exceed bound";

            Node<T>* new_node = new Node<T>(data);

            if (pos == 0) {
                new_node->next_ = this->head;
                this->head = new_node;
                ++this->n;
                return;
            }

            pos = pos - 1;
            Node<T>* curr = this->head;
            while (pos--) {
                curr = curr->next_;
            }
            new_node->next_ = curr->next_;
            curr->next_ = new_node;
            ++this->n;
        }

        T remove(size_t pos) {
            if (pos > this->n) throw "Exceed bound";

            if (pos == 0) {
                Node<T>* deleted_node = this->head;
                this->head = deleted_node->next_;
                --this->n;
                return deleted_node->data;
            }

            pos = pos - 1;
            Node<T>* curr = this->head;
            while (pos--) {
                curr = curr->next_;
            }
            Node<T>* deleted_node = curr->next_;
            curr->next_ = deleted_node->next_;
            --this->n;
            return deleted_node->data;
        }

        bool empty() {
            return this->n == 0;
        }
};

template <typename T>
class Stack : protected LinkedList<T> {
    public:
        T pop() {
            return this->remove(0);
        }

        void push(T data) {
            this->insert(0, data);
        }

        bool empty() {
            return LinkedList<T>::empty();
        }
};

template <typename T>
class Queue : protected LinkedList<T> {
    public:
        T pop() {
            return this->remove(this->n-1);
        }

        void push(T data) {
            this->insert(0, data);
        }

        bool empty() {
            return LinkedList<T>::empty();
        }
};

int main() {
    Stack<int> s;
    Queue<int> q;

    for (int i = 0; i < 5; ++i) {
        s.push(i);
        q.push(i);
    }

    cout << "Stack:\n";
    while (!s.empty()) {
        cout << s.pop() << " ";
    }
    cout << "\n";

    cout << "Queue:\n";
    while (!q.empty()) {
        cout << q.pop() << " ";
    }
    cout << "\n";

    return 0;
}
