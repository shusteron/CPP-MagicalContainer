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
MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& cont) : container(cont) {}

// ------------------------- Operators -------------------------

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() {
    index++;
    return *this;
}

bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const { return container.elements[index] == container.elements[other.index]; }

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const { return !(*this == other); }

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const { return container.elements[index] > container.elements[other.index]; }

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const { return container.elements[index] < container.elements[other.index]; }

int MagicalContainer::AscendingIterator::operator*() const { return container.elements[index]; }