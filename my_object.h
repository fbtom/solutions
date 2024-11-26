#pragma once

#include "timeslot.h"
#include <memory>
#include <string>
#include <vector>

class MyObject
{
  public:
    Timeslot _timeslot;
    uint8_t _room;
    std::string _doc_name;

    MyObject(const Timeslot &timeslot, uint8_t room,
             const std::string &doc_name);

    void showDateAndTime() const;
};

class ObjCollection
{
  public:
    std::vector<std::unique_ptr<MyObject>> _objects;

    ObjCollection();

    const std::vector<std::unique_ptr<MyObject>> &getObjects() const;

    void setObj(std::unique_ptr<MyObject> obj);
};

std::unique_ptr<MyObject> createMyObject(const Timeslot &timeslot,
                                         const std::string &doc_name,
                                         uint8_t room);
