/*
Write a function that receives appropriate information about the
dimensions of a cylinder from its caller and computes the volume of the
cylinder.  

*/

#define PI 3.141592654

double cylinder_volume(double radius, double height)
{
  return PI * radius * radius * height;
}
