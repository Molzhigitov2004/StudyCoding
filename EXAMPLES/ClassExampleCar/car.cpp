#include "car.h"
#include <stdexcept>


    car::car(double max_spd, std::string veh_id_num) :
    engine_on (false),
    speed(0.0),
    max_speed(max_spd),
    vin(veh_id_num)
    {
        if(max_spd <= 0.0){
            throw std::invalid_argument(" Max speed must be initialized to a positive number");
        }
    }



bool car::turn_off()
{
    if(!engine_on)
    return false;

    if(speed > 0){
        throw std::invalid_argument("Cannot turn off engine while car is moving!!!");
    }

    engine_on = false;
    return true;
}

bool car::turn_on()
{
    if(engine_on)
    return false;

    engine_on = true;
    return true;
}

void car::press_brake(){
    speed = 0;
}

void car::press_gas_pedal (double pressure){
    if(pressure < 0.0)
        throw std::invalid_argument("Cannot have negative pedal pressure!");

    if(engine_on) {
        unsigned int new_speed = speed + pressure;
        if(new_speed > max_speed) {
        speed = max_speed;        
        } else {
            speed = new_speed;
        }
    }
}

double car::get_speed() const {
    return speed;
}

bool car::is_engine_on() const {
    return  engine_on;
}

double car::get_max_speed() const {
    return max_speed;
}

std::string car::get_vin() const {
    return vin;
}

car::~car(){ }