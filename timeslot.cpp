#include "timeslot.h"

Timeslot::Timeslot() : _start{initCurrentlyClosestTimeslot()}, _duration{10}
{
}

Timeslot::Timeslot(const chrono::time_point<chrono::system_clock> &start,
                   const chrono::minutes &duration)
    : _start{start}, _duration{duration + chrono::minutes{10}}
{
}

chrono::year_month_day Timeslot::getDate() const
{
    return chrono::year_month_day{chrono::floor<chrono::days>(_start)};
}

pair<chrono::hours, chrono::minutes> Timeslot::getStart() const
{
    auto time_since_epoch = _start.time_since_epoch();
    auto hours = chrono::duration_cast<chrono::hours>(time_since_epoch %
                                                      chrono::days(1));
    auto minutes = chrono::duration_cast<chrono::minutes>(time_since_epoch %
                                                          chrono::hours(1));
    return {hours, minutes};
}

chrono::minutes Timeslot::getDuration() const
{
    return _duration;
}

void Timeslot::setTime(const chrono::year_month_day &date,
                       const chrono::hours &hours,
                       const chrono::minutes &minutes,
                       const chrono::minutes &duration)
{
    _start = {chrono::sys_days{date} + hours + minutes};
    _duration = duration + chrono::minutes{10};
}

chrono::time_point<chrono::system_clock> Timeslot::
    initCurrentlyClosestTimeslot() const
{
    const auto now = chrono::system_clock::now();
    auto now_minutes = chrono::ceil<chrono::minutes>(now);
    const auto minutes =
        chrono::duration_cast<chrono::minutes>(now_minutes.time_since_epoch()) %
        chrono::hours(1);
    auto rounded_minutes = chrono::minutes((minutes.count() + 9) / 10 * 10);
    if (rounded_minutes == chrono::minutes{60})
    {
        now_minutes += chrono::hours{1};
        rounded_minutes = chrono::minutes{0};
    }
    return now_minutes - minutes + rounded_minutes;
}

bool Timeslot::operator<(const Timeslot &other) const
{
    return _start < other._start;
}