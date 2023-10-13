#include "container.h"
#include <QErrorMessage>

Container::Container(Nodo* n) : first(n){}

Container::~Container(){delete first;}

void Container::insert(Food* x){
    Nodo* newNodo = new Nodo(x);
    if(first == nullptr){
        first = newNodo;
    }else{
        Nodo* temp = first;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newNodo;
    }
}

QString* Container::read() const{
    unsigned int carb = 0, protein = 0, fat = 0;
    QString* text = new QString();
    if(this->isEmpty()){
        text->append("Aggiungi Cibo");
    }else{
        text->append("Il Menu comprende:\n");
        for(Container::Iterator i = this->begin(); i!=this->end(); ++i){
            text->append("\t" + i.getName() + "\n");
            carb += i.getCarb();
            protein += i.getProtein();
            fat += i.getFat();
        }
        text->append("per un totale di:\n"
                    +QString::number(carb)+" gr da carboidrati,\n"
                    +QString::number(protein)+" gr da proteine,\n"
                    +QString::number(fat)+" gr da grassi,\n"
                    "e "+QString::number(carb*4+protein*4+fat*9)+" kcals");
    }
    return text;
}

void Container::removeAtIndex(int index){
    if (first == nullptr) {
        QErrorMessage *err = new QErrorMessage;
        err->showMessage("Nessun elemento da eliminare");
    }else if (index == 0) {
        Nodo* temp = first;
        first = first->next;
        delete temp;
    }else{
        Nodo* current = first;
        Nodo* previous = nullptr;
        int currentIndex = 0;
        while (currentIndex != index) {
            previous = current;
            current = current->next;
            currentIndex++;
        }
        previous->next = current->next;
        delete current;
    }
}

QString Container::searchMax(int p) const{
    QString name;
    unsigned int max = 0;
    Nodo* temp = first;
    switch(p){
        case 1:
            while(temp != nullptr){
                if(temp->info->getKcal()>max){
                    max = temp->info->getKcal();
                    name = temp->info->getName();
                }
                temp = temp->next;
            }
            break;
        case 2:
            while(temp != nullptr){
                if(temp->info->getCarb()>max){
                    max = temp->info->getCarb();
                    name = temp->info->getName();
                }
                temp = temp->next;
            }
            break;
        case 3:
            while(temp != nullptr){
                if(temp->info->getProtein()>max){
                    max = temp->info->getProtein();
                    name = temp->info->getName();
                }
                temp = temp->next;
            }
            break;
        case 4:
            while(temp != nullptr){
                if(temp->info->getFat()>max){
                    max = temp->info->getFat();
                    name = temp->info->getName();
                }
                temp = temp->next;
            }
            break;
        default:
            break;
    }
    return name;
}

bool Container::isEmpty() const{
    if(first==nullptr)return true;
    return false;
}

int Container::countElements() const{
    int n = 0;
    Nodo* temp = first;
    while(temp != nullptr) {
        n++;
        temp = temp->next;
    }
    return n;
}

Food* Container::at(int index) const{
    int currentIndex=0;
    Nodo* currentNodo = first;
    while (currentIndex != index) {
        currentNodo = currentNodo->next;
        currentIndex++;
    }
    return currentNodo->info;
}

Container::Iterator Container::begin() const{
    if(first != nullptr) return Iterator(first);
    return Iterator();
}

Container::Iterator Container::end() const {
    if(first==nullptr)
        return nullptr;
    Nodo* temp = first;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    return Iterator(temp+1);
}

Container::Iterator Container::middle(int index) const{
    int currentIndex=0;
    Nodo* currentNodo = first;
    while (currentIndex != index) {
        currentNodo = currentNodo->next;
        currentIndex++;
    }
    return Iterator(currentNodo);
}
