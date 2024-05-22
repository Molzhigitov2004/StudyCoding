#include <iostream>
#include "car.h"
using namespace std;

void output_state(car mcar){
    std::cout << "Car: " << mcar.get_vin()
              << ( mcar.is_engine_on()? "engine is running" : " engine is off\n")
              << "speed: " << mcar.get_speed() <<"\n";
}

int main()
{
    car my_car(170.0, "1AABD34JXNM345678");
    output_state(my_car);

    my_car.turn_on();
    output_state(my_car);
    
    for(unsigned int i = 0; i < 10; i++){
        std::cout << "pressing the gas pedal...\n";
        my_car.press_gas_pedal(25.0);
        output_state(my_car);
    }
    my_car.press_brake();
    output_state(my_car);
    try {
        my_car.turn_off();
        output_state(my_car);
    } catch (std::exception &ex) {
        std::cout << "oops! " << ex.what() << "\n";
    }

    return 0;
}

