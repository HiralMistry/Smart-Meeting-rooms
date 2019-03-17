#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <iostream>
#include <chrono>
#include "elma.h"


namespace elma {

   

    class Temperature : public Process {

        public: 
            Temperature() : Process(), temp_status(NULL) , desired_temp(30), _smart_room(NULL)  {}

            Temperature(string name) : Process(name), temp_status(NULL) , desired_temp(30), _smart_room(NULL) {}

            virtual ~Temperature() = default;

            void init();

            void start(){}

            void update();

            void stop(){}
            
            inline bool give_temp_status() { return temp_status;}
            inline double give_desired_temp(){return desired_temp;}
            inline void set_temp_status(bool value) { temp_status = value; }
            
            bool temp_status;   // false if heater is on, true if AC is on & NULL if nothing is on.

            double desired_temp;
            SmartRoom * _smart_room;
    };

}

#endif