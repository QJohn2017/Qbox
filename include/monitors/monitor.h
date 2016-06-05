#ifndef GUARD_monitor_h
#define GUARD_monitor_h

#include <vector>
#include <string>
#include <memory>
#include "../matrix.h"
#include "freq.h"


namespace apine {

    class Field2D;

    //*** technically, these are DFT monitors. Normal monitor can exist too.

    //monitor base class
    class monitor {
    public:
        monitor(std::string name, std::shared_ptr<freq_data> freq, int N): name(name), freq(freq), N(N) {};
        virtual void set_freq(std::shared_ptr<freq_data> new_freq); //set the frequencies
        //*** should probably be private:
        virtual void set_F(Field2D *newF);       //set the owning field
        virtual void update() {};                //update the DFT values

        monitor() = default;
        monitor(const monitor&) = default;
        monitor(monitor&&) = default;
        monitor& operator=(monitor&&) = default;
    public:
        std::string name;    //Monitor name; to call output from main
        int N;    //Number of points in the monitor
        std::shared_ptr<freq_data> freq;    //set of frequencies to DFT at
        std::unique_ptr<double[]> prevE;   //previous E at all all points in the monitor; needed to interpolate E in time domain
        Field2D *F;      //pointer to owning field object
    };


    int get_direction(std::vector<int> p1, std::vector<int> p2);

}
#endif