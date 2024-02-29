$fn = 16;

module rgb_laser() {
    cube([40, 68, 37]);
}

module rgb_holes() {
    translate([5.5, 5.5, 9])
    cylinder(h = 20, d = 1.5, center = true);
    translate([34.5, 62.5, 9])
    cylinder(h = 20, d = 1.5, center = true);
    translate([34.5, 5.5, 9])
    cylinder(h = 20, d = 1.5, center = true);
    translate([5.5, 62.5, 9])
    cylinder(h = 20, d = 1.5, center = true);
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
        cube([1000, 70, 15]);
        translate([-1, 2, 2])
        cube([1010, 66, 11]);
    }
    
    translate([100, 35, 9])
    cylinder(h = 20, d = 8, center = true);
    translate([500, 35, 9])
    cylinder(h = 20, d = 8, center = true);
    translate([900, 35, 9])
    cylinder(h = 20, d = 8, center = true);

    translate([0, 0, 0])
    rgb_holes();
    translate([320, 0, 0])
    rgb_holes();
    translate([640, 0, 0])
    rgb_holes();
    translate([960, 0, 0])
    rgb_holes();
}
