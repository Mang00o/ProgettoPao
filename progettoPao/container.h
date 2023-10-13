#ifndef CONTAINER_H
#define CONTAINER_H

#include "food.h"

class Container{
    private:
        class Nodo{
            public:
                Food* info;
                Nodo* next;
                Nodo(Food* i = nullptr, Nodo* n = nullptr) : info(i), next(n){}
        };
        Nodo* first;
    public:
        Container(Nodo* n = nullptr);
        ~Container();
        void insert(Food* x);
        QString* read() const;
        void removeAtIndex(int index);
        QString searchMax(int p) const;
        bool isEmpty() const;
        int countElements() const;
        Food* at(int index) const;
        class Iterator{
            friend class Container;
            private:
                Nodo* ptr;
                Iterator(Nodo* p): ptr(p){}
            public:
                Iterator() : ptr(nullptr){}
                Iterator& operator++();
                Iterator operator++(int);
                bool operator==(const Iterator& cit) const;
                bool operator!=(const Iterator& cit) const;
                QString getName() const;
                int getCarb() const;
                int getProtein() const;
                int getFat() const;
                Food* getFood() const;
        };
        Iterator begin() const;
        Iterator end() const;
        Iterator middle(int index) const;
};

#endif // CONTAINER_H
