#include "container.h"

Container::Iterator& Container::Iterator::operator++() {
    if(ptr){
        if(ptr->next==nullptr) ptr = ptr+1;
        else ptr = ptr->next;
    }
    return *this;
}

Container::Iterator Container::Iterator::operator++(int) {
    Iterator tmp(*this);
    if(ptr){
        if(ptr->next==nullptr) ptr += 1;
        else ptr = ptr->next;
    }
    return tmp;
}

bool Container::Iterator::operator==(const Iterator& cit) const {
    return ptr == cit.ptr;
}

bool Container::Iterator::operator!=(const Iterator& cit) const {
    return ptr != cit.ptr;
}

QString Container::Iterator::getName() const {
    return ptr->info->getName();
}

int Container::Iterator::getCarb() const {
    return ptr->info->getCarb();
}

int Container::Iterator::getProtein() const {
    return ptr->info->getProtein();
}

int Container::Iterator::getFat() const {
    return ptr->info->getFat();
}

Food* Container::Iterator::getFood() const{
    return ptr->info;
}
