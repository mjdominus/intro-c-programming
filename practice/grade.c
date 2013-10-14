/* 
  Write a program that reads up to 50 grades between 0 and 100 from the
  input; -1 signals the end of the input.  The program should write out
  the letter grades that correspond to the inputs.  The program should
  grade on a curve as follows: Divide the range betwen the lowest and
  highest grade into five parts.  Grades in the top part get A's; grades
  in the second part get B's, and soforth. 
  */

#include <stdio.h>

#define MAX_NUM_GRADES 50

int main(void)
{
  int highest_grade = -1, lowest_grade = 101;
  int grades[MAX_NUM_GRADES];
  int cur_grade;
  int num_grades_so_far = 0, i;
  char grade_names[] = "FDCBAA";
  int spread;			/* Point spread between highest and 
				   lowest grades */
  double interval;		/* # points between bottom and top of 
				   each letter range */

  /* Read in grades */
  while (num_grades_so_far < MAX_NUM_GRADES) {
    scanf("%d", &cur_grade);
    
    if (cur_grade == -1) 
      break;
    
    if (cur_grade < lowest_grade)
      lowest_grade = cur_grade;
    
    if (cur_grade > highest_grade)
      highest_grade = cur_grade;
    
    grades[num_grades_so_far++] = cur_grade;
  }

  spread = highest_grade - lowest_grade;
  interval = spread / 5.0;	
  if (interval < 1) {
    printf("Spread is too small to grade on a curve.\n");
    return 1;
  }

  /* If you get `lowest_grade', you get an F. 
   * it takes `interval' points to bump you up one letter grade.
   * (4*interval) are enough to bump you up to an A.
   * Thus the difference between your grade and the lowest grade,
   * measured in unit of `interval', is how many grades above an F
   * you get.  For examlpe, if your score is less then `interval' points
   * above the lowest grade, you get an F. 
   */

  /* Print out report. */
  for (i=0; i< num_grades_so_far; i++) {
    int the_grade = grades[i];
    int intervals_above_lowest = (the_grade-lowest_grade)/interval;

    printf("%d %c\n", the_grade,
	   grade_names[intervals_above_lowest]);
  }


  return 0;
}
