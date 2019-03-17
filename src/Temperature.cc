#include <iostream>
#include <chrono>
#include "elma.h"

namespace elma {

    void Temperature::init() {
        watch("Temperature Change",[this](Event& e) {
            desired_temp = e.value();
        });

    }

    void Temperature::update() {
        std::cout<<"Temperature update\n";
        if ( _smart_room->current().name() == "_occupied" ) {
            if (channel("temp").nonempty() ) {
                double value = channel("temp").latest();
                if (value < desired_temp) {
                    if ( temp_status == true) {
                        emit(Event("turn Off AC"));
                        emit(Event("turn On Heater"));
                        temp_status = false;
                    }
                }
                else
                {
                    if ( temp_status == false ) {  
                        emit(Event("turn Off Heater"));
                        emit(Event("turn on AC"));
                        temp_status = true;
                    }
                }            
            }
        }
        std::cout<<"Temperature update success\n";
    }
    
}