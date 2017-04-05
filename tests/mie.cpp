#include <qbox.h>
#include <iostream>

using namespace std;
using namespace qbox;

int main() {
    int pml_thickness = 20;
    double res = 2;
    double f = 2/30.0;

    grid_properties grid(120,120,res,pml_thickness);
    grid.set_tfsf(30);

    Field2D norm(grid, "inc.h5");

    //cylinder_monitor box_inc("box_inc", cylinder_surface(vec(60,60), 30), freq_data(1/30.0,3/30.0, 200)); 
    surface_monitor inc("inc",surface({40,60}, {80,60}), freq_data(1/30.0,3/30.0, 200)); 
    norm.add_monitor(inc);

    gaussian_line_source s1(fields::Ez, surface({0,30},{120,30}), f, 1/200.0, 80);
    //norm.add_source(s1);

    for (int i = 0; i != 4000; i++) {
        norm.update();
        //norm.writeE();
    }
    inc.write_flux();


    Field2D scat(grid, "scat.h5");

    object o1(cylinder(20), simple_material(2), vec(60,60), vec(1,1));
    scat.add_object(o1);

    //cylinder_monitor box_scat("box_scat", cylinder_surface(vec(60,60), 30), freq_data(1/30.0,3/30.0, 200)); 
    box_monitor box_scat("box_scat",volume({60,60}, 75), freq_data(1/30.0,3/30.0, 200)); 
    scat.add_monitor(box_scat);

    gaussian_line_source s2(fields::Ez, surface({0,30},{120,30}), f, 1/200.0, 80);
    //scat.add_source(s2);

    for (int i = 0; i != 4000; i++) {
        scat.update();
        //scat.writeE();
    }
    box_scat.write_flux();
}
