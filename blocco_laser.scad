$fa = 1;
$fs = 0.4;
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

blocchetto_laser();