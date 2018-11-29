#pragma once
#include <QPair>
#include "Collider.h"
#include <QDebug>



class RigidBody:public Collider{
private:
    //Parameters of Rigid Body.
    double mass = 0, vx = 0, vy = 0, ax = 0, ay = 0;
    
    // The current force is the total current force applied on the body which is a pair (Fx,Fy).
    QPair<double, double> currentForce = QPair<double, double>(0, 0);
    
    //Bounciness determines the decrease in velocity after hitting another body. It looses no velocity when bounciness=1.
    double bounciness_f = 0;
    
    // A body is considered stable when its velocity is close to zero AND the total force applied on it are close to zero.
    bool stable = false; //When the body is stable we set stable to true.
    
public:
    //Constructors
    RigidBody(double imass, double ix, double iy, double vx0, double vy0, double ax0, double ay0, int iid, QImage map);
    RigidBody(double imass, double ix, double iy);
    
    //Physics methods:
    
    void bounce(QPair<double, double> normal, double dt); //

    void addForce(QPair<double, double> F);
    double distance(RigidBody other);
    void simulate(double dt);
    
    //Set methods.
    void setbounciness(double b);
    void setm(double m);
    void setvx(double v_x);
    void setvy(double v_y);
    void setax(double a_x);
    void setay(double a_y);
    void setstable(bool a);
    
    //Get methods.
    bool getstable();
    double getbounciness();
    double getm();
    double getvx();
    double getvy();
    double getax();
    double getay();
    
};
