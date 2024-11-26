#pragma once
#include "user.h"
#include <string>

class DoctorUser : public User
{
    std::string _name;

  public:
    DoctorUser(const std::string &name);
    std::function<bool(const MyObject &)> getFilter() const override;
};
