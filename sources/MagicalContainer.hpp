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
    std::vector<int*> primes;
    bool isPrime(int num);

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
            AscendingIterator(MagicalContainer &container,size_t index);

            // --------- TO PASS TIDY --------
            // Copy constructor.
            AscendingIterator(const AscendingIterator &other) = default;
            // Destructor.
            ~AscendingIterator() = default;
            // Move constructor.
            AscendingIterator(AscendingIterator&& other) = delete; 
            // Assigment operator.
            AscendingIterator& operator=(AscendingIterator&& other)noexcept;
            AscendingIterator& operator=(const AscendingIterator& other);

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
                
                return MagicalContainer::AscendingIterator(this->container,  static_cast<size_t>(this->container.size())); 
            }
    };

   

    // ------------------------------------------------------- SideCrossIterator -------------------------------------------------------
    class SideCrossIterator {
    private:
        MagicalContainer& container;
        size_t index;

    public:
        SideCrossIterator(MagicalContainer& cont);

        // --------- TO PASS TIDY --------
        // Copy constructor.
        SideCrossIterator(const SideCrossIterator &other) = default;
        // Destructor.
        ~SideCrossIterator() = default;
        // Move constructor.
        SideCrossIterator(SideCrossIterator&& other) = delete; 
        // Assigment operator.
        SideCrossIterator& operator=(SideCrossIterator&& other) noexcept;
        SideCrossIterator& operator=(const SideCrossIterator& other);

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
            PrimeIterator(MagicalContainer &container,size_t index);

            // --------- TO PASS TIDY --------
            // copy constructor
            PrimeIterator(const PrimeIterator &other) = default;
            // destructor
            ~PrimeIterator() = default;
            // Move
            PrimeIterator(PrimeIterator&& other) = delete;   
            // Assigment
            PrimeIterator& operator=(PrimeIterator&& other)noexcept;
            PrimeIterator& operator=(const PrimeIterator& other);

            PrimeIterator& operator++();

            bool operator==(const PrimeIterator& other) const;

            bool operator!=(const PrimeIterator& other) const;

            bool operator>(const PrimeIterator& other) const;

            bool operator<(const PrimeIterator& other) const; 

            int operator*() const;

            PrimeIterator begin() {
                return PrimeIterator(this->container,0);
            }

            PrimeIterator end() {
                return PrimeIterator(this->container, this->container.primes.size());
            }

    };
    
    
};

#endif