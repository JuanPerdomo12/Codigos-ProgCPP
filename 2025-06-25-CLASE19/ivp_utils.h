#pragma once

#include <iostream>
#include <valarray>
#include <functional>


// function template to work with "any" type
template <class deriv_t, class system_t, class printer_t>
void integrate_euler(deriv_t fderiv, system_t & s, double tinit, double tend, double dt, printer_t writer)
{
    // vector to store derivs
    system_t dsdt(s.size());

    // time loop
    for(double t = tinit; t <= tend; t += dt) { // NOTE: Last time step not necessarily tf
        // compute derivs
        fderiv(s, dsdt, t);

        // compute new state. NOTE: Not using components, assuming valarray or similar
        s = s + dt*dsdt; // Euler

        // write new state
        writer(s, t);
      }
}

template <class deriv_t, class system_t, class printer_t>
void integrate_heun(deriv_t fderiv, system_t & s, double tinit, double tend, double dt, printer_t writer)
{
    // vector to store derivs

    system_t k1(s.size());
    system_t k2(s.size());
    system_t y1(s.size());

    // time loop
    for(double t = tinit; t <= tend; t += dt) { // NOTE: Last time step not necessarily tf
        // compute derivs
        fderiv(s, k1, t);
        y1=s + dt*k1;
        fderiv(y1, k2 , t + dt);

        // compute new state. NOTE: Not using components, assuming valarray or similar
        s = s + (dt/2.0)*(k1+k2); // Heun

        // write new state
        writer(s, t);
      }
}