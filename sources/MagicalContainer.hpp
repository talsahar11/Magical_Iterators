//
// Created by ts on 5/28/23.
//
#ifndef MAGICAL_ITERATORS_MAGICALCONTAINER_H
#define MAGICAL_ITERATORS_MAGICALCONTAINER_H
#include <list>
#include <limits>
#include <stdexcept>
#include <iostream>

using namespace std ;
namespace ariel {
    class MagicalContainer {
    private:
        list<int> elementsList ;
        list<int*> primesList ;
    public:
        class AscendingIterator {
        private:
            AscendingIterator(list<int>* elementsList, list<int>::iterator iter, int location)
                    :elementsList(elementsList),
                     iter(iter),
                     location(location){}
            list<int>* elementsList;
            list<int>::iterator iter ;
            int location ;
        public:
            AscendingIterator(MagicalContainer& container)
                    :elementsList(&container.elementsList),
                     iter((&container.elementsList)->begin()),
                     location(0) {}
            AscendingIterator(const AscendingIterator& other)
            : elementsList(other.elementsList),
            iter(other.iter),
            location(other.location){}
            AscendingIterator(AscendingIterator&& other) noexcept = default;
            AscendingIterator& operator=(AscendingIterator&& other) noexcept = default;
            ~AscendingIterator() {}

            AscendingIterator begin() const {return *this ;}
            AscendingIterator end() const {return *this ;}
            AscendingIterator& operator=(const AscendingIterator& other) {
                *this = AscendingIterator (other);
                return *this;
            }

            bool operator==(const AscendingIterator& iter) const {return true ;}
            bool operator!=(const AscendingIterator& iter) const { return false ;}
            bool operator<(const AscendingIterator& iter) const {return true ;}

            bool operator>(const AscendingIterator& iter) const {return true ;}
            AscendingIterator& operator++() {return *this ;}
            int operator*() {return 0 ;}
        };

        class PrimeIterator {
        private:
            PrimeIterator(list<int*>* primesList, list<int*>::iterator iter, int location = 0)
                    :primesList(primesList),
                     iter(iter),
                     location(location)  {}
            list<int*> *primesList;
            list<int*>::iterator iter;
            int location ;

        public:
            PrimeIterator(MagicalContainer& container)
                    :primesList(&container.primesList),
                     iter((&container.primesList)->begin()),
                     location(0)   {}
            PrimeIterator(const PrimeIterator &other) {
                this->primesList = other.primesList ;
                this->location = other.location ;
                this->iter = other.iter ;
            }
            PrimeIterator(PrimeIterator&& other) noexcept = default;
            PrimeIterator& operator=(PrimeIterator&& other) noexcept = default;
            ~PrimeIterator() {}

            PrimeIterator begin() const{ return *this ;}

            PrimeIterator end() const{ return *this ;}
            PrimeIterator& operator=(const PrimeIterator& other){
                *this = PrimeIterator (other);
                return *this;
            }
            bool operator==(const PrimeIterator& iter) const{ return false ;}

            bool operator!=(const PrimeIterator& iter) const{ return false ;}

            bool operator<(const PrimeIterator& iter) const { return true ;}

            bool operator>(const PrimeIterator& iter) const {return true ;}

            PrimeIterator &operator++() {return *this ;}

            int operator*() {return 0 ;}
        };

        class SideCrossIterator {
            SideCrossIterator(list<int>* elementsList, list<int>::iterator startIter, list<int>::iterator endIter, int location)
                    : elementsList(elementsList),
                      startIter(startIter),
                      endIter(endIter),
                      isForward(true),
                      location(location)    {}
            list<int> *elementsList;
            list<int>::iterator startIter, endIter;
            bool isForward ;
            int location ;

        public:
            SideCrossIterator(MagicalContainer& container)
                    : elementsList(&container.elementsList),
                      startIter((&container.elementsList)->begin()),
                      endIter(--(&container.elementsList)->end()),
                      isForward(true)
                    ,location(0){}
            SideCrossIterator(const SideCrossIterator &other) {
                this->elementsList = other.elementsList;
                this->startIter = other.startIter ;
                this->endIter = other.endIter ;
                this->location = other.location ;
                this->isForward = other.isForward ;
            }
            SideCrossIterator(SideCrossIterator&& other) noexcept = default;
            SideCrossIterator& operator=(SideCrossIterator&& other) noexcept = default;
            ~SideCrossIterator() {}

            SideCrossIterator begin() const {return *this ;}

            SideCrossIterator end() const {return *this ;}
            SideCrossIterator& operator=(const SideCrossIterator& other){
                *this = SideCrossIterator (other);
                return *this;
            }

            bool operator==(const SideCrossIterator& iter) const {return false ;}

            bool operator!=(const SideCrossIterator& iter) const {return false ;}

            bool operator<(const SideCrossIterator& iter) const {return true ;}
            bool operator>(const SideCrossIterator& iter) const {return true ;}

            SideCrossIterator &operator++() {return *this ;}

            int operator*() {return 0 ;}
        };

        MagicalContainer() {}
        void addElement(int element){}

        void removeElement(int element){}

        int size(){return elementsList.size() ;}
        list<int> getList(){
            return elementsList ;
        }
        list<int*> getPrimesList(){
            return primesList ;
        }
    };
}
#endif //MAGICAL_ITERATORS_MAGICALCONTAINER_H
