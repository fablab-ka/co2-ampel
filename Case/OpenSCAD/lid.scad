// CO2 Ampel - Case
// By: FabLab Karlsruhe e.V., Martina Feger
// Date: 19.10.2020
// License: MIT

// https://www.thingiverse.com/thing:135408/files
use <Bevel_Extrude_Module_for_OpenSCAD/bevel_extrude.scad>

$fn=100;
pcb_length=168;
pcb_width=78;

wall=2; //min=2 !
base=2;
lidThick=3;
gap=1;  //puffer (auf jeder seite) zwischen pcb und gehaeuse

lid();

module lid(){
    difference(){
        union(){
            mirror([0,0,1]) translate([-39,-84,lidThick]) mirror([0,0,1]) bevel_extrude(height=lidThick, bevel_depth=(0.5*lidThick), $fn=50) offset(r=wall+gap) import (file = "/mnt/io/gemeinsam/co2ampel/pcb.dxf");
            screwFastening();
            lidFastening();
        }
        translate([0,45,-10]) cylinder(d=74, h=20, center = false); //top window
        translate([0,-45,-10]) cylinder(d=74, h=20, center = false); //bottom window
    }
    powerHoleFilling();
    switchHoleFilling();
}


module lidFastening(){
    lidHoleFilling(0,"top");
    lidHoleFilling(90,"top");
    lidHoleFilling(180,"top");
    
    lidHoleFilling(0,"bottom");
    lidHoleFilling(180,"bottom");
}


module lidHoleFilling(alpha, segment){
    r = 39.8;
    if (segment == "top"){
        intersection(){
            translate([-39,-84,-(8+lidThick)]) linear_extrude(height=8, center = false, convexity = 200) offset(r=1) import (file = "/mnt/io/gemeinsam/co2ampel/pcb.dxf");
            translate([0,45,-(lidThick+1.5)]) translate([r*cos(alpha),r*sin(alpha),0]) rotate([0,0,alpha]) translate([-4,0,0]) cube([8,6,3], center = true);
        }
        translate([0,45,-(lidThick+3)]) translate([r*cos(alpha),r*sin(alpha),0]) rotate([0,0,alpha]) rotate([90,0,0]) linear_extrude(height = 6, center = true) polygon(points = [[0,0], [0.7,0], [0,1.5]]);
    } else if (segment == "bottom"){
        intersection(){
            translate([-39,-84,-(8+lidThick)]) linear_extrude(height=8, center = false, convexity = 200) offset(r=1) import (file = "/mnt/io/gemeinsam/co2ampel/pcb.dxf");
            translate([0,-45,-(lidThick+1.5)]) translate([r*cos(alpha),r*sin(alpha),0]) rotate([0,0,alpha]) translate([-4,0,0]) cube([8,6,3], center = true);
        }
        translate([0,-45,-(lidThick+3)]) translate([r*cos(alpha),r*sin(alpha),0]) rotate([0,0,alpha]) rotate([90,0,0]) linear_extrude(height = 6, center = true) polygon(points = [[0,0], [0.7,0], [0,1.5]]);
    }
}



module powerHoleFilling(){
    translate([0,0,-10.4]) intersection(){
        difference(){
            translate([-39,-84,-lidThick]) linear_extrude(height=10.4, center = false, convexity = 200) offset(r=wall+gap) import (file = "/mnt/io/gemeinsam/co2ampel/pcb.dxf");
            translate([-39,-84,-lidThick]) linear_extrude(height=10.4, center = false, convexity = 200) offset(r=gap)  import (file = "/mnt/io/gemeinsam/co2ampel/pcb.dxf");
        }
        //translate([0,-85,0]) cube([12.4,10,24], center = true);
        translate([0,-85,0]) cube([12.2,10,24], center = true);
    }
}


module switchHoleFilling(){
    translate([0,0,-16.2]) intersection(){
        difference(){
            translate([-39,-84,-lidThick]) linear_extrude(height=16.2, center = false, convexity = 200) offset(r=wall+gap) import (file = "/mnt/io/gemeinsam/co2ampel/pcb.dxf");
            translate([-39,-84,-lidThick]) linear_extrude(height=16.2, center = false, convexity = 200) offset(r=gap)  import (file = "/mnt/io/gemeinsam/co2ampel/pcb.dxf");
        }
        alpha = -151;
        //translate([45*cos(alpha),45*sin(alpha)-45,13]) rotate([0,0,alpha]) cube([15,10.6,34], center = true);
        translate([45*cos(alpha),45*sin(alpha)-45,13]) rotate([0,0,alpha]) cube([15,10.4,34], center = true);
    }
}


module screwFastening(){
    translate([0,0,-(21.2+lidThick)]){
        difference(){
            union(){
                cylinder(d = 7.2, h = 21.2, centre = true);
                translate([0,0,10.6]) cube([55.4,2,21.2], center = true);
            }
            cylinder(d = 3.2, h = 21.2, center = true);
        }
    }
}
