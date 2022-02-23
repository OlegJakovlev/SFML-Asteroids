#pragma once

#ifndef ISubscriber_H
#define ISubscriber_H

#include "../AllFactories/AsteroidFactory.h"

namespace Interfaces {

class ISubscriber {
 public:
    void subscribe(Factories::AsteroidFactory* newFactory);
    virtual void notify();

 protected:
     Factories::AsteroidFactory* factory;
};

}  // namespace Interfaces

#endif
