#pragma once
#include "my_object.h"
#include <functional>

class User
{
  public:
    virtual std::function<bool(const MyObject &)> getFilter() const = 0;
    virtual ~User() = default;
};
