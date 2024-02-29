$fn = 16;

module rgb_laser() {
    cube([4, 6.8, 3.7]);
}

module rgb_holes() {
    translate([0.55, 0.55, 0.9])
    cylinder(h = 2, d = 0.15, center = true);
    translate([3.45, 6.25, 0.9])
    cylinder(h = 2, d = 0.15, center = true);
    translate([3.45, 0.55, 0.9])
    cylinder(h = 2, d = 0.15, center = true);
    translate([0.55, 6.25, 0.9])
    cylinder(h = 2, d = 0.15, center = true);
}


/*
translate([0, 0, 1.5])
rgb_laser();
translate([32, 0, 1.5])
rgb_laser();
translate([64, 0, 1.5])
rgb_laser();
translate([96, 0, 1.5])
rgb_laser();
*/

difference() {
    difference() {
        cube([100, 7, 1.5]);
        translate([-0.1, 0.2, 0.2])
        cube([101, 6.6, 1.1]);
    }
    
    translate([10, 3.5, 0.9])
    cylinder(h = 2, d = 0.8, center = true);
    translate([50, 3.5, 0.9])
    cylinder(h = 2, d = 0.8, center = true);
    translate([90, 3.5, 0.9])
    cylinder(h = 2, d = 0.8, center = true);

    translate([0, 0, 0])
    rgb_holes();
    translate([32, 0, 0])
    rgb_holes();
    translate([64, 0, 0])
    rgb_holes();
    translate([96, 0, 0])
    rgb_holes();
}
