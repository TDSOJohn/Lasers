$fn = 16;

module rgb_laser() {
    difference() {
        cube([40, 68, 37]);
        rotate([90, 0, 0])
        translate([20, 18.5, -61])
        cylinder(h = 15, d = 12, center = true);
    }
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

translate([0, 0, 22])
    rgb_laser();
translate([320, 0, 22])
    rgb_laser();
translate([640, 0, 22])
    rgb_laser();
translate([960, 0, 22])
    rgb_laser();

difference() {
    difference() {
        cube([1000, 70, 20]);
        translate([-1, 3, -3])
        cube([1010, 70, 20]);
    }
    
    rotate([90, 0, 0])
    translate([60, 9, 0])
    cylinder(h = 20, d = 6, center = true);
    rotate([90, 0, 0])
    translate([500, 9, 0])
    cylinder(h = 20, d = 6, center = true);
    rotate([90, 0, 0])
    translate([940, 9, 0])
    cylinder(h = 20, d = 6, center = true);

    translate([0, 0, 2])
    rgb_holes();
    translate([320, 0, 2])
    rgb_holes();
    translate([640, 0, 2])
    rgb_holes();
    translate([960, 0, 2])
    rgb_holes();
}
