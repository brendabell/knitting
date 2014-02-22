/*
* File: timing-belt4.scad
*
* Copyright (C) 2013 Brenda A. Bell - All Rights Reserved
*
* You may use, distribute and modify this code under the terms
* of the GNU General Public License.
*
* You should have received a copy of the GNU General Public
* License with this file. If not, please visit:
*
*	  http://opensource.org/licenses/gpl-license.
*
* To report bugs or submit comments and suggestions, please
* contact the author via the contact form on her blog:
*
*	 http://brendaabell.com
*/

/* compute the belt's radius */

thickness=.8;
belt_width=3;
inner_radius=540/PI/2;
outer_radius=inner_radius+thickness;

/* compute the radius of the teeth */

tooth_diameter=3;
tooth_radius=tooth_diameter/2;

/* function to render a single 30-tooth segment starting with the
two extruded teeth */
module segment(segnum)
{
	for (tooth_idx=[0:29])
	{
		assign( angle=(segnum*120)+(tooth_idx*4) )
		{
			if (tooth_idx < 2)
			{
				/* the extruded teeth are twice as wide as the
				   others */
				tooth(angle, height=belt_width*2);
			}
			else
			{
				tooth(angle, height=belt_width);
			}
		}
	}
}

/* function to render a single tooth on the belt */
module tooth(angle, height)
{
	rotate([0,0,angle])
	{
		translate([0,inner_radius,0])
		{
			/* we need a semi-circle, so we render a cylinder
			   and chop off one side */
			difference()
			{
				/* render a cylinder */
				cylinder(r=tooth_radius,h=height,center=false,$fn=16);
				/* eliminate one half */
				translate([-1*tooth_radius,0,0])
				{
					cube(size=[tooth_diameter,tooth_diameter,height],center=false);
				}
			}
		}
	}
}

/* render the main belt */
difference()
{
	cylinder(r=outer_radius, h=belt_width, center=false, $fn=90);
	translate([0,0,0])
	{
		cylinder(r=inner_radius, h=belt_width, center=false, $fn=90);
	}
}

/* add the three toothed segments */
for (i=[0:2])
{
	segment(i);
}

/* add the three pairs of outer teeth for the clips */
for (pairnum=[0:2])
{
	for (toothnum=[0:1])
	{
		rotate([0,0,(pairnum*120)+(toothnum*4)])
		{
			/* center the clip gear on the tooth and sink it into
			   the tooth a bit */
			translate([-.5,outer_radius-1,0])
			{
				cube([1,2,belt_width*2], center=false);
			}
		}
	}
}
