#include <stdio.h>
#include "SimpleFft.h"
#include "SimpleShifter.h"
#include "Datatypes.h"

int main(int argc,char** argv)
{

signed short testsig[]={1,12,-13,14,4,-4,13,5,-13,17,-3,5,11,-10,7,-5,16,1,9,-13,-8,8,-9,12,2,-7,4,-4,-5,6,-14,4,-2,-4,14,-9,-6,13,-1,17,-2,10,-12,1,-11,-5,-17,-11,-3,13,-2,9,-17,3,-8,14,11,-3,-4,-6,3,7,-5,-3,3,6,12,21,13,5,-5,10,3,13,0,-9,-3,-9,-8,3,-14,-4,-4,3,-15,8,-6,18,10,16,7,4,1,2,2,-1,-6,15,5,10,13,-8,9,6,2,-5,3,-30,10,-11,-1,6,-7,1,-13,-6,-20,1,-3,8,10,-4,7,-11,1,1,6,6,5,-2,0,-15,-1,-1,-2,7,15,-11,-9,-8,-16,0,1,13,-2,31,1,17,-5,-8,2,-4,0,0,-13,-9,7,-2,6,0,-14,-3,-1,2,5,14,-2,-5,-9,-20,-7,-23,-1,-2,-1,15,-3,11,12,-8,13,-6,-4,5,2,-1,9,2,-2,-2,1,-4,-3,7,-2,7,15,-7,-6,-8,-13,10,15,1,21,-15,-5,-8,3,-3,3,2,10,13,2,6,-13,1,-1,-4,2,8,-7,12,-6,4,11,-3,5,-11,-1,-8,-16,4,-14,6,-2,21,1,13,10,-5,1,-1,-20,12,-11,-4,9,-15,11,-10,9,-11,3,6,1,8,2,5,-5,3,-3,3,6,3,10,13,-12,-13,-10,-11,3,5,9,-14,-1,-13,-2,6,6,-4,19,-8,-4,-14,-1,-14,2,0,-8,1,-3,0,-2,6,-2,4,2,3,2,-4,-6,-18,3,-7,10,2,1,-14,0,-6,-9,-6,-14,-4,8,2,7,-6,-7,-9,-3,-8,-1,6,0,-2,-2,-8,1,19,6,21,-4,4,3,11,9,-7,-1,1,12,20,-10,-9,-6,-7,17,4,18,6,6,-1,13,-3,4,-9,4,-1,11,-2,0,5,0,10,17,-19,10,-16,7,-2,-2,3,-9,-15,4,6,3,15,3,-11,7,-5,-10,7,-19,9,8,-3,10,-3,-13,0,2,-5,9,-4,-10,6,-7,11,8,1,5,8,2,0,3,-2,-3,4,16,-7,8,0,17,1,28,-5,-7,2,2,8,1,-3,-12,-13,0,-12,5,6,-14,11,1,1,4,1,-2,10,-2,7,-12,-6,-11,2,-3,1,-8,-3,-8,7,-13,-5,-1,-10,5,5,-3,6,4,2,4,-10,-2,3,5,12,4,3,11,-11,13,-15,7,-6,3,2,28,-13,12,1,-8,5,4,-4,18,-1,12,1,6,-6,8,0,-3,-11,-2,-6,-4,8,-18,0,2,-14,6,0,-4,2,-6,0,-18,3,-12,2,0,-4,-4,-1,2,8,7,13,6,-10,2,1,-2,21,8,22,15,-8,-2,0,-10,1,-2,8,-10,-8,8,1,6,-2,-9,-7,9,-5,9,-3,2,-6,8,0,-7,-4,-15,-15,0,-2,-3,1,-6,-11,14,3,5,7,-6,4,-11,3,-11,0,-7,-9,-3,0,-13,5,-23,-1,-16,-3,2,-9,12,4,-12,24,-18,10,11,-6,-10,-2,-13,-8,3,5,1,9,-5,-3,-4,-14,-2,-14,15,3,-4,13,-3,0,9,4,-2,12,-4,10,0,7,-10,-2,-3,4,3,15,10,17,5,10,-1,-7,0,2,2,1,12,-8,12,-2,0,10,-2,1,10,-6,-1,0,-18,16,-5,11,-2,-8,-3,-2,5,3,6,1,16,1,11,4,-10,2,-10,4,4,11,-3,14,-7,3,-3,3,-19,-3,-19,2,-5,17,1,-3,1,-16,8,-4,-4,3,4,5,10,-8,-5,-4,8,10,16,10,-1,-7,-9,-7,-2,18,0,7,-3,-4,0,-1,4,-2,0,3,-11,5,-3,-1,11,0,9,-1,-15,-2,12,5,17,-1,4,-11,-10,-13,-2,-18,12,-12,-1,-7,-5,12,-16,16,-6,-3,-11,17,-2,12,0,17,-2,15,-11,5,-15,8,-8,20,13,-5,-1,-26,-3,-17,-4,4,5,-4,16,-6,6,2,11,1,-1,-13,-11,3,2,3,8,3,-9,0,-1,-12,5,-5,4,10,-4,12,0,4,1,4,-11,0,-4,7,10,2,-2,-18,-11,1,-3,-1,-4,2,1,18,5,3,-4,-5,-3,-6,6,3,-13,-5,-2,-6,13,8,7,6,0,-22,-2,-17,-5,8,-2,5,2,0,-4,13,-16,6,-3,14,-4,12,6,-5,-9,1,-14,11,20,4,9,-12,-21,-11,-4,0,6,8,-3,4,-4,-12,9,-1,-2,13,0,6,-11,-4,7,4,11,0,-5,4,0,-12,6,-4,-1,-8,8,-3,1,5,-8,8,0,13,13,13,13,8,21,-2,16,-10,-8,0,16,-7,11,10,-6,17,4,-1,6,-2,1,8,5,0,7,11,4,17,5,-10,0,-2,5,11,6,2,-7,3,-1,0,-3,-4,-6,4,6,-11,1,-4,-5,12,10,-2,-3,-12,2,0,6,-3,-6,-8,-11,-6,-1,-1,-21,7,-18,10,5,3,-6,-8,-6,-7,15,-5,12,-1,1,-17,10,-8,2,18,3,-1,5,-1,-4,10,7,4,17,-5,-2,-17,-6,-18,4,2,-6,6,-11,5,1,0,12,-16,2,5,-1,8,3,-4,1,-5,-12,-12,-11,-1,-3,-13,-11,-6,-14,3,-7,0,-23,-11,-3,9,15,9,1,3,-4,15,-5,6,-2,-4,8,3,-10,-4,-2,-4,13,2,-6,-3,-11,-6,-2,-6,-9,-1,-16,7,7,-12,14,-2,9,10,13,11,12,24,-11,8,-18,4,7,12,13,-14,-2,-13,13,1,6,2,7,-8,7,-12,-9,5,1,-3,4,-10,-8,1,5,3,0,-9,-15,-9,-8,-27,-10,-14,-9,8,12,1,4,12,5,7,13,-8,12,6,0,10,-12,-4,-13,0,-7,9,2,1,9,-5,-1,-10,-5,-4,4,-6,6,-6,-1,12,7,5,20,5,12,6,21,-18,32,-15,-1,7,2,3,-7,20,-5,9,-2,-5,4,6,-5,-4,-21,-11,3,18,9,16,5,4,11,13,11,5,-2,-9,-5,4,-5,0,6,-14,14,-4,17,0,16,2,8,1,-15,-8,-3,-14,8,10,-3,8,-14,-6,-5,-4,11,-6,14,0,6,10,-5,12,5,8,9,15,1,-3,8,9,6,2,4,-1,4,8,9,13,13,-5,8,-15,-1,-5,7,-6,3,-9,-9,-7,-13,-16,-5,-6,2,5,4,-3,-3,-1,-6,-1,5,12,9,1,5,-11,-15,-9,-15,3,10,9,12,17,8,7,8,0,2,5,5,7,4,5,-3,-3,2,1,-1,-7,-13,11,-3,0,7,-5,0,4,16,-7,8,2,-2,6,0,-4,-1,-8,-2,7,-2,1,-4,-17,-5,-9,-5,3,7,-4,16,-7,1,-7,-5,15,7,11,-2,-3,4,-13,6,7,-7,8,14,-10,21,-9,-3,14,-11,15,-6,7,-1,-1,-7,-19,3,3,20,15,17,11,-2,23,11,20,-2,5,-3,-4,-16,20,-3,17,17,-7,-3,-3,-8,3,6,-11,19,-6,-2,-6,-15,-7,-11,-2,-8,-14,7,-15,10,8,-8,1,-2,5,6,16,-6,14,-25,12,-15,6,-23,-5,-12,-5,5,-10,-6,-5,0,14,8,4,-14,-8,3,-8,16,1,-14,-10,-10,-7,16,-16,14,7,2,-6,7,9,-11,6,2,-3,11,9,-3,2,-9,-9,-3,-4,-15,0,-4,-6,17,-6,-8,3,-16,-9,-4,-5,-4,10,3,-8,2,-13,3,13,12,-8,15,-13,2,9,3,6,10,4,-7,13,-8,-8,22,-12,8,-6,-18,7,-10,2,-12,-6,4,4,-4,-6,-7,-11,-2,6,3,7,-5,-2,-4,9,2,8,-3,-7,-9,10,0,13,2,-8,-18,0,-14,20,1,4,-3,-13,-10,7,-9,-4,-3,-6,20,8,4,11,-8,6,2,3,4,1,-11,-8,-4,0,-6,10,-7,2,4,-12,0,-7,-3,7,1,1,-10,3,0,0,10,-9,4,-14,-9,0,0,-5,12,11,7,-2,-6,-11,-5,0,-3,5,8,-7,13,-19,0,-11,-6,1,7,12,-2,0,-6,-3,1,-3,3,0,-15,9,8,-12,3,10,-10,14,9,8,9,2,1,-16,4,-7,2,8,4,2,11,3,0,7,12,5,3,7,-7,-2,-5,6,5,17,4,3,0,-16,2,1,-4,5,-13,-12,-2,11,1,7,-6,-7,-11,18,-19,10,-12,-10,5,-6,4,3,1,-2,1,1,-6,-8,-8,-5,-7,6,6,-10,-2,-3,3,10,15,-2,17,-3,13,8,-10,-1,-13,16,0,14,-2,-13,6,-2,-12,-6,-8,-9,16,-18,2,-23,6,4,14,15,11,-6,1,-14,-1,-6,-13,-5,-1,11,-7,-3,-8,4,-2,9,-12,-10,-10,-18,-5,1,-6,-1,-3,-3,-9,-5,8,8,17,6,8,-6,1,11,0,14,-10,1,-12,-1,4,-5,4,2,-3,9,-2,1,-4,1,0,5,7,1,3,-8,-4,-8,0,5,12,8,5,0,-5,-7,3,0,7,1,-4,1,-2,-15,0,-2,5,6,-10,-15,-3,-5,21,9,-2,3,-5,12,3,13,-8,0,-11,-2,3,6,-11,3,-2,1,-2,-4,1,-15,13,-8,-4,5,-14,-2,-2,-12,2,-3,8,11,9,17,-1,-7,-3,-1,-9,36,11,10,5,1,-20,-3,-8,-4,6,0,0,12,2,8,5,1,-5,-6,1,2,21,3,10,-9,1,0,-7,14,-13,13,3,7,6,8,-9,-8,-10,-14,3,-10,11,8,8,3,9,0,-2,2,-5,3,-8,-1,-8,-1,6,3,11,-4,-9,-1,-18,-6,1,-6,2,0,-9,-6,-11,-2,-4,-4,-2,-14,9,-11,0,-12,-4,-3,-2,14,6,2,-4,5,-3,-1,5,1,-1,-1,-13,2,-10,-9,9,-9,3,-1,-8,-4,1,1,16,-1,13,-6,0,-2,-1,-7,8,0,15,12,2,-15,-19,-18,-17,1,2,-4,-8,-7,-4,-1,10,-2,-7,7,-26,2,11,1,6,7,-9,1,-4,2,5,1,4,-2,-5,4,2,9,27,-4,24,1,5,19,-9,-1,1,-6,-10,8,-7,5,12,-7,-5,5,-6,21,7,10,0,-4,-9,-6,6,5,4,3,6,-11,1,-6,4,-2,9,8,7,8,13,-5,6,-1,-2,10,2,-1,8,-6,-7,4,-14,33,8,23,15,0,11,-11,18,1,-2,-3,-6,-2,9,6,10,-1,-1,2,0,-2,17,-14,20,-10,-3,6,2,7,0,4,2,-15,7,-12,9,2,5,-7,10,3,7,14,5,2,9,-2,-5,4,4,-5,16,2,6,6,-6,3,-2,-2,6,-14,-2,-24,7,-24,-7,-2,-9,3,9,0,7,-3,-5,6,4,15,10,4,-19,-1,-20,-3,-13,-3,-12,5,-9,7,7,5,11,-6,8,-13,4,-16,-8,1,3,2,9,4,-6,16,-16,6,2,7,2,16,-5,9,-2,1,-4,15,5,12,4,4,-5,10,-1,9,1,-8,13,4,16,5,-2,1,-5,-6,-5,-12,-3,0,3,1,-9,2,-7,7,7,8,10,4,-2,2,8,8,0,3,-2,1,13,-3,7,15,-14,15,-10,-5,-4,10,-9,5,-6,-1,-1,4,5,-6,7,-9,-1,7,-8,13,3,-10,10,5,10,16,4,5,7,7,9,4,5,12,2,3,0,-16,2,4,-13,0,-8,-3,5,0,3,-16,-13,1,2,11,11,-5,3,3,6,10,5,-5,13,-7,5,-7,8,-12,9,7,-3,19,8,-2,11,3,2,8,-6,4,11,8,19,8,7,14,-1,6,8,-11,11,7,-5,27,-13,3,4,-14,16,-3,-4,-5,-2,-23,22,-5,14,6,-7,1,3,-4,18,-3,4,8,-3,4,-3,-3,-1,-1,2,-11,9,0,8,16,9,0,-5,-5,-13,-9,-6,-2,9,-5,3,-10,-22,-2,-4,9,6,-9,-9,-5,-5,-2,1,-4,-7,0,0,-7,2,-5,4,15,12,16,5,-1,1,7,7,-3,18,-16,6,5,3,-4,6,-16,-11,-14,-7,4,9,5,-12,6,-9,3,18,4,7,9,-14,-3,-17,-5,-9,5,-10,2,-6,-12,-16,12,-4,12,12,-2,5,-8,-4,8,4,9,8,2,6,-5,19,10,-1,6,-2,-1,5,9,-3,2,5,10,7,12,-5,-6,-3,-6,-11,-3,-4,0,10,-4,4,-4,-9,1,-6,-5,13,-11,19,-14,-3,6,-8,16,7,16,7,10,-11,-10,-19,-20,-7,0,-9,1,-13,-12,-8,-16,2,-5,-3,3,8,12,2,15,3,-1,17,-11,-4,-7,-5,0,8,4,-3,0,5,1,1,-8,-12,-6,-1,-3,-6,-14,-3,-10,16,-5,2,-11,6,1,14,0,1,-4,5,-3,4,0,-8,-3,-1,-3,2,-2,-13,2,-2,-6,-1,-9,4,7,5,4,10,-11,10,0,4,4,-13,3,-3,0,10,8,1,11,-5,2,-7,-4,5,-1,10,-7,-4,-7,0,0,8,-9,16,-5,8,-1,0,-2,-5,5,-9,-5,-5,-10,15,1,0,10,-4,-8,-8,-3,-6,16,16,2,23,-6,9,6,7,-6,10,-12,-1,0,-19,7,-11,-2,7,3,-9,7,-8,-4,7,0,-8,4,-13,-1,6,-5,16,5,6,-2,4,-5,-12,-1,4,-9,5,-7,1,-2,10,13,-26,2,-15,4,-7,-1,-14,-19,18,-1,20,1,-5,5,-1,-7,5,-5,-12,2,-13,-8,-8,-3,-17,5,5,-7,11,-9,-12,-2,-2,-12,0,-1,-13,8,-2,-6,-2,-1,8,2,-4,-1,-4,-8,7,5,3,16,-3,0,-7,-1,-6,21,0,4,2,-13,-1,-8,-5,-5,-1,2,-3,3,3,18,-3,11,-12,2,9,2,20,11,-6,-18,7,-12,10,-2,-1,-14,1,-16,-7,-7,-4,10,15,18,1,-4,-3,2,0,6,1,-4,-13,-2,-6,-2,8,7,10,13,3,-12,6,-13,2,5,-17,-2,-5,5,3,5,-5,3,5,0,16,-1,10,-18,7,-22,-10,-5,-9,14,12,20,7,-2,-11,-4,1,3,11,-2,-5,-10,-9,5,1,13,-5,-5,-5,-6,5,10,4,18,-8,19,5,17,5,-22,10,-2,5,20,-6,5,-1,-1,1,8,-2,9,2,3,-2,6,0,-5,-3,-16,-5,2,11,16,6,-14,-5,-1,12,12,7,-5,-7,4,-10,17,-19,1,-7,5,10,0,-3,-4,5,-2,-7,-7,-13,-6,12,3,0,-2,-24,7,8,11,9,-1,-1,-10,12,0,-5,7,-4,-3,-2,-18,-7,6,-2,0,2,-6,10,-4,18,-10,2,13,-6,28,5,-1,5,-3,-9,13,-3,1,2,1,-7,0,7,-10,8,-7,3,-5,-7,-4,-2,2,6,-2,-8,5,-1,7,6,13,2,-6,-2,-11,-10,10,3,1,-1,1,-11,8,-2,-5,0,-13,-1,2,0,-3,-3,-2,-10,8,-5,4,6,7,10,3,-11,-1,-8,9,4,5,1,-9,-2,-5,2,6,-9,-1,8,4,15,5,8,15,11,8,3,9,-5,1,-3,-5,-2,5,8,12,8,7,5,0,6,0,5,2,-1,6,1,3,-10,-4,-12,7,4,6,4,6,-5,-2,2,5,-11,25,1,16,4,-12,-6,6,-11,17,2,-6,9,-7,8,9,1,-4,6,-14,-3,6,-14,14,13,-7,8,-1,0,-6,7,-15,6,-10,18,4,14,-6,-13,-24,-9,-4,-2,12,5,-9,7,-7,-13,8,-16,19,3,9,8,8,-5,21,3,1,-11,-16,-10,-9,-10,1,-14,2,-3,-6,7,-16,-5,-5,-5,-11,-1,-5,-6,12,2,5,8,-2,9,13,-1,8,-9,-5,7,-8,6,-1,6,3,7,2,12,-16,4,-17,-4,2,-7,10,9,-7,0,-8,-10,-5,4,-9,14,6,12,15,9,-3,-9,-15,-5,8,11,21,-1,4,-13,6,2,-3,-3,-5,-25,8,-9,6,-4,-2,-7,-3,-2,1,-4,-13,-12,26,-10,4,3,-5,6,22,-13,0,7,-5,4,4,8,-1,14,-8,-6,-2,-11,-6,14,7,-1,10,-8,-8,3,-24,-21,-9,-11,-11,9,-27,-6,3,14,5,14,-10,-11,2,-5,-7,3,3,-3,6,13,-7,-4,11,0,6,-5,3,-15,14,2,-2,-8,-21,-13,-4,1,-1,2,-11,-3,-7,-4,-2,-10,6,-13,7,-5,6,-3,7,2,7,-4,-3,1,3,12,-2,-1,-12,-6,7,12,3,17,-12,-5,-10,2,4,3,-4,2,-14,15,-8,1,8,-7,8,9,13,-4,7,-2,0,-2,2,10,-1,18,4,15,3,9,-12,1,-5,-21,10,-30,-1,10,2,0,1,-10,1,-7,5,-7,-4,-8,-5,4,3,-3,0,-1,8,-7,9,-8,-5,-8,-4,-13,-3,-4,-11,2,3,-2,-4,-6,-9,0,14,17,-3,-1,-13,-3,-2,6,-6,-2,3,-3,-3,1,1,11,10,8,3,8,-21,4,-7,-8,-5,0,1,5,-2,1,-3,-4,-2,-8,3,-1,1,8,4,-5,-12,-10,1,-9,9,-7,6,-4,5,-8,5,-21,1,1,11,10,19,-9,5,-2,-9,11,0,-4,10,-8,2,0,-1,-7,-3,-9,1,-5,-5,13,-14,6,-1,4,2,-2,-3,1,-2,-7,15,-4,7,11,12,16,17,-9,-12,-11,2,3,6,13,4,-4,3,-6,11,5,1,5,2,-2,1,1,-1,-1,8,-8,10,-1,11,-1,2,-3,1,7,4,-10,2,-11,11,6,7,5,-11,5,-5,-9,13,-1,7,8,-7,-8,-6,-11,6,7,10,11,6,-6,-2,6,-5,8,11,-2,11,11,7,19,-4,0,-7,-7,3,9,11,-6,0,-13,-14,1,-8,-11,-2,-12,2,-2,5,2,1,5,-7,6,-4,1,2,3,-7,6,2,3,3,3,-3,6,10,4,5,-10,5,-9,8,12,0,13,-5,-2,3,-5,2,-4,-8,-10,-2,5,7,7,-11,-3,-15,7,19,8,7,1,-2,-7,-5,4,5,9,-5,10,-1,2,16,1,20,6,-9,8,-9,-1,12,-4,-8,-2,-8,-8,18,-1,22,10,-2,11,3,-8,6,-7,-3,5,5,9,10,7,-11,3,-6,-1,-14,8,-5,1,0,4,-16,12,-19,9,-6,5,1,1,-11,4,13,6,13,11,0,4,6,0,4,0,-7,12,6,14,15,8,9,9,3,0,-15,-1,-13,-4,-1,-7,8,0,6,8,2,5,6,1,13,1,2,-2,-2,-3,-9,4,-18,8,-5,17,-10,11,-15,0,-1,-4,8,15,4,4,7,-2,-1,9,1,1,-7,-10,-16,2,8,20,10,3,-14,-9,-12,0,14,-6,9,-2,1,22,2,8,-8,5,-5,2,9,-2,11,8,-1,9,-3,-10,13,-3,21,6,0,10,-12,16,1,-9,4,-6,-3,13,9,6,6,16,0,22,4,4,3,-7,-22,-8,-14,-20,10,0,5,5,-15,0,-10,3,11,-1,11,4,8,13,-2,-3,5,8,7,7,-2,-1,2,11,2,-7,4,-17,11,1,4,7,4,5,-12,10,-11,5,3,3,2,-2,3,2,7,3,8,-10,11,5,13,9,6,-9,-10,0,-8,10,11,1,12,-9,-17,-12,-15,0,0,3,-10,-6,6,-10,3,-4,5,5,6,7,-8,-3,7,-10,11,7,-15,11,5,4,20,8,-1,7,-3,4,-4,9,-14,0,-5,-12,0,-6,4,-1,5,-11,5,-2,19,9,17,13,0,-12,-1,-1,4,8,-1,4,7,16,6,2,-6,-17,-9,6,-7,19,0,-11,-8,1,5,15,-2,-12,-24,-10,1,-6,13,-1,-7,7,-4,2,16,0,-3,0,7,-12,12,-5,-4,2,-8,7,-1,-2,-9,1,10,1,12,-19,3,-3,15,7,2,-6,-2,-8,0,0,-3,-10,-9,-5,-1,10,-10,5,-4,13,-5,-6,-3,-8,-8,-2,2,-14,15,-24,18,-14,-4,-8,-4,-6,6,1,11,5,-3,-9,-9,-4,6,7,15,-1,7,-4,5,-2,9,-3,1,1,-4,2,8,-4,2,-1,-4,8,-3,1,3,13,-8,5,-14,-12,14,3,10,18,-1,6,1,-6,8,-25,6,-14,-9,-7,-16,-8,-8,-13,-4,2,5,6,5,-4,5,-11,4,2,-9,-12,7,-19,8,-9,8,-6,-1,6,-4,12,1,-7,0,2,-12,5,-27,-17,-22,-12,-6,-3,3,-4,5,7,-6,4,-4,-4,2,3,-3,-1,-6,0,-11,-4,-7,2,6,11,14,7,13,5,-10,-9,-8,2,-7,5,11,5,18,-4,-7,1,5,15,16,-6,5,-2,6,18,6,5,4,-3,-4,-10,-4,-4,3,-8,-9,-3,-5,9,9,10,1,6,-9,-6,-10,-1,-3,-10,-7,-7,1,1,5,11,-13,-2,-9,-4,5,8,-12,-6,-17,-10,0,1,-12,7,1,4,14,3,-5,4,-14,7,-5,-4,8,1,18,5,12,-9,-6,-1,6,22,10,10,1};
	int fftsize=2048;
	tSComplex testsig2[2048];
	tSComplex output[2048];
	double spectrum[2048];
	int i;
	SimpleFft* simpleFft=new SimpleFft(fftsize);
	SimpleShifter* simpleShift=new SimpleShifter(2048000,16384);
	
	simpleFft->process((tSComplex*)testsig);
	simpleFft->getResult(output);


	simpleFft->getSpectrum(spectrum);
	printf("preshift=[");
	for (i=0;i<fftsize;i++)
	{
		printf("%.f ",spectrum[i]);
	}
	printf("];\n");
	simpleShift->process((tSComplex*)testsig,testsig2,2048*2);
	simpleFft->process(testsig2);
	simpleFft->getSpectrum(spectrum);
	printf("postshift=[");
	for (i=0;i<fftsize;i++)
	{
		printf("%.f ",spectrum[i]);
	}
	printf("];\n");	
	printf("hold off;\n");
	printf("plot(1:length(preshift),preshift,'r');\n");
	printf("hold on;\n");
	printf("plot(1:length(postshift),postshift,'g');\n");
}
