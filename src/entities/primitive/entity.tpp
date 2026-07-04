#include "entity.hpp"

template<typename ID>
Entity<ID>::Entity(ID id) {
    this->id = id;
}

template<typename ID>
ID Entity<ID>::getID() const{
    return id;
}