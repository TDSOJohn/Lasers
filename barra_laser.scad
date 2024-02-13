$fn = 16;

module blocchetto_laser() {
    difference() {
        cube([2.5, 2.5, 1]);    
        
        translate([0.35, 0.35, 0])
            cylinder(3, 0.15, 0.15, center = true);
        translate([0.35, 2.15, 0])
            cylinder(3, 0.15, 0.15, center = true);
        translate([2.15, 0.35, 0])
            cylinder(3, 0.15, 0.15, center = true);
        translate([2.15, 2.15, 0])
            cylinder(3, 0.15, 0.15, center = true);
        translate([1.25, 1.25, 0.2])
            cylinder(3, 0.75, 0.75);
        translate([1.25, 1.25, -0.1])
            cylinder(3, 0.5, 0.5);
    }
}

module laser_module() {
    translate([0, 0, -0.1])
        cylinder(h=3.2, r=0.5);
}

module locking_module() {
    translate([0, 0, -0.1])
        cylinder(h=2.2, r=0.4);
}

module bucket_module() {
    translate([0, 0, 0.75])
    color([0.5, 0.5, 0.5])
        cylinder(h=1, r=0.15);
    translate([0.8, 3, 0.75])
    color([0.5, 0.5, 0.5])
        cylinder(h=1, r=0.15);
}

module dmx_driver_module() {
    translate([1.375, 5.25, 0.75])
    color([0.5, 0.5, 0.5])
        cylinder(h=1, r=0.15);
    translate([-1.375, 5.25, 0.75])
    color([0.5, 0.5, 0.5])
        cylinder(h=1, r=0.15);
    translate([-0.7, -5.25, 0.75])
    color([0.5, 0.5, 0.5])
        cylinder(h=1, r=0.15);
}

module bucket_converter() {
    color([0, 0, 1])
        cube([2.1, 4.35, 1.5]);
}

module dmx_driver() {
    color([0.2, 0.2, 0.2])
        cube([4.1, 15.2, 2.3]);
    translate([2.2, 13.6, 0])
    color([0.8, 0.8, 0])
        cube([1.8, 4.8, 1.5]);
    translate([0.1, 13.6, 0])
    color([0.8, 0.8, 0])
        cube([1.8, 4.8, 1.5]);
}

module antenna_circuit() {
    translate([0, 0, 0.8])
    color([0, 0.6, 0.6])
        cube([1.55, 6.7, 1]);
}

module laser_driver() {
    color([0, 0.7, 0.3])
        cube([0.85, 2, 0.5]);
}

$fa = 2;
$fs = 0.2;

translate([0.3, 55, 1.5]) bucket_converter();
translate([2.6, 55, 1.5]) bucket_converter();
translate([0.3, 68, 1.5]) bucket_converter();
translate([2.6, 68, 1.5]) bucket_converter();

translate([0.45, 74, 0.75]) dmx_driver();

translate([1.725, 20, 0.75]) antenna_circuit();

translate([2.075, 39, 1.5]) laser_driver();
translate([2.075, 60.5, 1.5]) laser_driver();
translate([0.475, 97, 1.5]) laser_driver();
translate([2.075, 9, 1.5]) laser_driver();

translate([1.25, 3.75, 1.5]) blocchetto_laser();
translate([1.25, 33.75, 1.5]) blocchetto_laser();
translate([1.25, 63.75, 1.5]) blocchetto_laser();
translate([1.25, 93.75, 1.5]) blocchetto_laser();

difference() {
    cube([5, 100, 1.5]);

    locking_module();
    translate([2.5, 2, 0]) locking_module();
    translate([2.5, 50, 0]) locking_module();
    translate([2.5, 98, 0]) locking_module();
    
    translate([2.5, 5, 0]) laser_module();
    translate([2.5, 35, 0]) laser_module();
    translate([2.5, 65, 0]) laser_module();
    translate([2.5, 95, 0]) laser_module();
    
    translate([0.8, 55.525, 0]) bucket_module();
    translate([3.1, 55.525, 0]) bucket_module();
    translate([0.8, 68.525, 0]) bucket_module();
    translate([3.1, 68.525, 0]) bucket_module();
}
