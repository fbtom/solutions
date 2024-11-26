#include "admin_user.h"

std::function<bool(const MyObject &)> AdminUser::getFilter() const
{
    return [this](const MyObject &obj) { return true; };
}
