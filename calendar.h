#pragma once
#include "my_object.h"
#include <functional>

class Calendar
{
  public:
    Calendar(ObjCollection &collection,
             std::function<bool(const MyObject &)> filter);

    void display() const;

  private:
    const ObjCollection &_collection;
    std::function<bool(const MyObject &)> _filter;
};
