#ifndef GUARD_qbox_h
#define GUARD_qbox_h

/// qbox is the global namespace for Qbox
namespace qbox{}

//main
#include "qbox/field2.h"
#include "qbox/vec.h"
#include "qbox/dft.h"

//geometry
#include "qbox/geometry/cylinder.h"
#include "qbox/geometry/ellipse.h"
#include "qbox/geometry/block.h"

//materials
#include "qbox/materials/simple_material.h"
#include "qbox/materials/debye.h"
#include "qbox/materials/drude.h"
#include "qbox/materials/lorentz.h"
#include "qbox/materials/creation.h"

//monitors (DFT)
#include "qbox/monitors/point_monitor.h"
#include "qbox/monitors/surface_monitor.h"
#include "qbox/monitors/cylinder_monitor.h"
#include "qbox/monitors/box_monitor.h"
#include "qbox/monitors/volume_monitor.h"

//monitors (time)
#include "qbox/time_monitors/point_time_monitor.h"
#include "qbox/time_monitors/surface_time_monitor.h"
#include "qbox/time_monitors/volume_time_monitor.h"

//sources
#include "qbox/sources/point_source.h"
#include "qbox/sources/line_source.h"

#endif

