use </mnt/io/gemeinsam/prusa/Bevel_Extrude_Module_for_OpenSCAD/bevel_extrude.scad>

$fn=100;
pcb_length=168;
pcb_width=78;


wall=2; //min=2 !
base=1.6;
gap=1;

enclosure();

module enclosure(){
    difference(){
        union(){
            difference(){
                union(){
                    translate([-39,-84,0]) linear_extrude(height=base+38, center = false, convexity = 200) offset(r=wall+gap) import (file = "pcb_v2.dxf");
                    translate([0,88.9+wall,2]) wallFastening();
                }
                translate([-39,-84,0]) translate([0,0,base]) linear_extrude(height=38, center = false, convexity = 200) offset(r=gap)  import (file = "pcb_v2.dxf");
                //translate([0,0,0.5*base]) cylinder(d1 = 10.2, d2 = 4.2, h = base, center = true);
                //translate([0,0,1]) cylinder(d1 = 10.2, d2 = 4.2, h = 2, center = true);
                translate([0,0,0.5*base]) cylinder(d1 = 10.8, d2 = 4.2, h = base, center = true);
        
                airConditioning();
                //antennaHole();
            }
            screwFastening();
            pcbBearing();
            difference(){
                lidBearing();
                translate([25,0,base+33]) cylinder(d = 8, h = 5, center = true);
                translate([-25,0,base+33]) cylinder(d = 8, h = 5, center = true);
            }
            blowProtection();
        }
        powerHole();
        switchHole();
        lidFastening();
    }
}


module pcb(){
color("green")  linear_extrude(height = 1.6, center = false, convexity = 200)
   import (file = "pcb_v2.dxf");       
}


module antennaHole(){
    r = 39.8;
    alpha = 120;

    translate([0,45,base+6]) translate([r*cos(alpha),r*sin(alpha),0]) rotate([0,0,alpha])
    rotate([0,90,0]) cylinder(d=6.4, h=10, center = true);
}


module lidFastening(){
    r = 39.8;
    
    //top segment
    translate([0,45,base+35]){
        alpha = 90;
        translate([r*cos(alpha),r*sin(alpha),0]) rotate([0,0,alpha]) lidHole();
    
        beta = 0;
        translate([r*cos(beta),r*sin(beta),0]) rotate([0,0,beta]) lidHole();
    
        gamma = 180;
        translate([r*cos(gamma),r*sin(gamma),0]) rotate([0,0,gamma]) lidHole();
    }
    
    //base segment
    translate([0,-45,base+35]){
        beta = 0;
        translate([r*cos(beta),r*sin(beta),0]) rotate([0,0,beta]) lidHole();
    
        gamma = 180;
        translate([r*cos(gamma),r*sin(gamma),0]) rotate([0,0,gamma]) lidHole();
    }
}


module lidHole(){
    rotate([90,0,0]) linear_extrude(height = 6.5, center = true) polygon(points = [[0,0], [0.8,0], [0,1.6]]);
}


module wallFastening(){
    difference(){
        union(){
            cube([21,14,4], center = true);
            translate([0,7,0]) cylinder(d=12, h=4, center = true);
        }
        translate([10.5,7,0]) scale([1,2.75,1]) cylinder(d=9, h=4, center =true);
        translate([-10.5,7,0]) scale([1,2.75,1]) cylinder(d=9, h=4, center =true);
        translate([0,2,0]) cylinder(d = 8, h = 4, center = true);
        translate([0,8,0]) cylinder(d = 4.5, h = 4, center = true);
        translate([0,4,0]) cube([4.5,8,4], center = true); 
        
        translate([0,0,4]) mirror([0,0,1]) bevel_extrude(height=4, bevel_depth=2, $fn=50)
        union(){
            translate([0,2,0]) circle(d=10);
            translate([0,4,0]) square([6.5, 8], center = true);
            translate([0,8,0]) circle(d=6.5);
        }
    }
}


module switchHole(){
    alpha = -151;
    translate([45*cos(alpha),45*sin(alpha)-45,base+28.6]) rotate([0,0,alpha]) cube([15,10.6,24], center = true);
}


module powerHole(){
    translate([0,-85,base+28.6]) cube([12.4,10,24], center = true);
}


module airConditioning(){
    //top segment
    translate([42,45,base+6]) airHole(4);    //right side
    translate([35,15,base+6]) rotate([0,0,-20]) airHole(4);  //right side

    translate([-42,45,base+6]) airHole(4);   //left side
    translate([-35,15,base+6]) rotate([0,0,20]) airHole(4);  //left side
    
    //translate([42,45,base+24]) airHole(4);    //right side
    //translate([-42,45,base+24]) airHole(4);   //left side
    
    //base segment
    alpha = 30; //bottom = -90°
    translate([45*cos(-90+alpha),45*sin(-90+alpha)-40,base+6]) rotate([0,0,-90+alpha]) airHole(4);
    translate([45*cos(-90-alpha),45*sin(-90-alpha)-40,base+6]) rotate([0,0,-90-alpha]) airHole(4);
    
    //translate([45*cos(-90+alpha),45*sin(-90+alpha)-40,base+24]) rotate([0,0,-90+alpha]) airHole(4);
    //translate([45*cos(-90-alpha),45*sin(-90-alpha)-40,base+24]) rotate([0,0,-90-alpha]) airHole(4);
}


module airHole(n){
    l=20;
    d=1.6;
    a = (l-n*d)/(n+1);
    difference(){
        scale([1,2,1]) rotate([0,90,0]) cylinder(d = 0.5*l, h = 10, center = true);
        for (i = [0:1:n]){
            translate([0,((0.5+i)*d+(i+1)*a)-10,0]) cube([15,d,15], center = true);
        }
    }
}


module blowProtection(){
    difference(){
         translate([-39,-84,base]) linear_extrude(height = 14.5, center = false, convexity = 200) offset(r=-4)  import (file = "pcb_v2.dxf");
        translate([-39,-84,base]) linear_extrude(height = 14.5, center = false, convexity = 200) offset(r=-5.4)  import (file = "pcb_v2.dxf");
        translate([0,-44,base+7.25]) cube([100,100,14.5], center = true);
        translate([0,85,base+7.25]) cube([100,50,14.5], center = true);
    }
}


module lidBearing(){
    translate([-39,-84,0]) translate([0,0,base+34.8]) mirror([0,0,1]) bevel_extrude(height=10, bevel_depth=8, $fn=50) lidBearingSkew();
    
}


module lidBearingSkew(){
    difference(){
        offset(r=gap+1.6)  import (file = "pcb_v2.dxf");
        offset(r=gap-1)  import (file = "pcb_v2.dxf");
    }
}


module pcbBearing(){
    difference(){
        translate([-39,-84,0]) translate([0,0,base+15]) linear_extrude(height = 1.6, center = false, convexity = 200) offset(r=gap)  import (file = "pcb_v2.dxf");
        //translate([-39,-84,0]) translate([0,0,base+15]) linear_extrude(height = 1.6, center = false, convexity = 200) offset(r=gap-0.8)  import (file = "pcb_v2.dxf");
        translate([-39,-84,0]) translate([0,0,base+15]) linear_extrude(height = 1.6, center = false, convexity = 200) offset(r=gap-0.6)  import (file = "pcb_v2.dxf");
    }

    translate([-39,-84,0]) translate([0,0,base+15]) mirror([0,0,1]) bevel_extrude(height=10, bevel_depth=8, $fn=50) pcbBearingSkew();
}


module pcbBearingSkew(){
    difference(){
        offset(r=gap+1.6) import (file = "pcb_v2.dxf");
        offset(r=gap-2) import (file = "pcb_v2.dxf");
    }
}


module screwFastening(){
    translate([0,0,base]){
        difference(){
            union(){
                cylinder(d = 7.2, h = 15);
                rotate([0,45,0]) cube([15,2,15], center = true);
            }
            translate([0,0,-6]) cube([20,4,12], center = true);
            translate([0,0,-base]) cylinder(d = 4.2, h = base + 18.1);
        }
    }
}
