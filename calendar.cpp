#include "calendar.h"

Calendar::Calendar(ObjCollection &collection,
                   std::function<bool(const MyObject &)> filter)
    : _collection{collection}, _filter{filter}
{
}

void Calendar::display() const
{
    for (const auto &obj : _collection.getObjects())
    {
        if (_filter(*obj))
        {
            obj->showDateAndTime();
        }
    }
}
