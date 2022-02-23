#include "ISubscriber.h"

namespace Interfaces {

void ISubscriber::subscribe(Factories::AsteroidFactory* newFactory) {
    factory = newFactory;
}

void ISubscriber::notify() {
}

}
