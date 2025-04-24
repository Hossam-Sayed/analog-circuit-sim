#pragma once
#include "Components/Component.hpp"

class IndexedComponent : public virtual Component
{
public:
    int getIndex() const;
    void setIndex(int idx);

protected:
    int index = -1;
};