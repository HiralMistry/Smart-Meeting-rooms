#ifndef LIGHT_H
#define LIGHT_H

#include <iostream>
#include <chrono>
#include "gtest/gtest.h"
#include "elma.h"

namespace elma {

    using namespace std::chrono;
    using namespace elma;

    class SmartRoom;


    class Light : public Process {
        public:

        Light() : Process(), desired_lux(500), light_status(false), _smart_room(NULL) {}

        Light(string name) : Process(name), desired_lux(500), light_status(false), _smart_room(NULL) {}

        virtual ~Light() = default;

        void init() {}
        void start() {}

        void  update();

        inline bool give_light_status(){ return light_status;}
        inline double give_desired_lux() {return desired_lux;}

        void stop() {}
        
        bool light_status;  
        double desired_lux;
        SmartRoom * _smart_room;
    };
}
#endif