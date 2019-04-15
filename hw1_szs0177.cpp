//Suryansh soni
//szs0177
//hw1_szs0177.cpp
//The program calculates the fatal amount of diet coke
//i received no help at all. i am a genius

#include <iostream>
using namespace std;

int main() {
double const FractionOfSweetnerInCoke = 0.001;
double FatalAmountHuman, WeightHuman, WeightMouse, FatalAmountMouse;

std::cout<<"Please input the weight of the mouse in kg\n";
std::cin>>WeightMouse;

std::cout<<"Please input the fatal amount of sweetner for mouse in kg\n";
std::cin>>FatalAmountMouse;

std::cout<<"Please input the weight of your dear friend in kg\n";
std::cin>>WeightHuman;

FatalAmountHuman = (FatalAmountMouse*WeightHuman)/(WeightMouse*FractionOfSweetnerInCoke);

std::cout<<"The fatal amount of Coke for your friend is: "<< FatalAmountHuman<< " kg\n";
std::cout<<endl;
}

