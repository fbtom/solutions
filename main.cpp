#include "admin_user.h"
#include "calendar.h"
#include "doctor_user.h"
#include "my_object.h"
#include "timeslot.h"
#include <algorithm>
#include <array>
#include <chrono>
#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

bool isDurationValid(const chrono::minutes &duration)
{
    if (duration.count() % 10 != 0 || duration.count() < 10 ||
        duration.count() > 450)
    {
        return false;
    }
    return true;
}

Timeslot createTimeSlot(const DateAndTime &dateTime, chrono::minutes duration)
{
    if (not isDurationValid(duration))
    {
        duration = chrono::minutes{10};
    }

    return Timeslot{chrono::sys_days(dateTime.date) + dateTime.hours +
                        dateTime.minutes,
                    duration};
}

int main()
{
    DateAndTime dt{chrono::year{2021} / chrono::month{1} / chrono::day{1},
                   chrono::hours{10}, chrono::minutes{30}};
    chrono::minutes duration{20};

    ObjCollection collection{};
    collection.setObj(createMyObject(createTimeSlot(dt, duration), "Adam", 1));
    dt.hours = chrono::hours{11};
    collection.setObj(createMyObject(createTimeSlot(dt, duration), "Adam", 2));
    dt.hours = chrono::hours{13};
    duration = chrono::minutes{70};
    collection.setObj(createMyObject(createTimeSlot(dt, duration), "Pawel", 1));
    dt.date = chrono::year{2020} / chrono::month{12} / chrono::day{31};
    collection.setObj(createMyObject(createTimeSlot(dt, duration), "Jude", 2));
    dt.date = chrono::year{2022} / chrono::month{1} / chrono::day{1};
    collection.setObj(createMyObject(createTimeSlot(dt, duration), "Adam", 1));

    std::unique_ptr<User> user = make_unique<DoctorUser>("Adam");
    Calendar calendar{collection, user->getFilter()};

    calendar.display();
    std::cout << std::endl;
    dt.date = chrono::year{2025} / chrono::month{1} / chrono::day{1};
    collection.setObj(createMyObject(createTimeSlot(dt, duration), "Adam", 1));

    calendar.display();

    std::cout << std::endl;

    std::unique_ptr<User> admin = make_unique<AdminUser>();
    Calendar calendar2{collection, admin->getFilter()};

    calendar2.display();
    return 0;
}
