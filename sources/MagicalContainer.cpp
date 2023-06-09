#include "MagicalContainer.hpp"
#include <stdio.h>
#include <cmath>

namespace ariel{}
using namespace std;


void MagicalContainer::addElement(int element){
    // // If element is prime insert him in the primes vector to.
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

void MagicalContainer::removeElement(int element) {
    auto iterator = std::find(elements.begin(), elements.end(), element);
    if (iterator != elements.end()) {
        elements.erase(iterator);
    } else {
        throw std::runtime_error("Element not found in container.");
    }
}


size_t MagicalContainer::size() const {
    return elements.size();
}

bool MagicalContainer::isPrime(int num){
    if(num <= 1) return false;
    if(num==2) return true;

    for(int i=2; i < (num); i++){
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
            throw std::runtime_error("Iterators from different containers cannot be assinged.");
        }

        index = other.index;
        container = other.container;
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
    if(this->index >= container.size())
        throw runtime_error("Index out of bounds");
    ++this->index;
    return *this;
}

bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const { return index == (other.index); }

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const { return this->index != other.index; }

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const { return index > (other.index); }

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const { return index < (other.index); }

int MagicalContainer::AscendingIterator::operator*() const {
    if(this->index > container.sorted.size())
        throw out_of_range("Index out of bounds");
    return *(container.sorted.at(this->index));
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() const{
    return MagicalContainer::AscendingIterator(this->container,0);
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() const {
    return MagicalContainer::AscendingIterator(this->container,(this->container.size()));
}

// ********************************************************************************************************
//              SideCrossIterator
// ********************************************************************************************************
// Constuctor.
MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& cont) : container(cont), index(0) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& cont, size_t index) : container(cont), index(index) {}



// Assigment operator.
MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const MagicalContainer::SideCrossIterator &other) {
      if (this != &other){
        if (&container != &other.container){
            throw runtime_error("Iterators from different containers cannot be assinged.");
        }
        container = other.container;
        index = other.index;
    }

    return *this;
}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(MagicalContainer::SideCrossIterator &&other)noexcept {
    return *this;
}

// --------------------- Operators ---------------------

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {
  if (this->index >= this->container.size()){
        throw std::runtime_error("Index out of bounds.");
    }
    ++ this->index;
    return *this;
}

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const { return index == other.index; }

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const { return !(*this == other); }

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const { return index > other.index; }

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const { return index < other.index; }

int MagicalContainer::SideCrossIterator::operator*() const { 
    // cross side will be left
    if (this->index%2 == 0) {
        return (container.elements.at(index/2)); 
    }
    // cross side will be right
    size_t disFromEnd = ((container).size() -1 -(this->index/2));
    return (container.elements.at(disFromEnd));
 }

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
    if(index >= container.primes.size())
        throw runtime_error(" Index out of bounds");
    ++index;
    return *this;
}

bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const { return index == other.index; }

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const { return !(*this == other); }

bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const { return index > other.index; }

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const { return (index) < (other.index); }

int MagicalContainer::PrimeIterator::operator*() const {  return *(container.primes.at(index));}