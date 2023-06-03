#include "doctest.h"
#include "sources/MagicalContainer.hpp"
#include <stdexcept>

using namespace ariel;
TEST_SUITE_BEGIN("Classes tests") ;
TEST_CASE("Container Class tests"){
    MagicalContainer container ;
    CHECK(container.size() == 0) ;
    container.addElement(6) ;
    container.addElement(8) ;
    CHECK(container.size() == 2) ;
    container.removeElement(6) ;
    CHECK(container.size() == 1) ;

    //-----Removing non exist element-----
    CHECK_THROWS_AS(container.removeElement(1), std::runtime_error) ;
}

TEST_CASE("AscendingIterator class tests"){
    MagicalContainer container ;
    container.addElement(1) ;
    container.addElement(2) ;
    container.addElement(3) ;

    MagicalContainer::AscendingIterator iter(container) ;
    int i = 1 ;
    for(iter = iter.begin() ; iter != iter.end() ; ++iter){
        CHECK(*iter == i) ;
        if(i == 2){
            container.addElement(4) ;
        }
        i++ ;
    }
    CHECK(i == 5) ;

    MagicalContainer::AscendingIterator iter1(container) ;
    MagicalContainer::AscendingIterator iter2(container) ;
    CHECK(iter1 == iter2) ;
    CHECK_FALSE(iter1 != iter2) ;
    CHECK_FALSE(iter1 < iter2) ;
    CHECK_FALSE(iter1 > iter2) ;

    ++iter1 ;
    CHECK_FALSE(iter1 == iter2) ;
    CHECK(iter1 != iter2) ;
    CHECK(iter1 > iter2) ;
    CHECK_FALSE(iter1 < iter2) ;

    MagicalContainer::AscendingIterator iter3(iter1) ;
    CHECK(iter1 == iter3) ;
}

TEST_CASE("PrimeIterator class tests"){
    MagicalContainer container ;
    container.addElement(1) ;
    container.addElement(2) ;
    container.addElement(4) ;
    container.addElement(6) ;
    container.addElement(7) ;

    MagicalContainer::PrimeIterator iter(container) ;
    CHECK(*iter == 2) ;
    ++iter ;
    CHECK(*iter == 7) ;
    CHECK_THROWS_AS(++iter, std::runtime_error) ;

    MagicalContainer::PrimeIterator iter1(container) ;
    MagicalContainer::PrimeIterator iter2(container) ;
    CHECK(iter1 == iter2) ;
    CHECK_FALSE(iter1 != iter2) ;
    CHECK_FALSE(iter1 < iter2) ;
    CHECK_FALSE(iter1 > iter2) ;

    ++iter1 ;
    CHECK_FALSE(iter1 == iter2) ;
    CHECK(iter1 != iter2) ;
    CHECK(iter1 > iter2) ;
    CHECK_FALSE(iter1 < iter2) ;

    MagicalContainer::PrimeIterator iter3(iter1) ;
    CHECK(iter1 == iter3) ;
}

TEST_CASE("SideCrossIterator class tests"){
    MagicalContainer container ;
    container.addElement(1) ;
    container.addElement(2) ;
    container.addElement(4) ;
    container.addElement(6) ;
    container.addElement(7) ;
    MagicalContainer::SideCrossIterator iter(container) ;

    CHECK(*iter == 1) ;
    CHECK(*(++iter) == 7) ;
    CHECK(*(++iter) == 2) ;
    CHECK(*(++iter) == 6) ;
    CHECK(*(++iter) == 4) ;
    CHECK_THROWS_AS(++iter, std::runtime_error) ;

    MagicalContainer::SideCrossIterator iter1(container) ;
    MagicalContainer::SideCrossIterator iter2(container) ;
    CHECK(iter1 == iter2) ;
    CHECK_FALSE(iter1 != iter2) ;
    CHECK_FALSE(iter1 < iter2) ;
    CHECK_FALSE(iter1 > iter2) ;

    ++iter1 ;
    CHECK_FALSE(iter1 == iter2) ;
    CHECK(iter1 != iter2) ;
    CHECK(iter1 > iter2) ;
    CHECK_FALSE(iter1 < iter2) ;

    MagicalContainer::SideCrossIterator iter3(iter1) ;
    CHECK(iter1 == iter3) ;
}