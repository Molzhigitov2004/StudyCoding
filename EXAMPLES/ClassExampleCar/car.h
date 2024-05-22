#ifndef CAR_H_
#define CAR_H_
#include <string>
class car {
    // ((speed > 0.0)) Implies engine_on)
    // AND (0.0 < speed < max_speed)
    bool engine_on;
    double speed;
    const double max_speed;
    const std::string vin;


public: 
/*
1) Precondition: max_spd > 0.0
2) Postcondition: (speed = 0.0)
                AND NOT (engine_on)
                AND NOT (max_speed = max_spd)
                AND NOT (vin = veh_id_num)
3) Exceptional
    Condition: THROW invalis_argument IF max_spd > 0.0  
*/
car(double max_spd, std::string veh_id_num);
/*
Postcondition: engine_on 
                AND PRESERVE(mean doesnt change) (speed)
                AND (RESULT = NOT(OLD(means value before calling function(engine_on)))
*/

bool turn_on();

void press_brake();

void press_gas_pedal (double pressure);

bool turn_off();

double get_speed()const;

bool is_engine_on() const;

double get_max_speed() const;

std::string get_vin() const;

~car(){ }

};

#endif