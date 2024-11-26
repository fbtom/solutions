#pragma once
#include "user.h"

class AdminUser : public User
{
  public:
    std::function<bool(const MyObject &)> getFilter() const override;
};
