#include "my_object.h"
#include <iostream>

MyObject::MyObject(const Timeslot &timeslot, uint8_t room,
                   const std::string &doc_name)
    : _timeslot{timeslot}, _room{room}, _doc_name{doc_name}
{
}

void MyObject::showDateAndTime() const
{
    const auto date = _timeslot.getDate();
    const auto start = _timeslot.getStart();
    std::cout << date.year() << "-" << date.month() << "-" << date.day() << " "
              << start.first.count() << ":" << start.second.count()
              << std::endl;
}

ObjCollection::ObjCollection() : _objects{}
{
}

const std::vector<std::unique_ptr<MyObject>> &ObjCollection::getObjects() const
{
    return _objects;
}

void ObjCollection::setObj(std::unique_ptr<MyObject> obj)
{
    _objects.emplace_back(std::move(obj));
}

std::unique_ptr<MyObject> createMyObject(const Timeslot &timeslot,
                                         const std::string &doc_name,
                                         uint8_t room)
{
    return std::make_unique<MyObject>(timeslot, room, doc_name);
}
