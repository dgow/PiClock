ddd = 53;
$fa = 0.1;
$fs = 0.1;



wand = 1;

difference()
{
	cube ([60,60,3],true );
	translate( [0,0,-10] )
	{
		cylinder(ddd * 0.5, ddd * 0.5, ddd * 0.5);
	}

	hole = 2;
	translate( [22,22,-10] ){ #cylinder(100, hole, hole);	}
	translate( [-22,22,-10] ){ #cylinder(100, hole, hole);	}
	translate( [-22,-22,-10] ){ #cylinder(100, hole, hole);	}
	translate( [22,-22,-10] ){ #cylinder(100, hole, hole);	}
}

difference()
{
	$fa = 0.01;
	cylinder(35, ddd * 0.5 + wand, ddd * 0.5 + wand);

	translate( [0,0,-3] )
	{
#cylinder(42, ddd * 0.5, ddd * 0.5);
	}
}

color("blue")
difference()
{
translate( [0,0,35] )
{
	cylinder(5, ddd * 0.5 + wand, ddd * 0.5 + wand);
}
	cylinder(1000, 6,6, true);
}

