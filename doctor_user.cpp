#include "doctor_user.h"

DoctorUser::DoctorUser(const std::string &name) : _name{name}
{
}

std::function<bool(const MyObject &)> DoctorUser::getFilter() const
{
    return [this](const MyObject &obj) { return obj._doc_name == _name; };
}
