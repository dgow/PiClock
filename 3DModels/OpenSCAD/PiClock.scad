mainSize = [190, 90, 7];
groundZ = 80;
groundY = 3;

displaySize = [80.8, 53.2, 1000 ];
displayOutBounds = [ displaySize.x + 2 + 4, displaySize.y + 2 + 2, 7];

ground = (mainSize.y - displayOutBounds.y);
stand = [ 41, ground * 0.5, 30 ];

module front()
{
	difference()
	{
		intersection()
		{
			cube( mainSize, true );

			radius = mainSize.z;

			hull(){
				$fn = 100;
				rotate( 90, [1, 0 ,0] )
					translate( [mainSize.x *0.5 - radius, mainSize.z * 0.5, -mainSize.y * 0.5 ] ) 
					cylinder( mainSize.y, radius, mainSize.z);
				rotate( 90, [1, 0 ,0] )
					translate( [-mainSize.x *0.5 + radius, mainSize.z * 0.5, -mainSize.y * 0.5 ] ) 
					cylinder( mainSize.y, radius, mainSize.z);
			}
		}
		translate( [0,0,1])
		{
			cube( displayOutBounds, true );
		}	
		translate( [1,0,1])
		{
			cube(displaySize,true);
		}
	}
}

module stand()
{
	union()
	{
/*		color("red")
			translate( [0, -(displayOutBounds.y*0.5 + mainSize.y*0.5) * 0.5, mainSize.z*0.5 + stand.z * 0.5 ] )
			cube(stand, true);

		smallStand = 8;
		color("red")
			translate( [-displayOutBounds.x *0.5 + smallStand*0.5,
					-(displayOutBounds.y*0.5 + mainSize.y*0.5) * 0.5, 
					mainSize.z*0.5 + stand.z * 0.5  ] )
			cube( [smallStand, stand.y, stand.z], true);
*/
		color("red")
			translate( [0, -(mainSize.y*0.5 ) + groundY * 0.5, groundZ*0.5 + mainSize.z * 0.5 ] )
			cube( [mainSize.x, groundY, groundZ] , true);
	}
}

module usb()
{
	hole = 20;
	translate( [0,displayOutBounds.y*0.5 - hole, 0] )
		mirror([-1, 0, 0]){
			cube( [displayOutBounds.x * 0.5 + 45, hole, 10]);
		}
}

module frontWithUsb()
{
	difference()
	{
		front();
		usb();
		displayScrewHoles();
	}
}

module sides()
{
	color("green"){
		translate( [mainSize.x * 0.5 - groundY,-mainSize.y*0.5 + groundY, mainSize.z * 0.5] ) 
		{
			cube([groundY, mainSize.y - groundY, groundZ], false); 
		}
		translate( [-mainSize.x * 0.5 ,-mainSize.y*0.5 + groundY, mainSize.z * 0.5] ) 
		{
			cube([groundY, mainSize.y - groundY, groundZ], false); 
		}
	}
}

module top()
{
	translate( [0, mainSize.y*0.5 - groundY*0.5,groundZ*0.5 + mainSize.z*0.5] ) 
	{
		cube([mainSize.x - groundY*2 , groundY, groundZ], true); 
	}
}

module back()
{
	color("blue")
		translate( [0, 0, groundZ + groundY * 2] )
#cube( [mainSize.x, mainSize.y, groundY], true);
}

zatschelW = 7;
module zatschel()
{
	zatschelW = 7;
	l = 20;
	translate( [0,0, -l*.5] )
		difference()
		{
			cylinder(l, 0, zatschelW, true); 
			translate( [0,5,0] ) 
				cube([100, 10, 100], true);
		}
}

leftTop = 		[mainSize.x * 0.75 * 0.5, mainSize.y*0.5 - groundY, -mainSize.z * 0.5 + groundZ + mainSize.z];
rightTop = 		[-mainSize.x * 0.75 * 0.5, mainSize.y*0.5 - groundY, -mainSize.z * 0.5 + groundZ + mainSize.z];
leftBottom = 	[mainSize.x * 0.75 * 0.5, mainSize.y*0.5 - groundY, -mainSize.z * 0.5 + groundZ + mainSize.z];
rightBottom =  	[-mainSize.x * 0.75 * 0.5, mainSize.y*0.5 - groundY, -mainSize.z * 0.5 + groundZ + mainSize.z];

module zatschelS()
{
	translate( leftTop )
	zatschel();
	translate(rightTop)
	zatschel();

	rotate(180, [0,0,1] )
	{
		translate(leftBottom)
		zatschel();
		translate(rightBottom)
		zatschel();
	}
}

module backHoles(w)
{
	l = 30;
	//w = 2;
	$fn = 100;
	translate(leftTop )
	translate([0,-zatschelW*0.25,0])
	cylinder(l, w,w, true);
	translate(rightTop)
	translate([0,-zatschelW*0.25,0])
	cylinder(l, w,w, true);

	rotate(180, [0,0,1] )
	{
	translate(leftBottom)
	translate([0,-zatschelW*0.25,0])
	cylinder(l, w,w, true);
	translate(rightBottom)
	translate([0,-zatschelW*0.25,0])
	cylinder(l, w,w, true);
	}
}

module cableHole()
{
	translate( [0, -mainSize.y * 0.5, 0] )
	cylinder(1000, 10, 10, true);
}

module displayScrewHoles()
{
	$fs = 0.01;
	holeRadius = 1.5;
	x = 27.5;
	h = 10;
	y = 3;

	translate( [x, displayOutBounds.y * 0.5 + 2 + holeRadius, y ] ) 
	cylinder(h, holeRadius,holeRadius, true);
	translate( [-x, displayOutBounds.y * 0.5 + 2 + holeRadius, y ] ) 
	cylinder(h, holeRadius,holeRadius, true);
	translate( [x, -displayOutBounds.y * 0.5 - 2 - holeRadius, y ] ) 
	cylinder(h, holeRadius,holeRadius, true);
	translate( [-x, -displayOutBounds.y * 0.5 - 2 - holeRadius, y ] ) 
	cylinder(h, holeRadius,holeRadius, true);
}

module speakerHoles()
{
	$fs = 0.1;
	$fa = 0.1;
	translate( [0,0, mainSize.z * 0.5 + groundZ * 0.5 ] )
	{
		rotate( [0,90,0] )
		{
			speakerSize = 52;
			#cylinder(200, speakerSize * 0.5, speakerSize * 0.5, true);

			screwSize = 2;
			translate( [22,22, 22] )
			cylinder(300, screwSize, screwSize, true);
			translate( [-22,22, 22] )
			cylinder(300, screwSize, screwSize, true);
			translate( [-22,-22, 22] )
			cylinder(300, screwSize, screwSize, true);
			translate( [22,-22, 22] )
			cylinder(300, screwSize, screwSize, true);
		}
	}
}

//main
translate([0,0, mainSize.z * 0.5])
union() 
{

// Main
/* 
	frontWithUsb();
	stand();
	difference()
	{
		sides();
		speakerHoles();
	}
	top();

	
	difference()
	{
		zatschelS();
		backHoles(1);
	}
*/

	//displayScrewHoles();
    
    
//BackPlate
	difference()
	{
		back();
		backHoles(1.5);
		cableHole();
	}
    
}

