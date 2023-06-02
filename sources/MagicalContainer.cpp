#include "MagicalContainer.hpp"
#include <stdio.h>

namespace ariel{}
using namespace std;


void MagicalContainer::addElement(int element){
    this->elements.emplace_back(element);
}

void MagicalContainer::removeElement(int element){
    //elements.erase(std::remove(elements.begin(), elements.end(), element), elements.end());
}

int MagicalContainer::size() {
    return elements.size();
}


// ------------------------- AscendingIterator -------------------------
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

// ------------------------- Operators -------------------------

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() {
    index++;
    return *this;
}

bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const { return container.elements[index] == container.elements[other.index]; }

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const { return !(*this == other); }

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const { return container.elements[index] > container.elements[other.index]; }

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const { return container.elements[index] < container.elements[other.index]; }

int MagicalContainer::AscendingIterator::operator*() const { return container.elements.at(index); }

// ***********************************************
//              SideCrossIterator
// ***********************************************
// Constuctor.
MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& cont) : container(cont) {}


// Assigment operator.
MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const MagicalContainer::SideCrossIterator &other) {
    return *this;
}
MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(MagicalContainer::SideCrossIterator &&other)noexcept {
    return *this;
}

// ------------------------- Operators -------------------------

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {
    return *this;
}

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const { return container.elements[index] == container.elements[other.index]; }

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const { return !(*this == other); }

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const { return container.elements[index] > container.elements[other.index]; }

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const { return container.elements[index] < container.elements[other.index]; }

int MagicalContainer::SideCrossIterator::operator*() const { return container.elements[index]; }


// ------------------------- PrimeIterator -------------------------
// Constuctor.
MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& cont) : container(cont) {}
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
    return *this;
}

bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const { return false; }

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const { return false; }

bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const { return false; }

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const { return false; }

int MagicalContainer::PrimeIterator::operator*() const { return false; }