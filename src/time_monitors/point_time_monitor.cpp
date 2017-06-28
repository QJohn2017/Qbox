#include "field2.h"
#include "time_monitors/point_time_monitor.h"

namespace qbox {

    point_time_monitor::point_time_monitor(std::string name, const vec &pos):
        time_monitor(name), pos(pos) {};
    point_time_monitor::point_time_monitor(const vec &pos): 
        point_time_monitor("monitor_" + std::to_string(_num_created), pos) {_num_created++;}

    void point_time_monitor::set_F(Field2D *newF) {
        time_monitor::set_F(newF);
        h5cpp::write_vector<double>(pos, get_group(), "position");
    }

    void point_time_monitor::write(const fields& A) {
        switch(A) {
            case fields::E   : write(fields::Ez); return; break;
            case fields::H   : write(fields::Hx); 
                               write(fields::Hy); return; break;
            case fields::all : write(fields::E); 
                               write(fields::H);  return; break;
            default : break;
        }

        ivec ipos = F->grid.to_grid(pos);
        tensor& field = F->get_field_ref(A);
        double E = field(ipos);

        auto iter = dsets.find(A);
        if (iter != dsets.end())
            iter->second.append(&E);
        else {
            std::string name = field_names.at(A);
            auto h5group = get_group();
            auto dset = h5cpp::write_scalar(E, h5group, name, h5cpp::append::True);
            dsets[A] = std::move(dset);
        }
    }
}