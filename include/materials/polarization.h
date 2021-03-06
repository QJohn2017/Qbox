#ifndef GUARD_polarization_h
#define GUARD_polarization_h

#include "../grid.h"
#include "../object.h"
#include "../vec.h"

namespace qbox {

    class Field2D;

    class polarization {
    public:
        polarization(const grid_properties &grid, int Npoles): grid(grid), Npoles(Npoles) {
            J = tensor3(grid.Nx, grid.Ny, Npoles); J.setZero();
        }
        virtual void update_J(Field2D &f) = 0;
        virtual void insert_object(const object &new_object) = 0;
        virtual void reset() {J.setZero();}

    protected:
        grid_properties grid;
        tensor3 J;    // Nx x Ny x Npoles tensor
        int Npoles;
    };

}

#endif
