$fn = 16;

translate([1.5, 1.5, -0.5])
    cylinder(h = 1.5, d = 0.75);

module collimatore() {
    difference() {
        cylinder(h = 0.4, d = 2.5);
        translate([0, 0, -0.1])
            cylinder(h = 0.6, d = 2);
    }
}

translate([1.5, 1.5, 0.6])
    collimatore();
translate([1.5, 1.5, -0.5])
    collimatore();

difference() {
    cube([3, 3, 0.5]);
    translate([1.5, 1.5, -0.5])
        cylinder(h = 3, d = 0.9);
    translate([2.6, 2.6, -0.5])
        cylinder(h = 3, d = 0.3);
    translate([2.6, 0.4, -0.5])
        cylinder(h = 3, d = 0.3);
    translate([0.4, 2.6, -0.5])
        cylinder(h = 3, d = 0.3);
    translate([0.4, 0.4, -0.5])
        cylinder(h = 3, d = 0.3);
}
