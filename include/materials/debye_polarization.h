#ifndef GUARD_debye_polarization_h
#define GUARD_debye_polarization_h

#include "qbox/materials/debye.h"
#include "qbox/grid.h"
#include "qbox/object.h"
#include "qbox/vec.h"

namespace qbox {

    class Field2D;

    class debye_polarization {
    public:
        debye_polarization(const grid_properties &grid, const debye &mat);
        void update_J(Field2D &f);
        void insert_object(const object &new_object);

    private:
        grid_properties grid;
        debye mat;

        tensor beta, J;
    };

}

#endif