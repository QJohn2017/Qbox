#ifndef GUARD_box_monitor_h
#define GUARD_box_monitor_h

#include <string>
#include <memory>
#include "monitor.h"
#include "surface_monitor.h"

namespace qbox {

    class Field2D;

    //*** There is memory redunancy here....is it worth it for using a templated add_monitor function instead???
    //box monitor: monitors all points inside 4 surface monitors
    class box_monitor: public monitor {
    public:
        //various constructors
        box_monitor(std::string name, const volume &vol, const freq_data &freq, bool extendable=false);
        box_monitor(const volume &vol, const freq_data &freq, bool extendable=false);

        //same as surface_monitor 
        void set_F(Field2D *newF);
        void update();
        Array compute_flux() const override;

        ComplexArray ntff(const vec &p) const;
        ComplexTensor ntff_sphere(double radius, int N) const;

        void write_flux_sides();  //call write for all surface_monitors
        void write_ntff_sphere(double radius, int N) const;

        void operator-=(const box_monitor& other) {
            for (int i = 0; i != 4; i++)
                monitors[i] -= other.monitors[i];
        }
    private:
        surface_monitor monitors[4];    //4 surface monitors
        volume vol;
    };
}

#endif
