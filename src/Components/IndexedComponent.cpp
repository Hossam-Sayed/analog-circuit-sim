#include "Components/IndexedComponent.hpp"

int IndexedComponent::getIndex() const
{
    return index;
}

void IndexedComponent::setIndex(int idx)
{
    index = idx;
}