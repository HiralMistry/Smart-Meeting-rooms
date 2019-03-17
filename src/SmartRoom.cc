#include <iostream>
#include <chrono>
#include "gtest/gtest.h"
#include "elma.h"
// #include "SmartRoom.h"

using namespace std::chrono;
// using namespace elma;

namespace elma {

    void SmartRoom::init() {
        watch("Motion Detected", [this] (Event& e){
            _room_status = true;
        });
        watch("No Motion Detected",[this](Event& e){
            _room_status = false;
            //set_temp_status(NULL);
        });
    }

    void SmartRoom::start(){
        _room_status = false;
    }

    void SmartRoom::update() {
        if ( channel("motion").latest() == 1 ) {
            if(_room_status == false) {
                emit(Event("Motion Detected"));
                count_motion = 0;
            }
        }
        else {
            if (_room_status == true) {
                count_motion ++;
                if ( count_motion == max_limit ) {
                    emit(Event("No Motion Detected"));
                }
            }
        }
            
    }

    inline bool SmartRoom::_give_room_status() { return _room_status;}


}