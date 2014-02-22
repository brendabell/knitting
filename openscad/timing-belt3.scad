/*
 * File: timing-belt3.scad
 *
 * Copyright (C) 2013 Brenda A. Bell - All Rights Reserved
 *
 * You may use, distribute and modify this code under the terms
 * of the GNU General Public License.
 *
 * You should have received a copy of the GNU General Public
 * License with this file. If not, please visit:
 *
 *     http://opensource.org/licenses/gpl-license.
 *
 * To report bugs or submit comments and suggestions, please
 * contact the author via the contact form on her blog:
 *
 *    http://brendaabell.com
 */

/* compute the belt's radius */

r=540/PI/2;

/* function to render a single 30-tooth segment starting with the
   two extruded teeth */
module segment(segnum) {
  for (toothnum=[0:29]) {
    if (toothnum < 2) {
      tooth((segnum*120)+(toothnum*4), -1.5, 6, false);
    }
    else {
      tooth((segnum*120)+(toothnum*4), 0, 3, true);
    }
  }
}

/* function to render a single tooth on the belt */
module tooth(rotdeg, transz, cylheight, cylctr) {
  rotate([0,0,rotdeg]) {
    translate([0,r-1.5,transz]) {
      cylinder(r=3/2,h=cylheight,center=cylctr,$fn=16);
    }
  }
}

/* render the main belt */
difference(){
  cylinder(r=r, h=3, center=true, $fn=90);
  cylinder(r=r-1.5, h=3.1, center=true, $fn=90);
}

/* add the three toothed segments */
for (i=[0:2]) {
  segment(i);
}

/* add the three pairs of outer teeth for the clips */
for (pairnum=[0:2]) {
  for (toothnum=[0:1]) {
    rotate([0,0,(pairnum*120)+(toothnum*4)]) {
      translate([-.5,r-1,-1.5]) {
        cube([1,2,6], center=false);
      }
    }
  }
}
