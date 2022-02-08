#pragma once

#ifndef ISubscriber_H
#define ISubscriber_H

#include "../AllFactories/AsteroidFactory.h"

namespace Interfaces {

class ISubscriber {
 public:
    virtual void subscribe(Factories::AsteroidFactory newFactory);
    virtual void notify();

 private:
    Factories::AsteroidFactory factory;
};

}  // namespace Interfaces

#endif
