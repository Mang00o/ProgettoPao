#include "food.h"

Food::Food(QString n, unsigned int c, unsigned int p, unsigned int f)
: name(n), carb(c), protein(p), fat(f){}

Food::Food(const Food& f) : name(f.name), carb(f.carb), protein(f.protein), fat(f.fat){}

Food::~Food(){}

QString Food::getName() const {return name;}

unsigned int Food::getCarb() const {return carb;}

unsigned int Food::getProtein() const {return protein;}

unsigned int Food::getFat() const {return fat;}

unsigned int Food::getKcal() const{return kcal;}

void Food::updateKcal(){kcal = carb*4+protein*4+fat*9;}

void Food::setName(QString n){name = n;}

void Food::setCarb(unsigned int c){carb = c; updateKcal();}

void Food::setProtein(unsigned int p){protein = p; updateKcal();}

void Food::setFat(unsigned int f){fat = f; updateKcal();}
