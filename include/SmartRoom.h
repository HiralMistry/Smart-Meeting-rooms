#ifndef SMARTROOM_H
#define SMARTROOM_H

#include <iostream>
#include <chrono>
#include "elma.h"

namespace elma {

    class Temperature;
    class Light;

    
    class RoomState : public State {
        public:
            RoomState(string name) : State(name) {}
            virtual void entry(const Event& e) {}
            virtual void during() {} 
            virtual void exit(const Event& e) {} 
    };

    class SmartRoom : public StateMachine {
    public:
        // friend class Light;
        // friend class Temperature;
        
        SmartRoom() : StateMachine(), _room_status(NULL), max_limit(1200){
            set_initial(_idle);
            add_transition("start",_idle,_not_occupied);
            add_transition("Motion Detected", _not_occupied , _occupied );
            add_transition("No Motion Detected", _occupied, _not_occupied);
            _light._smart_room = this;
            _temp._smart_room = this;
        }

        SmartRoom(string name) : StateMachine(name), _room_status(NULL), 
                        max_limit(1200) {
            set_initial(_idle);
            add_transition("start",_idle,_not_occupied);
            add_transition("Motion Detected", _not_occupied , _occupied );
            add_transition("No Motion Detected", _occupied, _not_occupied);
            _light._smart_room = this;
            _temp._smart_room = this;
        }
        void init();
        void start();
        void update();
        void stop(){}

        inline bool _give_room_status();
        

    //private:
        bool _room_status; // false if room is not occupied
        int count_motion; // counts the number of 'no motion' events 
        int max_limit; // time period after which room will turn off everything if no motion is there.
        RoomState _occupied = RoomState("Occupied");
        RoomState _not_occupied = RoomState("Not Ocuupied");
        RoomState _idle = RoomState("Idle");
        Light _light;
        Temperature _temp;
    };
}

#endif