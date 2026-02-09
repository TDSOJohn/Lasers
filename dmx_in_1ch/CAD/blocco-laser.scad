$fa = 1;
$fs = 0.4;
$fn = 32;

module blocchetto_laser() {
    difference() {
        cube([25, 25, 10]);    
        
        translate([3.5, 3.5, 0])
            cylinder(30, 1.5, 1.5, center = true);
        translate([3.5, 21.5, 0])
            cylinder(30, 1.5, 1.5, center = true);
        translate([21.5, 3.5, 0])
            cylinder(30, 1.5, 1.5, center = true);
        translate([21.5, 21.5, 0])
            cylinder(30, 1.5, 1.5, center = true);
        translate([12.5, 12.5, 2])
            cylinder(30, 7.5, 7.5);
        translate([12.5, 12.5, -1])
            cylinder(30, 5, 5);
    }
}

blocchetto_laser();