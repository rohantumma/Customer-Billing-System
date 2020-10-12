#include "goods.h"

goods::goods()
{
    //ctor
}

goods::~goods()
{
    //dtor
}

goods::goods(const goods& other)
{
    //copy ctor
}

goods& goods::operator=(const goods& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
