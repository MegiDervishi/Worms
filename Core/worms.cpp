#include "worms.hpp"

bool Worm::isAlive() const{
  return health > 0; 
}

void Worm::move(bool right){
}

void Worm::weaponSelect(int weapon_ID) {
    this->current_weapon = weapon_ID;
}

void Worm::fireWeapon(double power, std::vector* projectile_list) {
    current_projectile = weapons[weapon_ID]
    current_projectile.set_inital_position(double this->x, double this->y); //might need to offset initial position to avoid worm shooting himself 
    current_projectile.addForce(QPair<double, double> )
    projectile_list->push_back(current_weapon);


}

void Worm::move(){           // Takes care of all movements of the worms based on the keyboard inputs. NOT TESTED 
  
  // MOVE TO THE RIGHT
  if(int QKeyEvent::key() const == 0x44){           //If the input key is the right arrow which has code 0x01000014, then give force to the right to the rigid body.
    worms.addForce(QPair<double, double>(5, 0));
    if(bool QKeyEvent::isAutoRepeat() const == true && int QKeyEvent::key() const == 0x44){      // If the user stays on the right arrow, repeatedly give 5 speed to the right.
      worms.addForce(QPair<double, double>(5, 0));                                             // The way int QKeyEvent::key() const and bool QKeyEvent::isAutoRepeat() const work are explained in the text under.
      }
  }
  
  // MOVE TO THE LEFT
  if (int QKeyEvent::key() const == 0x41){ // To move to the left just take out 5 velocity.
    worms.addForce(QPair<double, double>(-5, 0));
    }
    if((bool QKeyEvent::isAutoRepeat() const == true && int QKeyEvent::key() const == 0x41){
      worms.addForce(QPair<double, double>(-5, 0));
      }
   
  // JUMP
  if (int QKeyEvent::key() const == 0x57){ // To move jump give a negative force to the y-axis (recall 
    worms.addForce(QPair<double, double>(0, -5));
    }
    if((bool QKeyEvent::isAutoRepeat() const == true && int QKeyEvent::key() const == 0x57){
      vy0 += 5;
      }
}

-----------------------------------------------------------------------------------------------
// Is it here that we should link the keys of the keyboards to the features ew want to implement?
                                            // Hence set the right arrow to add say 5 velocity to the right.
                                            // Here are some ascii codes: 37(left arrow)
                                            //                            38(up arrow)
                                            //                            39(right arrow)
                                            //                            40(down arrow)
// Problem: How to make it smooth? If we use the switch method, we should add the break; instruction after each successful 
// checking. Will it break the entire process? Is it fine like this?
  
// This is also something that I found as an example of how to handle key inputs. Remark that the ascii is here not the same.
// We will have to see how it works depending on the keyboard.
  
// Remark the function getch()
  
/*
https://stackoverflow.com/questions/24708700/c-detect-when-user-presses-arrow-key
CODE:


#include <conio.h>
#include <iostream>
using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

int main()
{
    int c = 0;
    while(1)
    {
        c = 0;

        switch((c=getch())) {
        case KEY_UP:
            cout << endl << "Up" << endl;//key up
            break;
        case KEY_DOWN:
            cout << endl << "Down" << endl;   // key down
            break;
        case KEY_LEFT:
            cout << endl << "Left" << endl;  // key left
            break;
        case KEY_RIGHT:
            cout << endl << "Right" << endl;  // key right
            break;
        default:
            cout << endl << "null" << endl;  // not arrow
            break;
        }

    }

    return 0;
}

RESULT IN THE CONSOLE AFTER SOME TESTS:
Up

Down

Right

Left

Up

Left

Right

Right

Up
*/
-----------------------------------------------------------------------------------------------
  
void worms::jump(){ // Should be the same as for the move.
  
}
  

  
  
