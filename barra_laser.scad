module laser_module() {
    translate([0, 0, -0.2])
        cylinder(h=1.2, r=0.75);
    translate([0, 0, -2 + 0.01])
        cylinder(h=2, r=0.45);
}

module locking_module() {
    translate([0, 0, -1.1])
        cylinder(h=2.2, r=0.4);
}

module bucket_module() {
    translate([-0.4, -1.5, 0])
    color([0.5, 0.5, 0.5])
        cylinder(h=1, r=0.15);
    translate([0.4, 1.5, 0])
    color([0.5, 0.5, 0.5])
        cylinder(h=1, r=0.15);
}

module dmx_driver_module() {
    translate([1.375, 5.25, 0])
    color([0.5, 0.5, 0.5])
        cylinder(h=1, r=0.15);
    translate([-1.375, 5.25, 0])
    color([0.5, 0.5, 0.5])
        cylinder(h=1, r=0.15);
    translate([-0.7, -5.25, 0])
    color([0.5, 0.5, 0.5])
        cylinder(h=1, r=0.15);
}

module bucket_converter() {
    translate([0, 0, 1])
    color([0, 0, 1])
        cube([2.1, 4.35, 1.5], center=true);
    bucket_module();
}

module dmx_driver() {
    translate([0, 0, 1.5])
    color([0, 0, 0])
        cube([4.1, 15.2, 2.3], center=true);
    translate([1, 7.6, 1.5])
    color([0.8, 0.8, 0])
        cube([1.8, 4.8, 1.5], center=true);
    translate([-1, 7.6, 1.5])
    color([0.8, 0.8, 0])
        cube([1.8, 4.8, 1.5], center=true);
    dmx_driver_module();
}

$fa = 2;
$fs = 0.2;

translate([-1.4, 8, 0.75]) bucket_converter();
translate([+1.4, 8, 0.75]) bucket_converter();
translate([-1.4, 20, 0.75]) bucket_converter();
translate([+1.4, 20, 0.75]) bucket_converter();

translate([0, 33, 0.75]) dmx_driver();


difference() {
    cube([5, 100, 1.5], center=true);

    locking_module();
    translate([0, -47.875, 0]) locking_module();
    translate([0, +47.875, 0]) locking_module();
    
    translate([0, +15, 0]) laser_module();
    translate([0, -15, 0]) laser_module();
    translate([0, +45, 0]) laser_module();
    translate([0, -45, 0]) laser_module();

    translate([0, 33, 0]) dmx_driver_module();
    
    translate([-1.4, 8, 0]) bucket_module();
    translate([+1.4, 8, 0]) bucket_module();
    translate([-1.4, 20, 0]) bucket_module();
    translate([+1.4, 20, 0]) bucket_module();
}