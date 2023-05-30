#ifndef MAGICALCONTAINER_H
#define MAGICALCONTAINER_H

namespace ariel{}

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stdexcept>

// ------------------------------------------------------- MagicalContainer -------------------------------------------------------
class MagicalContainer {
private:
    std::vector<int> elements;

public:
    void addElement(int element);

    void removeElement(int element);

    int size();

    // ------------------------------------------------------- AscendingIterator -------------------------------------------------------
    class AscendingIterator {
        private:
            MagicalContainer& container;
            int index;

        public:
            AscendingIterator(MagicalContainer& cont);

            // Copy constructor.
            AscendingIterator(const AscendingIterator &other) = default;

            // Destructor.
            ~AscendingIterator() = default;

            AscendingIterator& operator++();

            bool operator==(const AscendingIterator& other) const;

            bool operator!=(const AscendingIterator& other) const;

            bool operator>(const AscendingIterator& other) const;

            bool operator<(const AscendingIterator& other) const;

            int operator*() const;

            AscendingIterator begin() {
                return AscendingIterator(*this);
            }

            AscendingIterator end() {
                return AscendingIterator(this->container, container.size());
            }
    };

   

    // ------------------------------------------------------- SideCrossIterator -------------------------------------------------------
    class SideCrossIterator {
    private:
        MagicalContainer& container;
        int index;

    public:
        SideCrossIterator(MagicalContainer& cont, int index) : container(cont), index(index) {}

        // copy constructor
        SideCrossIterator(const SideCrossIterator &other) = default;

        // destructor
        ~SideCrossIterator() = default;

        SideCrossIterator& operator++();

        bool operator==(const SideCrossIterator& other) const;

        bool operator!=(const SideCrossIterator& other) const;

        bool operator>(const SideCrossIterator& other) const;

        bool operator<(const SideCrossIterator& other) const;

        int operator*() const;
    };

    SideCrossIterator begin() {
        return SideCrossIterator(*this, 0);
    }

    SideCrossIterator end() {
        return SideCrossIterator(*this, elements.size());
    }

    class PrimeIterator{
        private:
            MagicalContainer& container;
            int index;

        public:
            PrimeIterator(MagicalContainer& cont, int index) : container(cont), index(index) {}

            // copy constructor
            PrimeIterator(const PrimeIterator &other) = default;

            // destructor
            ~PrimeIterator() = default;


            PrimeIterator& operator++();

            bool operator==(const PrimeIterator& other) const;

            bool operator!=(const PrimeIterator& other) const;

            bool operator>(const PrimeIterator& other) const;

            bool operator<(const PrimeIterator& other) const; 

            int operator*() const;

            PrimeIterator begin() {
                return PrimeIterator(*this, 0);
            }

            PrimeIterator end() {
                return PrimeIterator(*this, elements.size());
            }

    };
    
    
};

#endif