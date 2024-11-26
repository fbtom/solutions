cmake_minimum_required(VERSION 3.12)

project(CalendarProject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(main main.cpp timeslot.cpp my_object.cpp calendar.cpp doctor_user.cpp admin_user.cpp)