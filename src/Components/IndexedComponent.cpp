#include "Components/IndexedComponent.hpp"

const int &IndexedComponent::getIndex() const
{
    return index;
}

void IndexedComponent::setIndex(const int &idx)
{
    index = idx;
}