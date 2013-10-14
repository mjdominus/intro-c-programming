

/* Program to solve quadratic equations ax^2 + bx + c = 0.
   Known bugs:  Fails when a=0.
 */

#include <stdio.h>
#include <math.h>

int main(void) {
   double a, b, c;
   double x1, x2;
   double discriminant;

   /* get inputs a, b, and c from user. */
   printf("Please input a, b, and c, one per line.\n");
   scanf("%lf", &a);
   scanf("%lf", &b);
   scanf("%lf", &c);

   discriminant = b*b - 4*a*c;

   if ( discriminant < 0 ) {
     printf("The roots are imaginary.  I can't find them.\n");
     return 1;
   } else {
     x1 = ( -b + sqrt(discriminant) )  / (2*a);
     x2 = ( -b - sqrt(discriminant) )  / (2*a);

     printf("The roots are %f and %f.\n", x1, x2);

     return 0;
   }

}
