#include "doctest.h"
#include "MagicalContainer.hpp"
// Tests for the MagicalContainer class
TEST_CASE("MagicalContainer") {
    MagicalContainer container;

    SUBCASE("addElement() and size()") {
        container.addElement(10);
        container.addElement(20);

        CHECK(container.size() == 2);
        CHECK_NOTHROW(container.size());
        container.addElement(5);
        CHECK(container.size() == 3);
    }

    SUBCASE("removeElement() and size()") {
        container.addElement(10);
        container.addElement(20);
        container.removeElement(10);

        CHECK(container.size() == 1);
        CHECK_NOTHROW(container.removeElement(3));

        // Size should remain the same, '3' is not exist in the container.
        CHECK(container.size() == 1);

    }

}

TEST_CASE("AscendingIterator") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.addElement(11);
    container.addElement(22);


    SUBCASE("Iterate elements && operator ==") {
        MagicalContainer::AscendingIterator it(container);
        CHECK(*it == 1);
        ++it;
        CHECK(*it == 11);
        ++it;
        CHECK(*it == 2);
        ++it;
        CHECK(*it == 11);
        ++it;
        CHECK(*it == 22);
        ++it;
        CHECK(it == it.end());
    }

     SUBCASE("Comparison"){
        MagicalContainer::AscendingIterator it1(container);
        MagicalContainer::AscendingIterator it2(container);
        
        ++it2;
        CHECK(*it1 < *it2);
        ++it1;
        ++it1;
        CHECK(*it1 > *it2);
        CHECK(*it1 != *it2);
    }
}


TEST_CASE("SideCrossIterator") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);

    SUBCASE("Iterating elements && operator ==") {
        MagicalContainer::SideCrossIterator it(container);
        CHECK(*it == 1);
        ++it;
        CHECK(*it == 4);
        ++it;
        CHECK(*it == 2);
        ++it;
        CHECK(*it == 3);
        ++it;
        CHECK(it == it.end());
    }

    SUBCASE("Comparation"){
        MagicalContainer::AscendingIterator it1(container);
        MagicalContainer::AscendingIterator it2(container);

        ++it2;
        CHECK(*it1 < *it2);
        ++it1;
        ++it1;
        CHECK_FALSE(*it1 > *it2);
        CHECK(*it1 != *it2);

    }
}

TEST_CASE("PrimeIterator") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);
    container.addElement(7);


    SUBCASE("Iterating elements && operator ==") {
        MagicalContainer::PrimeIterator it(container);
        CHECK(*it == 2);
        ++it;
        CHECK(*it == 3);
        ++it;
        CHECK(*it == 5);
        ++it;
        CHECK(*it == 7);
        ++it;
        CHECK(it == it.end());
    }

    SUBCASE("Comparation"){
        MagicalContainer::AscendingIterator it1(container);
        MagicalContainer::AscendingIterator it2(container);

        ++it2;
        CHECK(*it1 < *it2);
        ++it1;
        ++it1;
        CHECK(*it1 > *it2);
        CHECK(*it1 != *it2);
    }
}
