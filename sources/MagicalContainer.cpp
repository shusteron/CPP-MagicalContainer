#include "MagicalContainer.hpp"
#include <stdio.h>

namespace ariel{}
using namespace std;


void MagicalContainer::addElement(int element){
    // If element is prime insert him in the primes vector to.
    auto elemnt_address = new int(element);

    if(isPrime(element)){
        primes.emplace_back(elemnt_address);
        sort(primes.begin(), primes.end(), [](const int* a, const int* b) { return *a < *b; });
    }
    // Insert element in sorted vector, then sort.
    this->sorted.emplace_back(elemnt_address);
    sort(sorted.begin(), sorted.end(), [](const int* a, const int* b) { return *a < *b; });

    this->elements.emplace_back(element);
}

void MagicalContainer::removeElement(int element){
    for(auto& elem : primes){
        if(*elem == element){
            delete elem;
        }
        auto iterator = std::find(primes.begin(), primes.end(), elem);
        primes.erase(iterator);
    }
    elements.erase(remove(elements.begin(), elements.end(), element), elements.end());
}

size_t MagicalContainer::size() const {
    return elements.size();
}

bool MagicalContainer::isPrime(int num){
    if(num <= 1){
        return false;
    }

    for(int i=3; i < sqrt(num); i+=2){
        if( num % i == 0){
            return false;
        }
    }
    return true;
}

// ********************************************************************************************************
//                 AscendingIterator 
// ********************************************************************************************************
// Constructor.
MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& cont) : container(cont),index(0) {}

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container,size_t index) :container(container),index(index){}

// Assigment 
MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const MagicalContainer::AscendingIterator &other) {
    if (this != &other)
    {
        if (&container != &other.container)
        {
            throw std::runtime_error("Iterators from different containers cannot be assinged");
        }

        index = other.index;
    }

    return *this;
}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(MagicalContainer::AscendingIterator &&other) noexcept {
    if (this != &other) {
        container = other.container;
        index = other.index;
    }
    return *this;
}

// --------------------- Operators ---------------------

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() {
    cout << "++"<<endl;

    if(this->index > container.size())
        throw runtime_error("Index out of bounds");
    ++this->index;
    return *this;
}

bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const { return container.elements.at(index) == container.elements.at(other.index); }

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const { return !(*this == other); }

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const { return container.elements.at(index) > container.elements.at(other.index); }

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const { return container.elements.at(index) < container.elements.at(other.index); }

int MagicalContainer::AscendingIterator::operator*() const {
    cout << "*"<<endl;
    if(this->index > container.size())
        throw runtime_error("Index out of bounds");
    return *(container.sorted.at(this->index));
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() const{
    std::cout << "begin"<<std::endl;
    return MagicalContainer::AscendingIterator(this->container,0);
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() const {
    std::cout << "end"<<std::endl;
    return MagicalContainer::AscendingIterator(this->container,(this->container.size()));
}

// ********************************************************************************************************
//              SideCrossIterator
// ********************************************************************************************************
// Constuctor.
MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& cont) : container(cont) {}


// Assigment operator.
MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const MagicalContainer::SideCrossIterator &other) {
    return *this;
}
MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(MagicalContainer::SideCrossIterator &&other)noexcept {
    return *this;
}

// --------------------- Operators ---------------------

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {
  if (this->index == (this->container.size())){
        throw std::runtime_error("Index out of bounds.");
    }
    ++ this->index;
    return *this;
}

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const { return container.elements[index] == container.elements[other.index]; }

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const { return !(*this == other); }

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const { return container.elements[index] > container.elements[other.index]; }

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const { return container.elements[index] < container.elements[other.index]; }

int MagicalContainer::SideCrossIterator::operator*() const { return container.elements[index]; }

// ********************************************************************************************************
//                 PrimeIterator 
// ********************************************************************************************************
//Default constructor
MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container)
        :container(container),index(0)
{}
//Default complete constructor
MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container,size_t index)
        :container(container),index(index)
{}

// Assigment
MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const MagicalContainer::PrimeIterator &other) {
    if (this != &other)
    {
        if (&container != &other.container){throw std::runtime_error("Iterators from different containers cannot be assinged");}

        index = other.index;
    }
    return *this;
}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(MagicalContainer::PrimeIterator&& other) noexcept {
    if (this != &other) {
        container = other.container;
        index = other.index;
    }
    return *this;
}

// ------------------------- Operators -------------------------

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() {
    index++;
    if(index > container.primes.size())
        throw runtime_error(" Index out of bounds");
    return *this;
}

bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const { return container.primes.at(index) == container.primes.at(other.index); }

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const { return !(*this == other); }

bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const { return container.primes.at(index) > container.primes.at(other.index); }

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const { return container.primes.at(index) < container.primes.at(other.index); }

int MagicalContainer::PrimeIterator::operator*() const {  return *(container.primes.at(index));}