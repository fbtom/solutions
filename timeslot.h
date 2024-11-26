#pragma once

#include <chrono>

using namespace std;

struct DateAndTime
{
    chrono::year_month_day date;
    chrono::hours hours;
    chrono::minutes minutes;
};

class Timeslot
{
  public:
    Timeslot();
    Timeslot(const chrono::time_point<chrono::system_clock> &start,
             const chrono::minutes &duration);

    chrono::year_month_day getDate() const;
    pair<chrono::hours, chrono::minutes> getStart() const;
    chrono::minutes getDuration() const;
    void setTime(const chrono::year_month_day &date, const chrono::hours &hours,
                 const chrono::minutes &minutes,
                 const chrono::minutes &duration);

    bool operator<(const Timeslot &other) const;

  private:
    chrono::time_point<chrono::system_clock> _start;
    chrono::minutes _duration;

    chrono::time_point<chrono::system_clock> initCurrentlyClosestTimeslot()
        const;
};
