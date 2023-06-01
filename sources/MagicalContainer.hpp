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
            size_t index;

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
                return *this;
            }
    };

   

    // ------------------------------------------------------- SideCrossIterator -------------------------------------------------------
    class SideCrossIterator {
    private:
        MagicalContainer& container;
        size_t index;

    public:
        SideCrossIterator(MagicalContainer& cont);

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

        SideCrossIterator begin() {
            return *this;
        }

        SideCrossIterator end() {
            return *this;
        }
    };


    class PrimeIterator{
        private:
            MagicalContainer& container;
            size_t index;

        public:
            PrimeIterator(MagicalContainer& cont);

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
                return *this;
            }

            PrimeIterator end() {
                return *this;
            }

    };
    
    
};

#endif