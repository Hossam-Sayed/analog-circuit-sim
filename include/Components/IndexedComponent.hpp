#pragma once
#include "Components/Component.hpp"

class IndexedComponent : public virtual Component
{
public:
    const int &getIndex() const;
    void setIndex(const int &idx);

protected:
    int index = -1;
};