#include <memory>
#include <iostream>
#include <string>
#include "Network_Types.h"

using std::cout, std::endl;

Node::Node(const std::string &n) : id(next_id++) {}

Node::~Node()
{
    cout << "Node " << id << " destroyed." << endl;
}

int Node::getId() const
{
    return id;
}

// Static variables need to be initialised outside their class declaration
// This is because they are only initialised ONCE, not individually for every object.
int Node::next_id = 0;

Hub::Hub(const std::string &n) : name(n) {}

Hub::~Hub()
{
    cout << "Hub " << name << " destroyed." << endl;
}