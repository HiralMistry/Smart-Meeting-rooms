#include <iostream>
#include <chrono>
#include "elma.h"

namespace elma {
    
    void Light::update() {
        std::cout<<"Light update\n";
        if (channel("light").nonempty() ) {
            double value = channel("light").latest();
            if (value < desired_lux) {
                if ( light_status == false) {
                    emit(Event("turn On lights"));
                    light_status = true;
                }
            }
            else
            {
                if ( light_status == true ) {  
                    emit(Event("turn Off light"));
                    light_status = false;
                }
            }            
        } 
        std::cout<<"Light update success\n";
    }

}